/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pattern.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:28:33 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:06:55 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATTERN_CLASS_HPP
# define PATTERN_CLASS_HPP

# include <vector>

# include <Define.hpp>

struct		s_patterns
{
	t_patterns const	patterns;
	int	const			range;
};

class Pattern
{
	public:
		~Pattern(void);
		static s_patterns const		patterns[MAX_PLAYERS][5];

	private:
		Pattern(void);
		static t_patterns			capture(e_player const & player);
		static t_patterns			aligned5(e_player const & player);
		static t_patterns			freeX(e_player const & player, int const & x);
		static t_patterns			legal(e_player const & player);
};

#endif /* ! PATTERN_CLASS_HPP */
