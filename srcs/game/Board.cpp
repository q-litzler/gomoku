/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:52:34 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 22:05:06 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Board.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Board::Board(int const & side): _side(side), _size(side * side)
{
	_board.reserve(_size);
	for (int i = 0; i < _size; ++i)
	{
		_board.push_back(Intersection(i % _side, i / _side));
	}
}

Board::~Board(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

std::vector<Intersection>	Board::getIntersections(void) const { return _board; }
int							Board::getSide(void) const { return _side; }

/*******************************************
	Member functions
*******************************************/

int		Board::addStone(int const & x, int const & y, int const & player)
{
	int		coord = normalize(x, y);
	if (_board[coord].stone == NONE)
	{
		_board[coord].stone = player;
		return (1);
	}
	return (0);
}

void	Board::clear(void)
{
	std::vector<Intersection>::iterator	it;
	for (it = _board.begin(); it != _board.end(); ++it)
	{
		(*it).stone = NONE;
	}
}

int		Board::victoryByAlignement(int const & x, int const & y, int const & player)
{
	if (alignement(x, y, player, 1, 0) >= 5
		|| alignement(x, y, player, 0, 1) >= 5
		|| alignement(x, y, player, 1, 1) >= 5
		|| alignement(x, y, player, -1, 1) >= 5
		)
	{
		return (player);
	}

	return (NONE);
}

int		Board::alignement(int const & x, int const & y, int const & player, int const & xNeg, int const & yNeg)
{
	int		aligned = 0;
	int		newX = x;
	int		newY = y;
	int		coord;
	int		direction = 1;

	for (int i = 0; i < _side; ++i)
	{
		coord = normalize(newX, newY);
		if (coord < 0 || coord >= _size)
		{
			break ;
		}
		if (_board[coord].stone != player)
		{
			if (direction == -1)
			{
				break ;
			}
			direction = -1;
			newX = x;
			newY = y;
		} else
		{
			newX += direction * xNeg;
			newY += direction * yNeg;
			++aligned;
		}
	}
	return (aligned - 1);
}

void	Board::capture(int const & x, int const & y, int const & player, std::vector<Intersection> & captured)
{
	int const	points = 16;

	for (int i = 0; i < points; i += 2)
	{
		int		targetX = x + Board::_grid[i];
		int		targetY = y + Board::_grid[i + 1];

		if (targetX < 0 || targetX > _side - 1
			|| targetY < 0 || targetY > _side - 1)
		{
			continue ;
		}
		int const coord = normalize(targetX, targetY);
		if (_board[coord].stone == player)
		{
			int		stoneX = targetX + Board::_regression[i];
			int		stoneY = targetY + Board::_regression[i + 1];
			int		stone1 = normalize(stoneX, stoneY);
			int		stone2 = normalize(stoneX + Board::_regression[i], stoneY + Board::_regression[i + 1]);

			if (_board[stone1].stone == !player && _board[stone2].stone == !player)
			{
				removeStone(stoneX, stoneY, captured);
				removeStone(stoneX + Board::_regression[i], stoneY + Board::_regression[i + 1], captured);
			}
		}
	}
}

int		Board::normalize(int const & x, int const & y)
{
	return y * _side + x;
}

void	Board::removeStone(int const & x, int const & y, std::vector<Intersection> & captured)
{
	_board[normalize(x, y)].stone = NONE;
	captured.push_back(Intersection(x, y));
}

int		Board::_grid[16] = {
	-3, -3, 0, -3, 3, -3,
	3, 0,
	3, 3, 0, 3, -3, 3,
	-3, 0
};

int		Board::_regression[16] = {
	1, 1, 0, 1, -1, 1,
	-1, 0,
	-1, -1, 0, -1, 1, -1,
	1, 0
};