/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GUIOpenGL.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:16:38 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 15:04:44 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUIOPENGL_CLASS_HPP
# define GUIOPENGL_CLASS_HPP

# define GL_MAJOR		4
# define GL_MINOR		0

# include <libs/GL/glew.h>
# include <libs/glfw/glfw3.h>

# include <game/Gomoku.hpp>
# include <gui/IGUIModule.hpp>
# include <gui/opengl/object/GLBoard.hpp>
# include <gui/opengl/object/GLStone.hpp>
# include <gui/opengl/object/GLFactory.hpp>
# include <gui/opengl/Panels.hpp>

class GUIOpenGL: public IGUIModule
{
	public:
		GUIOpenGL(Window const & window, Gomoku & gomoku);
		virtual ~GUIOpenGL(void);

		virtual void		setup(void);
		virtual int			render(void);

	private:
		void				GLwindow(void);
		void				GLcontext(void);
		void				addGhost(int const & turn, Intersection const & ghost);
		void				addStones(t_board const & intersections);
		void				drawCalls(void);
		void				clearCalls(void);
		void				viewport(int const & x);

		GLFWwindow *		_glWindow;
		GLBoard *			_board;
		GLStone	*			_stones[MAX_PLAYERS];
		GLFont *			_font[MAX_FONTS];
		Gomoku &			_gomoku;

		int					_width;
		int					_height;

		static void			rotate(GLfloat const & angle);
		static void			move(glm::vec3 const & position);
		static void			scale(GLfloat const & delta);
		static void			reset(void);
		static void			inputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);

		static GUIOpenGL *	_GLFW;
};

#endif /* ! GUIOPENGL_CLASS_HPP */
