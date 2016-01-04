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

GLBoard::GLBoard(Model3D & model3D, Camera & camera, GLShader const * shader):
	GLObject(
		model3D,
		camera,
		shader,
		"assets/obj/goban.obj"
	)
{
	indexing();
	generate();
}

GLBoard::~GLBoard(void)
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	glDeleteBuffers(1, &_nbo);
	glDeleteTextures(1, &_tbo);
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLBoard::indexing()
{
	indexingBO(_obj.vbo, _obj.ebo[VBO], XYZ);
	indexingBO(_obj.nbo, _obj.ebo[NBO], XYZ);
	indexingBO(_obj.pbo, _obj.ebo[PBO], UV);
}

void			GLBoard::generate()
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	generateBO(_vbo, _obj.vbo, _obj.vbo.size(), GL_STATIC_DRAW);
	generateBO(_nbo, _obj.nbo, _obj.nbo.size(), GL_STATIC_DRAW);
	generateBO(_pbo, _obj.pbo, _obj.pbo.size(), GL_STATIC_DRAW);

	glGenTextures(1, &_tbo);
	glBindTexture(GL_TEXTURE_2D, _tbo);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	ParserTGA		tga("assets/textures/wood.tga");
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, tga.getWidth(), tga.getHeight(), 0, GL_BGR, GL_UNSIGNED_BYTE, tga.getImage());
	tga.freeImage();
}

void			GLBoard::draw(void)
{
	_shader->use();
	_shader->uniforms(_model3D, _camera, _mtl);
	glBindVertexArray(_vao);
	setBO(_vbo, _shader->getPosition(), XYZ);
	setBO(_nbo, _shader->getNormal(), XYZ);
	setBO(_pbo, _shader->getTexture(), UV);

	glDrawArrays(GL_TRIANGLES, 0, _obj.vbo.size());
}
