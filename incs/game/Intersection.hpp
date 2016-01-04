/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersection.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/01 12:53:57 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/02 14:38:47 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTION_CLASS_HPP
# define INTERSECTION_CLASS_HPP

struct Intersection
{
	public:
		Intersection(int const & x, int const & y);
		~Intersection(void);

		int			x;
		int			y;
		int			stone;

	private:
		Intersection(void);


};

#endif /* ! INTERSECTION_CLASS_HPP */
