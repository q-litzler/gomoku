/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:50:03 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 15:50:04 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_CLASS_HPP
# define BOARD_CLASS_HPP

# include <vector>

# include <Define.hpp>
# include <game/Intersection.hpp>
# include <game/Pattern.hpp>

class Board
{
	public:
		Board(int const & side);
		~Board(void);

		t_board			getBoard(void) const;
		int				getSide() const;

		void			clear(void);
		int				addStone(e_player const & player, Coord const & coord);
		t_matches		pattern(e_pattern const & type, e_player const & player, Coord const & coord);

		int				isLegal(e_player const & player, Coord const & coord);
		void			removeStone(Coord const & coord);

	private:
		Board(void);

		t_matches		match(t_patterns const & patterns, t_board const & chunck);
		int				normalize(Coord const & coord);
		int				normalize(int const & x, int const & y);
		t_direction		directions(Coord const & coord, int const & range);
		t_board			direction(Coord const & coord, int const & range, int const & xRange, int const & yRange, int const & dirX, int const & dirY);

		int const		_side;
		t_board			_board;
};

#endif /* ! BOARD_CLASS_HPP */
