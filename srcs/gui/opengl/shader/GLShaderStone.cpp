/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShaderStone.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:50:51 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:19:56 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/shader/GLShaderStone.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLShaderStone::GLShaderStone(void): 
GLShader("shaders/stone_vertex.glsl", "shaders/stone_fragment.glsl")
{
	_attr.vertex.position = glGetAttribLocation(_id, "v_position");
	_attr.vertex.normal = glGetAttribLocation(_id, "v_normal");
	_attr.vertex.color = glGetAttribLocation(_id, "v_color");
	_attr.vertex.instance = glGetAttribLocation(_id, "v_instance");
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

GLShaderStone::~GLShaderStone(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLShaderStone::uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const
{
	GLShader::uniforms(model3D, camera, mtl);
}