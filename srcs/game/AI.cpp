/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.cpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:04:56 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>

#include <game/AI.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

AI::AI(void)
{
	
}

AI::~AI(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Non-Member functions
*******************************************/

t_children		AI::minimax(t_board const & board, int const & size, e_player const & player)
{
	t_children	children;
	s_minimax	child;

	for (int i = 0; i < size; ++i)
	{
		child.state = board;
		if (child.state[i].stone == NONE)
		{
			child.state[i].stone = player;
			children.push_front(child);
		}
	}	
	return children;
}

void		AI::children(s_minimax & root, int const & size, e_player const & player, int const & depth)
{
	t_children::iterator	it;

	if (depth > 0)
	{
		return ;
	}
	for (it = root.children.begin(); it != root.children.end(); ++it)
	{	
		(*it).children = AI::minimax((*it).state, size, player);

		AI::children((*it), size, player == WHITE ? BLACK : WHITE, depth + 1);
	}
}



void		AI::turn(Gomoku & gomoku)
{
	Board					board = gomoku.getBoard();
	int	const				size = board.getSide() * board.getSide();
	e_player				player = gomoku.getPlayer();
	s_minimax				root;
	std::clock_t			start;
    double					duration;

    start = std::clock();
	root.state = board.getBoard();
	root.children = AI::minimax(board.getBoard(), size, player);
	AI::children(root, size, player, 0);
	gomoku.setPlayer(player == WHITE ? BLACK : WHITE);

    duration = (std::clock() - start) / static_cast<double>(CLOCKS_PER_SEC);
    std::cout << std::fixed << duration << std::endl;
}

int			AI::heuristic(Gomoku const & gomoku, Coord const & coord)
{
	Board		board = gomoku.getBoard();
	e_player	player = gomoku.getPlayer();
	t_matches	matches;
	int const	infinity = std::numeric_limits<int>::max();
	int			h = 0;

	if (!board.pattern(VICTORY5, player, coord).empty())
	{
		return (infinity);
	}
	matches = board.pattern(FREE4, player, coord);
	if (!matches.empty())
	{
		return (infinity);
	}
	matches = board.pattern(CAPTURE, player, coord);
	if (matches.size() + gomoku.getCaptured(player).size() >= CAPTURED10)
	{
		return (infinity);
	}
	h += matches.size() * 10;
	matches = board.pattern(FREE3, player, coord);
	h += matches.size() * 1;
	return (h);
}

