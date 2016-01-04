/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:05:22 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 21:59:24 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/GUIOpenGL.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Gomoku::Gomoku(Board & board):
_board(board), _player(WHITE), _ghost(Intersection(0, 0)), _victory(NONE)
{
	Window		window("Gomoku", 1920, 1080);
	_model3D = new Model3D(1.0f, 44.0f);
	_camera = new Camera(glm::vec3(0.0f, 9.0f, 9.0f));

	_moduleGUI = new GUIOpenGL(window, *_model3D, *_camera, *this);
}

Gomoku::~Gomoku(void)
{
	delete _model3D;
	delete _camera;
}

/*******************************************
	Accessors
*******************************************/

Board			Gomoku::getBoard(void) const { return _board; }
Intersection	Gomoku::getGhost(void) const { return _ghost; }
int				Gomoku::getPlayer(void) const { return _player; }
int				Gomoku::getVictory(void) const { return _victory; }

/*******************************************
	Member functions
*******************************************/

void			Gomoku::addStone()
{
	if (_victory == NONE && _board.addStone(_ghost.x, _ghost.y, _player))
	{
		_board.capture(_ghost.x, _ghost.y, _player, _captured[!_player]);
		_victory = _board.victoryByAlignement(_ghost.x, _ghost.y, _player);
		victoryByCapture();
		_player = !_player;
	}
}

void			Gomoku::moveGhost(int const & x, int const & y)
{
	int	const	newX = _ghost.x + x;
	int	const	newY = _ghost.y + y;
	int	const	size = _board.getSide();

	if (newX >= 0 && newX < size && newY >= 0 && newY < size)
	{
		_ghost.x = newX;
		_ghost.y = newY;
	}
}

void			Gomoku::victoryByCapture(void)
{
	if (_captured[!_player].size() >= 10)
	{
		_victory = _player;
	}
}

void			Gomoku::setup(void)
{
	_moduleGUI->setup();
}

void			Gomoku::reset(void)
{
	_ghost.x = 0;
	_ghost.y = 0;
	_captured[WHITE].clear();
	_captured[BLACK].clear();
	_board.clear();
	_victory = NONE;
}

void			Gomoku::gameLoop()
{
	while (CONTINUE)
	{
		if (_moduleGUI->render() == ESC) {
			break ;
		}
	}
}

