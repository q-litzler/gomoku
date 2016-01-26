/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLBoard.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 20:33:31 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 19:48:04 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLBoard.hpp>
#include <gui/ParserTGA.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLBoard::GLBoard(Model3D & model3D, Camera & camera, GLSBoard const * shader):
_model3D(model3D), _camera(camera), _shader(shader)
{
	GLParser	parser("assets/obj/goban.obj");

	_obj = parser.getObj();
	_mtl = parser.getMtl();
	indexing();
	generate();
}

GLBoard::~GLBoard(void)
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_nbo);
	glDeleteBuffers(1, &_pbo);
	glDeleteTextures(1, &_tbo);
	delete &_model3D;
	delete &_camera;
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLBoard::indexing(void)
{
	GLObject::indexingBO(_obj.vbo, _obj.ebo[VBO], XYZ);
	GLObject::indexingBO(_obj.nbo, _obj.ebo[NBO], XYZ);
	GLObject::indexingBO(_obj.pbo, _obj.ebo[PBO], UV);
}

void			GLBoard::generate(void)
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	GLObject::generateBO(_vbo, _obj.vbo, _obj.vbo.size(), GL_STATIC_DRAW);
	GLObject::generateBO(_nbo, _obj.nbo, _obj.nbo.size(), GL_STATIC_DRAW);
	GLObject::generateBO(_pbo, _obj.pbo, _obj.pbo.size(), GL_STATIC_DRAW);
	GLObject::setBO(_vbo, _shader->vertexPosition, XYZ);
	GLObject::setBO(_nbo, _shader->vertexNormal, XYZ);
	GLObject::setBO(_pbo, _shader->vertexTexture, UV);

	glGenTextures(1, &_tbo);
	glBindTexture(GL_TEXTURE_2D, _tbo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	ParserTGA		tga("assets/textures/wood.tga");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tga.getWidth(), tga.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, tga.getImage());
	tga.freeImage();
}

void			GLBoard::uniforms(void) const
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
	glUniform1i(_shader->vertexMaterial, 0);
}

void			GLBoard::rotate(GLfloat const & angle)
{
	_model3D.rotate(angle);
}

void			GLBoard::move(glm::vec3 const & position)
{
	_camera.move(position);
}

void			GLBoard::scale(GLfloat const & delta)
{
	_model3D.scale(delta);
}

void			GLBoard::reset(void)
{
	_model3D.reset();
	_camera.reset();
}

void			GLBoard::draw(void) const
{
	_shader->use();
	uniforms();
	glBindVertexArray(_vao);
	glDrawArrays(GL_TRIANGLES, 0, _obj.vbo.size());
}
