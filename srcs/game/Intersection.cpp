/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersection.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:55:13 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:25:45 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Intersection.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Intersection::Intersection(Coord const & coord): coord(coord), stone(NONE)
{
	if (coord.x < 0 || coord.x > 18 || coord.y < 0 || coord.y > 18)
	{
		std::cout << "error: " << coord.x << " " << coord.y << std::endl;
		throw std::exception();
	}
}

Intersection::~Intersection(void)
{
	
}

/*******************************************
	Accessors
*******************************************/


/*******************************************
	Member functions
*******************************************/