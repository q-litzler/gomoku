/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Panels.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:17:19 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:23 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/Panels.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Panels::Panels(void)
{
	
}

Panels::~Panels(void)
{

}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Non-Member functions
*******************************************/

void		Panels::viewport(int const & x, int const & width, int const & height)
{
	int		newHeight = height / static_cast<GLfloat>(width) * width * _centerPanel;
	glViewport(x, (height - newHeight) / 2, width * _centerPanel, static_cast<int>(newHeight));
}


void		Panels::drawText(std::stringstream & ss, GLFont const & font, GLfloat const & x, GLfloat const & y, glm::vec3 const & color)
{
	font.draw(ss.str(), x, y, 1.0f, color);
	ss.str("");
	ss.clear();
}

void		Panels::informations(Gomoku const & gomoku, GLFont * font[MAX_FONTS], GLfloat const & x, GLfloat const & y)
{
	std::stringstream	ss;
	e_player const		victory = gomoku.getVictory();
	glm::vec3 const		white = glm::vec3(1.0f, 1.0f, 1.0f);

	if (victory == NONE)
	{
		ss << Panels::_names[gomoku.getPlayer()] << " to move.";
	} else
	{
		ss << Panels::_names[victory] << " is victorious.";
	}
	Panels::drawText(ss, *font[FONT12], x, y, white);
	ss << _names[WHITE] << " captured " << gomoku.getCaptured(BLACK).size() << " stones.";
	Panels::drawText(ss, *font[FONT12], x, y - 50, white);
	ss << _names[BLACK] << " captured " << gomoku.getCaptured(WHITE).size() << " stones.";
	Panels::drawText(ss, *font[FONT12], x, y - 70, white);
}

void		Panels::lastMoves(Gomoku const & gomoku, GLFont * font[MAX_FONTS], GLfloat const & x, GLfloat const & y)
{
	std::stringstream			ss;
	int							i = 1;
	int							turn = 0;
	int const					displayed = 20;
	t_replay::const_iterator	move;
	glm::vec3 const				white = glm::vec3(1.0f, 1.0f, 1.0f);
	t_replay const				replay = gomoku.getReplay();
	int const					replaySize = !replay.empty() ? (replay.size() - 1) / displayed : 0;

	ss << "BLACK";
	Panels::drawText(ss, *font[FONT12], x + 20, y - 150, white);
	ss << "WHITE";
	Panels::drawText(ss, *font[FONT12], x + 150, y - 150, white);
	for (move = replay.begin() + (replaySize * displayed); move != replay.end(); ++move)
	{
		Intersection				getFirst = std::get<BOARD>(*move);
		std::vector<Intersection>	getLast = std::get<EVENT>(*move);

		ss << Coord::printCoord(getFirst.coord);
		if (!getLast.empty())
		{
			ss << " [";
			ss << Coord::printCoord(getLast.front().coord);
			if (getLast.size() > 2)
			{
				ss << " .. ";
			} else
			{
				ss << " - "; 
			}
			ss << Coord::printCoord(getLast.back().coord);
			ss << "]";
		}
		Panels::drawText(ss, *font[FONT10], x + turn, y - 170 - (i * 20), white);
		turn = turn == 0 ? 130 : 0;
		i += turn == 0 ? 1 : 0;
	}
}

void		Panels::rightPanel(Gomoku const & gomoku, GLFont * font[MAX_FONTS])
{
	GLfloat const		y = 580.0f;
	GLfloat const		x = 20.0f;

	informations(gomoku, font, x, y);
	lastMoves(gomoku, font, x, y);
}

char const *	Panels::_names[MAX_PLAYERS] = { "White", "Black" };
GLfloat const	Panels::_centerPanel = 7.0f / 10.0f;
GLfloat const	Panels::_borderPanel = 1.5f / 10.0f;
