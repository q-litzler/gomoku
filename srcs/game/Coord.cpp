/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Coord.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:19:39 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:25:20 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Coord.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Coord::Coord(void)
{
	
}

Coord::Coord(int const & x, int const & y): x(x), y(y)
{
	
}

Coord::~Coord(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

std::string		Coord::printCoord(Coord const & coord)
{
	std::stringstream	ss;

	ss << Coord::printX(coord.x) << Coord::printY(coord.y);
	return ss.str();
}

char		Coord::printX(int const & x)
{
	return static_cast<char>(x + 97);
}

int			Coord::printY(int const & y)
{
	return y + 1;
}
