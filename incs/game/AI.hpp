/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AI.hpp                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:04:56 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AI_CLASS_HPP
# define AI_CLASS_HPP

# include <limits>

# include <Define.hpp>
# include <game/Coord.hpp>

class Gomoku;

class AI
{
	public:
		AI(void);
		~AI(void);

		static void				turn(Gomoku & gomoku);
		static int				heuristic(Gomoku const & gomoku, Coord const & coord);
		static void				children(s_minimax & root, int const & size, e_player const & player, int const & depth);
		static t_children		minimax(t_board const & board, int const & size, e_player const & player);

	private:
};

#endif /* ! AI_CLASS_HPP */
