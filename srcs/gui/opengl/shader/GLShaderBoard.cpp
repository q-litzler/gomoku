/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShaderBoard.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:34:40 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:19:50 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLShaderBoard.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLShaderBoard::GLShaderBoard(void):
GLShader("shaders/board_vertex.glsl", "shaders/board_fragment.glsl")
{
	_attr.vertex.position = glGetAttribLocation(_id, "v_position");
	_attr.vertex.normal = glGetAttribLocation(_id, "v_normal");
	_attr.vertex.texture = glGetAttribLocation(_id, "v_texture");
	_attr.vertex.material = glGetUniformLocation(_id, "v_material");
	_attr.matrix.model = glGetUniformLocation(_id, "model");
	_attr.matrix.view = glGetUniformLocation(_id, "view");
	_attr.matrix.projection = glGetUniformLocation(_id, "projection");
	_attr.matrix.camera = glGetUniformLocation(_id, "camera");
	_attr.light.position = glGetUniformLocation(_id, "light.position");
	_attr.light.ambient = glGetUniformLocation(_id, "light.ambient");
	_attr.light.diffuse = glGetUniformLocation(_id, "light.diffuse");
	_attr.light.specular = glGetUniformLocation(_id, "light.specular");
	_attr.light.coefficient = glGetUniformLocation(_id, "light.coefficient");
	_attr.light.shininess = glGetUniformLocation(_id, "light.shininess");
}

GLShaderBoard::~GLShaderBoard(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLShaderBoard::uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const
{
	GLShader::uniforms(model3D, camera, mtl);
	glUniform1f(_attr.vertex.material, 1.0f);
}
