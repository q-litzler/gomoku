/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLFactory.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLFACTORY_CLASS_HPP
# define GLFACTORY_CLASS_HPP

# include <gui/opengl/object/GLBoard.hpp>
# include <gui/opengl/object/GLStone.hpp>
# include <gui/opengl/object/GLFont.hpp>
# include <gui/opengl/shader/GLSFactory.hpp>

enum e_gl_factory
{
	GL_BOARD = 0,
	GL_STONE_WHITE,
	GL_STONE_BLACK,
	GL_FONT10,
	GL_FONT12
};

struct s_gl;

class GLFactory
{
	public:
		~GLFactory(void);

		static IGLObject * newInstance(e_gl_factory const & type);

	private:
		GLFactory(void);
		static IGLObject *				newGLBoard(void);
		static IGLObject *				newGLStoneWhite(void);
		static IGLObject *				newGLStoneBlack(void);
		static IGLObject *				newGLFont10(void);
		static IGLObject *				newGLFont12(void);
		static s_gl						_gl[];

};

struct s_gl
{
	IGLObject *		(*f)(void);
};

#endif /* ! GLFACTORY_CLASS_HPP */
