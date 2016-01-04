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
# define GL_MINOR		1

# include <libs/GL/glew.h>
# include <libs/glfw/glfw3.h>

# include <game/Gomoku.hpp>
# include <gui/IGUIModule.hpp>
# include <gui/opengl/object/GLBoard.hpp>
# include <gui/opengl/object/GLStoneBlack.hpp>
# include <gui/opengl/object/GLStoneWhite.hpp>
# include <gui/opengl/shader/GLShaderBoard.hpp>
# include <gui/opengl/shader/GLShaderStone.hpp>

class GUIOpenGL: public IGUIModule
{
	public:
		GUIOpenGL(Window const & window, Model3D & model3D, Camera & camera, Gomoku & gomoku);
		virtual ~GUIOpenGL(void);

		virtual void		setup(void);
		virtual int			render(void);

	private:
		void				GLwindow(void);
		void				GLcontext(void);
		void				addGhost(int const & turn, Intersection const & ghost);
		void				addStones(std::vector<Intersection> const & intersections);
		void				drawCalls(void);
		void				clearCalls(void);

		GLFWwindow *		_glWindow;
		GLBoard *			_board;
		GLStone	*			_stones[2];
		Model3D	&			_model3D;
		Camera &			_camera;
		Gomoku &			_gomoku;

		static GUIOpenGL *	_GLFW;
		static void			inputHandler(GLFWwindow* window, int key, int scancode, int action, int mods);
};

#endif /* ! GUIOPENGL_CLASS_HPP */
