/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStoneWhite.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:30:48 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 15:44:05 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLStoneWhite.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLStoneWhite::GLStoneWhite(Model3D & model3D, Camera & camera, GLShader const * shader):
GLStone(model3D, camera, shader, "assets/obj/stone_white.obj")
{
	
}

GLStoneWhite::~GLStoneWhite(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/


