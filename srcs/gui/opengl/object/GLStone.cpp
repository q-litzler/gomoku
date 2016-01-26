/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStone.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:05:37 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:18:19 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLStone.hpp>

/*******************************************
	Constructors - Destructor
************************************s*******/

GLStone::GLStone(Model3D & model3D, Camera & camera, GLSStone const * shader, char const * objFile):
_model3D(model3D), _camera(camera), _shader(shader), _instances(0)
{
	GLParser	parser(objFile);

	_obj = parser.getObj();
	_mtl = parser.getMtl();
	indexing();
	generate();
}

GLStone::~GLStone(void)
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_nbo);
	glDeleteBuffers(1, &_cbo);
	glDeleteBuffers(1, &_ibo);
	delete &_model3D;
	delete &_camera;
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLStone::generate(void)
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);
	GLObject::generateBO(_vbo, _obj.vbo, _obj.vbo.size(), GL_STATIC_DRAW);
	GLObject::generateBO(_cbo, _obj.cbo, MAX_STONES * RGBA, GL_STREAM_DRAW);
	GLObject::generateBO(_nbo, _obj.nbo, _obj.nbo.size(), GL_STATIC_DRAW);
	GLObject::generateBO(_ibo, _obj.ibo, MAX_STONES * XYZ, GL_STREAM_DRAW);

	GLObject::setBO(_vbo, _shader->vertexPosition, XYZ);
	GLObject::setBO(_nbo, _shader->vertexNormal, XYZ);

	glVertexAttribDivisor(_shader->vertexPosition, 0);
	glVertexAttribDivisor(_shader->vertexColor, 1);
	glVertexAttribDivisor(_shader->vertexInstance, 1);
}

void			GLStone::indexing(void)
{

	GLObject::indexingBO(_obj.vbo, _obj.ebo[VBO], XYZ);
	GLObject::indexingBO(_obj.nbo, _obj.ebo[NBO], XYZ);
}

void			GLStone::add(int const & x, int const & z, GLfloat const & alpha)
{
	if (x < 0 || x > 18 || z < 0 || z > 18)
	{
		std::cerr << "add exception" << std::endl;
		throw std::exception();
	}
	_obj.ibo.push_back((x - 9) * UNIT);
	_obj.ibo.push_back(0.3f);
	_obj.ibo.push_back((z - 9) * UNIT);
	std::vector<GLfloat>::iterator		it;

	_obj.cbo.push_back(1.0f);
	_obj.cbo.push_back(1.0f);
	_obj.cbo.push_back(1.0f);
	_obj.cbo.push_back(alpha);
	this->_instances += 1;
}

void			GLStone::uniforms(void) const
{
	glUniform3fv(_shader->matrixCamera, 1, glm::value_ptr(_camera.getPosition()));
	glUniformMatrix4fv(_shader->matrixView, 1, GL_FALSE, glm::value_ptr(_camera.getLookAt()));
	glUniformMatrix4fv(_shader->matrixModel, 1, GL_FALSE, glm::value_ptr(_model3D.getMatrix()));
	glUniformMatrix4fv(_shader->matrixProjection, 1, GL_FALSE, glm::value_ptr(_model3D.getProjection()));
	glUniform3fv(_shader->lightPosition, 1, glm::value_ptr(_model3D.getLightPosition()));
	glUniform3fv(_shader->lightAmbient, 1, glm::value_ptr(_mtl.ambient));
	glUniform3fv(_shader->lightDiffuse, 1, glm::value_ptr(_mtl.diffuse));
	glUniform3fv(_shader->lightSpecular, 1, glm::value_ptr(_mtl.specular));
	glUniform1f(_shader->lightShininess, 25.0f);
	glUniform1f(_shader->lightCoefficient, 1.0f);
	glUniform1f(_shader->lightAttenuation, 0.0f);
}

void			GLStone::draw(void) const
{
	_shader->use();
	uniforms();
	glBindVertexArray(_vao);

	GLObject::setBO(_cbo, _shader->vertexColor, RGBA);
	glBufferSubData(GL_ARRAY_BUFFER, 0, _obj.cbo.size() * sizeof(GLfloat), &_obj.cbo[0]);

	GLObject::setBO(_ibo, _shader->vertexInstance, XYZ);
	glBufferSubData(GL_ARRAY_BUFFER, 0, _obj.ibo.size() * sizeof(GLfloat), &_obj.ibo[0]);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArraysInstanced(GL_TRIANGLES, 0, _obj.vbo.size(), _instances);
	glDisable(GL_BLEND);
}

void			GLStone::rotate(GLfloat const & angle)
{
	_model3D.rotate(angle);
}

void			GLStone::move(glm::vec3 const & position)
{
	_camera.move(position);
}

void			GLStone::scale(GLfloat const & delta)
{
	_model3D.scale(delta);
}

void			GLStone::reset(void)
{
	_model3D.reset();
	_camera.reset();
}

void			GLStone::clear(void)
{
	this->_instances = 0;
	_obj.ibo.clear();
	_obj.cbo.clear();
}
