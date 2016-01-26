/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLFont.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:15:58 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:43:28 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFONT_CLASS_HPP
# define GLFONT_CLASS_HPP

# include <iostream>
# include <map>

# include <libs/GL/glew.h>

# include <gui/model/Model2D.hpp>
# include <gui/opengl/shader/GLSFont.hpp>
# include <gui/opengl/object/GLObject.hpp>
# include <gui/opengl/object/IGLObject.hpp>

struct e_character
{
	GLuint		textureID;
	glm::ivec2	size;
	glm::ivec2	bearing;
	GLuint		advance;
};

class GLFont: public IGLObject
{
	public:
		GLFont(Model2D & model2D, GLSFont const * shader, int const & fontSize);
		~GLFont(void);

		void							draw(std::string const & text, GLfloat const & x, GLfloat const & y, GLfloat const & scale, glm::vec3 const & color) const;
		virtual void					draw(void) const;
		virtual void					move(glm::vec3 const & position);
		virtual void					rotate(GLfloat const & angle);
		virtual void					scale(GLfloat const & delta);
		virtual void					reset(void);

	private:
		void							generate(void);
		void							freetype(int const & fontSize);
		void							uniforms(glm::vec3 const & color) const;

		Model2D &						_model2D;
		GLSFont const *					_shader;

		GLuint							_vao;
		GLuint							_vbo;

		std::map<GLchar, e_character>	_characters;
};

#endif /* ! GLFONT_CLASS_HPP */
