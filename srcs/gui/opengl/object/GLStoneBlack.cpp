/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStoneBlack.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:29:55 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 15:31:25 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLStoneBlack.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLStoneBlack::GLStoneBlack(Model3D & model3D, Camera & camera, GLShader const * shader):
GLStone(model3D, camera, shader, "assets/obj/stone_black.obj")
{
	
}

GLStoneBlack::~GLStoneBlack(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/


