/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 18:54:14 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/01 14:55:25 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <game/Gomoku.hpp>
# include <exception>

int					main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	try
	{
		Board		board(19);
		Gomoku		gomoku(board);

		gomoku.setup();
		gomoku.gameLoop();
	} catch (std::exception e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}