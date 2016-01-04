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

GLStone::GLStone(Model3D & model3D, Camera & camera, GLShader const * shader, char const * objFile):
	GLObject(
		model3D,
		camera,
		shader,
		objFile
	),
	_instances(0)
{
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
	generateBO(_vbo, _obj.vbo, _obj.vbo.size(), GL_STATIC_DRAW);
	generateBO(_cbo, _obj.cbo, MAX_STONES * RGBA, GL_DYNAMIC_DRAW);
	generateBO(_nbo, _obj.nbo, _obj.nbo.size(), GL_STATIC_DRAW);
	generateBO(_ibo, _obj.ibo, MAX_STONES * XYZ, GL_DYNAMIC_DRAW);
}

void			GLStone::indexing(void)
{

	indexingBO(_obj.vbo, _obj.ebo[VBO], XYZ);
	indexingBO(_obj.nbo, _obj.ebo[NBO], XYZ);
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

void			GLStone::draw(void)
{
	_shader->use();
	_shader->uniforms(_model3D, _camera, _mtl);
	glBindVertexArray(_vao);

	setBO(_vbo, _shader->getPosition(), XYZ);
	glVertexAttribDivisor(_shader->getPosition(), 0);

	setBO(_cbo, _shader->getColor(), RGBA);
	glBufferSubData(GL_ARRAY_BUFFER, 0, _obj.cbo.size() * sizeof(GLfloat), &_obj.cbo[0]);

	setBO(_nbo, _shader->getNormal(), XYZ);

	setBO(_ibo, _shader->getInstance(), XYZ);
	glBufferSubData(GL_ARRAY_BUFFER, 0, _obj.ibo.size() * sizeof(GLfloat), &_obj.ibo[0]);

	glVertexAttribDivisor(_shader->getColor(), 1);
	glVertexAttribDivisor(_shader->getInstance(), 1);
	glDrawArraysInstanced(GL_TRIANGLES, 0, _obj.vbo.size(), _instances);
}

void			GLStone::clear(void)
{
	this->_instances = 0;
	_obj.ibo.clear();
	_obj.cbo.clear();
}
