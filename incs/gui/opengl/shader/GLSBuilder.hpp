/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSBuilder.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSBUILDER_CLASS_HPP
# define GLSBUILDER_CLASS_HPP

# include <iostream>
# include <libs/glfw/glfw3.h>

class GLSBuilder
{
	public:
		GLSBuilder(char const * fileVertex, char const * fileFragment);
		virtual ~GLSBuilder(void);

		void					freeResources(void);
		GLuint					getId(void) const;

	private:
		void					readShader(GLint const & source, char const * fileVertex);
		void					compile(GLuint & program, char const * file, GLenum const & type);
		void					checkStatus(GLuint & program);
		FILE *					readFile(char const *path);

		GLuint 					_id;
		GLuint					_vertex;
		GLuint					_fragment;
};

#endif /* ! GLSBUILDER_CLASS_HPP */
