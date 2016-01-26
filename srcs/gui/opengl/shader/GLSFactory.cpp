/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSFactory.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLSFactory.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLSFactory::~GLSFactory(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Non-Member functions
*******************************************/

GLShader *	GLSFactory::newInstance(e_gls_factory const & type)
{
	GLSBuilder  shader = GLSBuilder(_gls[type].vertex, _gls[type].fragment);

	GLShader * instance = (*_gls[type].f)(shader.getId());
	return instance;
}

GLShader *	GLSFactory::newGLSBoard(GLuint const & id)
{
	return new GLSBoard(id);
}

GLShader *	GLSFactory::newGLSStone(GLuint const & id)
{
	return new GLSStone(id);
}

GLShader *	GLSFactory::newGLSFont(GLuint const & id)
{
	return new GLSFont(id);
}


s_gls		GLSFactory::_gls[] = {
	{	"shaders/board_vertex.glsl", "shaders/board_fragment.glsl", &GLSFactory::newGLSBoard	},
	{	"shaders/stone_vertex.glsl", "shaders/stone_fragment.glsl", &GLSFactory::newGLSStone	},
	{	"shaders/font_vertex.glsl", "shaders/font_fragment.glsl", &GLSFactory::newGLSFont		}
};
