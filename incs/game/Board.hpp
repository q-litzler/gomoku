/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Board.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:50:03 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 21:57:31 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOARD_CLASS_HPP
# define BOARD_CLASS_HPP

# include <vector>

# include <game/Intersection.hpp>

class Board
{
	public:
		Board(int const & x);
		~Board(void);

		std::vector<Intersection>		getIntersections(void) const;
		int								getSide() const;


		void		clear(void);
		int			addStone(int const & x, int const & y, int const & player);
		void		capture(int const & x, int const & y, int const & player, std::vector<Intersection> & captured);
		void		removeStone(int const & x, int const & y, std::vector<Intersection> & captured);
		int			victoryByAlignement(int const & x,  int const & y, int const & player);
		int			alignement(int const & x, int const & y, int const & player, int const & xNeg, int const & yNeg);

	private:
		Board(void);\

		int			normalize(int const & x, int const & y);

		int const					_side;
		int	const					_size;
		std::vector<Intersection>	_board;

		static int					_grid[16];
		static int					_regression[16];

};

#endif /* ! BOARD_CLASS_HPP */
