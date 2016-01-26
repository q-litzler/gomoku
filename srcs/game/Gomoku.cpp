/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:05:22 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:15 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/GUIOpenGL.hpp>
#include <game/Gomoku.hpp>
#include <game/Board.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Gomoku::Gomoku(Board & board, e_mode const & mode):
_board(board), _mode(mode), _player(BLACK),
_ghost(Intersection(Coord(INITIAL, INITIAL))), _victory(NONE)
{
	Window		window("Gomoku", 1920, 1080);

	_moduleGUI = new GUIOpenGL(window, *this);
}

Gomoku::~Gomoku(void)
{

}

/*******************************************
	Accessors
*******************************************/

e_mode			Gomoku::getMode(void) const { return _mode; }
Board			Gomoku::getBoard(void) const { return _board; }
Intersection	Gomoku::getGhost(void) const { return _ghost; }
e_player		Gomoku::getPlayer(void) const { return _player; }
e_player		Gomoku::getVictory(void) const { return _victory; }
t_captured		Gomoku::getCaptured(e_player const & player) const { return _captured[player]; }
t_replay		Gomoku::getReplay(void) const { return _replay; }

void			Gomoku::setPlayer(e_player const & player) { _player = player; }
void			Gomoku::setIntelligence(e_player const & player, e_intelligence const & intelligence)
{
	_intelligence[player] = intelligence;
}

/*******************************************
	Member functions
*******************************************/

Coord			Gomoku::turnMode(void)
{
	Coord		coord;

	if (_mode == REGULAR)
	{
		coord = _ghost.coord;
	}
	else
	{
		if (_it != _load.end())
		{
			coord = std::get<BOARD>(*_it).coord;
			++_it;
			if (_it == _load.end())
			{
				_mode = REGULAR;
			}
		}
	}
	return coord;
}

void			Gomoku::turn(void)
{
	Coord const		coord = turnMode();

	if (_victory == NONE && _board.isLegal(_player, coord) < 2)
	{
		if (_board.addStone(_player, coord))
		{
			_replay.push_back(std::make_pair(coord, t_board()));
			capture(_board.pattern(CAPTURE, _player, coord));
			victory5(_board.pattern(VICTORY5, _player, coord));
			_player = _player == WHITE ? BLACK : WHITE;
		}
	}
}

void			Gomoku::victory5(t_matches const & matches)
{
	t_matches::const_iterator	match;
	t_board::const_iterator		board;

	for (match = matches.begin(); match != matches.end(); ++match)
	{
		for (board = (*match).begin(); board != (*match).end(); ++board)
		{
			std::get<EVENT>(_replay.back()).push_back((*board));
		}
	}
	_victory = !matches.empty() || _captured[!_player].size() >= CAPTURED10 ? _player : NONE;
}

void			Gomoku::capture(t_matches const & matches)
{
	t_matches::const_iterator	match;

	for (match = matches.begin(); match != matches.end(); ++match)
	{
		removeStone(*match, 1);
		removeStone(*match, 2);
	}
}

void			Gomoku::removeStone(t_board const & board, int const & index)
{
	_board.removeStone(board[index].coord);
	_captured[!_player].push_back(Intersection(board[index].coord));
	std::get<EVENT>(_replay.back()).push_back(board[index].coord);
}

void			Gomoku::moveGhost(Coord const & coord)
{
	int	const	newX = _ghost.coord.x + coord.x;
	int	const	newY = _ghost.coord.y + coord.y;
	int	const	size = _board.getSide();

	if (_mode == REGULAR && newX >= 0 && newX < size && newY >= 0 && newY < size)
	{
		_ghost.coord.x = newX;
		_ghost.coord.y = newY;
	}
}

void			Gomoku::setup(void)
{
	_moduleGUI->setup();
}

void			Gomoku::replay(char const * path)
{
	Replay		replay(path);

	replay.parse(_load);
	_it = _load.begin();
}

void			Gomoku::save(void)
{
	Replay::save(_replay);
}

void			Gomoku::reset(void)
{
	_ghost.coord.x = INITIAL;
	_ghost.coord.y = INITIAL;
	_captured[WHITE].clear();
	_captured[BLACK].clear();
	_replay.clear();
	_board.clear();
	_victory = NONE;
	_player = BLACK;
}

void			Gomoku::gameLoop()
{
	while (CONTINUE)
	{
		if (_moduleGUI->render() == ESC) {
			break ;
		}
		if (_intelligence[_player] == AI)
		{
			AI::turn(*this);
		}
	}
}
