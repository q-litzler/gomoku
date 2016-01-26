/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSFont.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:35:00 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:49:49 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLSFont.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLSFont::GLSFont(GLuint const & id): GLShader(id),
	vertexPosition(glGetAttribLocation(id, "v_position")),
	vertexTexture(glGetAttribLocation(id, "v_texture")),
	vertexMaterial(glGetUniformLocation(id, "v_material")),
	matrixProjection(glGetUniformLocation(id, "projection")),
	fragmentTexture(glGetAttribLocation(id, "f_texture")),
	fragmentColor(glGetUniformLocation(id, "f_color"))
{

	
}

GLSFont::~GLSFont(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/
