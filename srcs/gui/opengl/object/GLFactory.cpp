/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLFactory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLFactory.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLFactory::~GLFactory(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Non-Member functions
*******************************************/

IGLObject *	GLFactory::newInstance(e_gl_factory const & type)
{
	return (*_gl[type].f)();
}

IGLObject *	GLFactory::newGLBoard(void)
{
	return new GLBoard(
		*Model3D::newInstance(),
		*Camera::newInstance(),
		static_cast<GLSBoard *>(GLSFactory::newInstance(GLS_BOARD))
	);
}

IGLObject *	GLFactory::newGLStoneWhite(void)
{
	return new GLStone(
		*Model3D::newInstance(),
		*Camera::newInstance(),
		static_cast<GLSStone *>(GLSFactory::newInstance(GLS_STONE)),
		"assets/obj/stone_white.obj"
	);
}

IGLObject *	GLFactory::newGLStoneBlack(void)
{
	return new GLStone(
		*Model3D::newInstance(),
		*Camera::newInstance(),
		static_cast<GLSStone *>(GLSFactory::newInstance(GLS_STONE)),
		"assets/obj/stone_black.obj"
	);
}

IGLObject *	GLFactory::newGLFont10(void)
{
	return new GLFont(*Model2D::newInstance(), static_cast<GLSFont *>(GLSFactory::newInstance(GLS_FONT)), 10);
}

IGLObject *	GLFactory::newGLFont12(void)
{
	return new GLFont(*Model2D::newInstance(), static_cast<GLSFont *>(GLSFactory::newInstance(GLS_FONT)), 12);
}


s_gl		GLFactory::_gl[] = {
	{	&GLFactory::newGLBoard		},
	{	&GLFactory::newGLStoneWhite	},
	{	&GLFactory::newGLStoneBlack	},
	{	&GLFactory::newGLFont10		},
	{	&GLFactory::newGLFont12		}
};
