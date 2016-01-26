/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSFactory.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSFACTORY_CLASS_HPP
# define GLSFACTORY_CLASS_HPP

# include <gui/opengl/shader/GLSBuilder.hpp>
# include <gui/opengl/shader/GLSBoard.hpp>
# include <gui/opengl/shader/GLSStone.hpp>
# include <gui/opengl/shader/GLSFont.hpp>

enum e_gls_factory
{
	GLS_BOARD = 0,
	GLS_STONE,
	GLS_FONT
};

struct s_gls;

class GLSFactory
{
	public:
		~GLSFactory(void);

		static GLShader * newInstance(e_gls_factory const & type);

	private:
		GLSFactory(void);
		static GLShader *				newGLSBoard(GLuint const & id);
		static GLShader *				newGLSStone(GLuint const & id);
		static GLShader *				newGLSFont(GLuint const & id);
		static s_gls					_gls[];

};

struct s_gls
{
	char const *	vertex;
	char const *	fragment;
	GLShader *		(*f)(GLuint const & id);
};

#endif /* ! GLSFACTORY_CLASS_HPP */
