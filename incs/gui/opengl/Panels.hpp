/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Panels.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:17:19 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:23 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PANELS_CLASS_HPP
# define PANELS_CLASS_HPP

# include <sstream>
# include <iterator>

# include <libs/GL/glew.h>
# include <libs/glfw/glfw3.h>
# include <Define.hpp>

# include <game/Gomoku.hpp>
# include <gui/opengl/object/GLFactory.hpp>

class Panels
{
	public:
		Panels(void);
		~Panels(void);
		static void				viewport(int const & x, int const & width, int const & height);
		static void				drawText(std::stringstream & ss, GLFont const & font, GLfloat const & x, GLfloat const & y, glm::vec3 const & color);
		static void				rightPanel(Gomoku const & gomoku, GLFont * font[MAX_FONTS]);
		static void				informations(Gomoku const & gomoku, GLFont * font[MAX_FONTS], GLfloat const & x, GLfloat const & y);
		static void				lastMoves(Gomoku const & gomoku, GLFont * font[MAX_FONTS], GLfloat const & x, GLfloat const & y);
		static char const *		_names[MAX_PLAYERS];
		static GLfloat const	_centerPanel;
		static GLfloat const	_borderPanel;

	private:


};

#endif /* ! PANELS_CLASS_HPP */
