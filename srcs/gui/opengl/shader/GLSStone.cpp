/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSStone.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:50:51 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:19:56 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLSStone.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLSStone::GLSStone(GLuint const & id): GLShader(id),
	vertexPosition(glGetAttribLocation(id, "v_position")),
	vertexNormal(glGetAttribLocation(id, "v_normal")),
	vertexColor(glGetAttribLocation(id, "v_color")),
	vertexInstance(glGetAttribLocation(id, "v_instance")),
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

GLSStone::~GLSStone(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

// void			GLShaderStone::uniforms(Model const & model, Camera const & camera, s_mtl const & mtl) const
// {
// 	glUniform3fv(_attr.matrix.camera, 1, glm::value_ptr(camera.getPosition()));
// 	glUniformMatrix4fv(_attr.matrix.view, 1, GL_FALSE, glm::value_ptr(camera.getLookAt()));
// 	glUniformMatrix4fv(_attr.matrix.model, 1, GL_FALSE, glm::value_ptr(model.getMatrix()));
// 	glUniformMatrix4fv(_attr.matrix.projection, 1, GL_FALSE, glm::value_ptr(model.getProjection()));
// 	glUniform3fv(_attr.light.position, 1, glm::value_ptr(model.getLightPosition()));
// 	glUniform3fv(_attr.light.ambient, 1, glm::value_ptr(mtl.ambient));
// 	glUniform3fv(_attr.light.diffuse, 1, glm::value_ptr(mtl.diffuse));
// 	glUniform3fv(_attr.light.specular, 1, glm::value_ptr(mtl.specular));
// 	glUniform1f(_attr.light.shininess, 25.0f);
// 	glUniform1f(_attr.light.coefficient, 1.0f);
// 	glUniform1f(_attr.light.attenuation, 0.0f);
// }