/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLObject.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:15:58 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:43:28 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBJECT_CLASS_HPP
# define GLOBJECT_CLASS_HPP

# include <libs/GL/glew.h>

# include <gui/opengl/object/GLParser.hpp>
# include <gui/opengl/object/IGLObject.hpp>

enum e_bo
{
	VBO = 0,
	PBO,
	NBO,
};

enum e_dimension
{
	UV = 2,
	XYZ,
	RGBA
};

class GLObject: public IGLObject
{
	public:
		GLObject(Model3D & model3D, Camera & camera, GLShader const * shader, char const * objFile);
		virtual ~GLObject(void);

	protected:
		void				indexingBO(std::vector<GLfloat> & bo, std::vector<GLuint> & ebo, e_dimension const & dimensions);
		void				generateBO(GLuint & buffer, std::vector<GLfloat> const & bo, int const & size, GLenum type);
		void				setBO(GLuint const & bo, GLint const & sbo, e_dimension const & dimension);

		GLuint				_vao;
		GLuint				_vbo;
		GLuint				_nbo;

		s_obj				_obj;
		s_mtl				_mtl;
};

#endif /* ! GLOBJECT_CLASS_HPP */
