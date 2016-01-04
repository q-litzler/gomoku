/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShader.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSHADER_CLASS_HPP
# define GLSHADER_CLASS_HPP

# include <iostream>
# include <gui/opengl/shader/IGLShader.hpp>

class GLShader: public IGLShader
{
	public:
		GLShader(char const * fileVertex, char const * fileFragment);
		virtual ~GLShader(void);

		GLuint					getPosition(void) const;
		GLuint					getColor(void) const;
		GLuint					getNormal(void) const;
		GLuint					getTexture(void) const;
		GLuint					getMaterial(void) const;
		GLuint					getInstance(void) const;

		void					freeResources(void);
		virtual void			use(void) const;
		virtual void			uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const;

	protected:
		GLuint 					_id;
		s_attributes			_attr;

	private:
		void					readShader(GLint const & source, char const * fileVertex);
		void					compile(GLuint & program, char const * file, GLenum const & type);
		void					checkStatus(GLuint & program);
		FILE *					readFile(char const *path);

		GLuint					_vertex;
		GLuint					_fragment;
};

#endif /* ! GLSHADER_CLASS_HPP */
