/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersection.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:53:57 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:25:45 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_CLASS_HPP
# define INTERSECTION_CLASS_HPP

# include <game/Coord.hpp>

struct Intersection
{
	public:
		Intersection(Coord const & coord);
		~Intersection(void);

		Coord		coord;
		int			stone;

	private:
		Intersection(void);


};

#endif /* ! INTERSECTION_CLASS_HPP */
