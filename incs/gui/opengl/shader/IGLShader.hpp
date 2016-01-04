/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGLShader.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 13:08:51 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:31:58 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLSHADER_CLASS_HPP
# define IGLSHADER_CLASS_HPP

# include <gui/Model3D.hpp>
# include <gui/Camera.hpp>
# include <gui/opengl/object/GLParser.hpp>

struct s_light
{
	GLuint		position;
	GLuint		ambient;
	GLuint		specular;
	GLuint		filter;
	GLuint		diffuse;
	GLuint		coefficient;
	GLuint		shininess;
	GLuint		attenuation;
};

struct s_vertex
{
	GLuint		position;
	GLuint		color;
	GLuint		normal;
	GLuint		texture;
	GLuint		material;
	GLuint		instance;
};

struct s_matrix
{
	GLuint		model;
	GLuint		view;
	GLuint		projection;
	GLuint		camera;
};

struct s_attributes
{
	s_light		light;
	s_vertex	vertex;
	s_matrix	matrix;
};

class IGLShader
{
	public:
		IGLShader(void) {};
		virtual ~IGLShader(void) {};

		virtual void			use(void) const = 0;

		virtual void			uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const = 0;

	private:

};

#endif /* ! IGLSHADER_CLASS_HPP */
