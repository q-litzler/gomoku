/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSBoard.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:34:40 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:19:50 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLSBoard.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLSBoard::GLSBoard(GLuint const & id): GLShader(id),
	vertexPosition(glGetAttribLocation(id, "v_position")),
	vertexNormal(glGetAttribLocation(id, "v_normal")),
	vertexTexture(glGetAttribLocation(id, "v_texture")),
	vertexMaterial(glGetUniformLocation(id, "v_material")),
	matrixModel(glGetUniformLocation(id, "model")),
	matrixView(glGetUniformLocation(id, "view")),
	matrixProjection(glGetUniformLocation(id, "projection")),
	matrixCamera(glGetUniformLocation(id, "camera")),
	lightPosition(glGetUniformLocation(id, "light.position")),
	lightAmbient(glGetUniformLocation(id, "light.ambient")),
	lightDiffuse(glGetUniformLocation(id, "light.diffuse")),
	lightSpecular(glGetUniformLocation(id, "light.specular")),
	lightCoefficient(glGetUniformLocation(id, "light.coefficient")),
	lightShininess(glGetUniformLocation(id, "light.shininess")),
	lightAttenuation(glGetUniformLocation(id, "light.attenuation"))
{
	
}

GLSBoard::~GLSBoard(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/
