/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:52:34 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 15:50:07 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Board.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Board::Board(int const & side): _side(side)
{
	int			size = _side * _side;

	_board.reserve(size);
	for (int i = 0; i < size; ++i)
	{
		_board.push_back(Intersection(Coord(i % _side, i / _side)));
	}
}

Board::~Board(void)
{

}

/*******************************************
	Accessors
*******************************************/

t_board		Board::getBoard(void) const { return _board; }
int			Board::getSide(void) const { return _side; }

/*******************************************
	Member functions
*******************************************/

int			Board::addStone(e_player const & player, Coord const & coord)
{
	int			index = normalize(coord);

	if (_board[index].stone == NONE)
	{
		_board[index].stone = player;
		return (1);
	}
	return (0);
}

void		Board::removeStone(Coord const & coord)
{
	_board[normalize(coord)].stone = NONE;
}

void		Board::clear(void)
{
	t_board::iterator	it;

	for (it = _board.begin(); it != _board.end(); ++it)
	{
		(*it).stone = NONE;
	}
}

t_direction	Board::directions(Coord const & coord, int const & range)
{
	t_direction		directions;

	directions.reserve(4);
	directions.push_back(direction(coord, range, -1, 0, 1, 0));
	directions.push_back(direction(coord, range, 0, -1, 0, 1));
	directions.push_back(direction(coord, range, -1, -1, 1, 1));
	directions.push_back(direction(coord, range, 1, -1, -1, 1));
	return directions;
}

t_matches	Board::pattern(e_pattern const & type, e_player const & player, Coord const & coord)
{
	t_matches				matches;
	t_matches				result;

	t_patterns				patterns = Pattern::patterns[player][type].patterns;
	t_direction				directions = this->directions(coord, Pattern::patterns[player][type].range);
	t_direction::iterator	direction;

	for (direction = directions.begin(); direction != directions.end(); ++direction)
	{
		matches = match(patterns, *direction);
		if (!matches.empty())
		{
			result.push_back(matches.front());	
		}
	}
	return result;
}

int			Board::isLegal(e_player const & player, Coord const & coord)
{
	int				legals = 0;
	int				save = _board[normalize(coord)].stone;


	_board[normalize(coord)].stone = player;
	legals = pattern(LEGAL, player, coord).size();
	_board[normalize(coord)].stone = save;
	return legals;
}

t_matches	Board::match(t_patterns const & patterns, t_board const & chunck)
{
	int							match;
	t_patterns::const_iterator	pattern;
	t_matches					result;

	for (unsigned long i = 0; i < chunck.size(); ++i)
	{
		for (pattern = patterns.begin(); pattern != patterns.end(); ++pattern)
		{
			match = 1;
			for (unsigned long j = 0; j < (*pattern).size(); ++j)
			{
				if (i + j >= chunck.size() || (*pattern)[j] != chunck[i + j].stone)
				{
					match = 0;
					break ;
				}
			}
			if (match == 1)
			{
				result.push_back(t_board(chunck.begin() + i, chunck.end()));
			}
		}
	}
	return (result);
}

t_board		Board::direction(Coord const & coord, int const & range, int const & xRange, int const & yRange, int const & dirX, int const & dirY)
{
	t_board		diagonal;

	int			index;
	int const	doubleRange = range * 2 + 1;
	int			newX = coord.x + range * xRange;
	int			newY = coord.y + range * yRange;

	diagonal.reserve(doubleRange);
	for (int i = 0; i < doubleRange; ++i)
	{
		if (newX >= 0 && newX < _side && newY >= 0 && newY < _side)
		{
			index = normalize(newX, newY);
			diagonal.push_back(_board[index]);
		}
		newY += dirY;
		newX += dirX;
	}
	return diagonal;
}

int			Board::normalize(int const & x, int const & y)
{
	return y * _side + x;
}

int			Board::normalize(Coord const & coord)
{
	return coord.y * _side + coord.x;
}
