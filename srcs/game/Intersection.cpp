/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersection.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:55:13 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/02 16:09:49 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Intersection.hpp>
#include <game/Gomoku.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Intersection::Intersection(int const & x, int const & y): x(x), y(y), stone(NONE)
{
	if (x < 0 || x > 18 || y < 0 || y > 18)
	{
		std::cout << "error: " << x << " " << y << std::endl;
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