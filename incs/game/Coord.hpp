/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coord.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:18:35 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:26:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COORD_CLASS_HPP
# define COORD_CLASS_HPP

# include <sstream>

struct Coord
{
	public:
		Coord(void);
		Coord(int const & x, int const & y);
		~Coord(void);

		static std::string		printCoord(Coord const & coord);
		static char				printX(int const & x);
		static int				printY(int const & y);

		int		x;
		int		y;

};

#endif /* ! COORD_CLASS_HPP */
