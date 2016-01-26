/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:54:14 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 15:51:24 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <game/Gomoku.hpp>
# include <game/Board.hpp>
# include <exception>

void				intelligence(Gomoku & gomoku, char const * argv, e_player const & player)
{
	std::string		human("human");
	std::string		ai("ai");

	if (!human.compare(argv))
	{
		gomoku.setIntelligence(player, HUMAN);
	}
	else if (!ai.compare(argv))
	{
		gomoku.setIntelligence(player, AI);
	}
	else
	{
		std::cerr << "Usage: ./gomoku [HUMAN] [AI]" << std::endl;
		throw std::exception();
	}
}

int					main(int argc, char **argv)
{
	try
	{
		e_mode			mode = argc == 2 ? REPLAY: REGULAR;
		Board			board(19);
		Gomoku			gomoku(board, mode);

		if (argc == 3)
		{
			intelligence(gomoku, argv[1], BLACK);
			intelligence(gomoku, argv[2], WHITE);
		}
		if (mode == REPLAY)
		{
			gomoku.replay(argv[1]);
		}
		gomoku.setup();
		gomoku.gameLoop();
	} catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}