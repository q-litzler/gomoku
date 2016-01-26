/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pattern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 16:29:12 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/12 18:08:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game/Pattern.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Pattern::~Pattern(void)
{
	
}

/*******************************************
	Accessors
*******************************************/


/*******************************************
	Non-Member functions
*******************************************/

s_patterns const		Pattern::patterns[MAX_PLAYERS][5] =
{
	{
		{ Pattern::capture(WHITE),		3	},
		{ Pattern::legal(WHITE),		5	},
		{ Pattern::aligned5(WHITE),		5	},
		{ Pattern::freeX(WHITE, 3),		5	},
		{ Pattern::freeX(WHITE, 4),		6	},
	},
	{
		{ Pattern::capture(BLACK),		3	},
		{ Pattern::legal(BLACK),		5	},
		{ Pattern::aligned5(BLACK),		5	},
		{ Pattern::freeX(BLACK, 3),		5	},
		{ Pattern::freeX(BLACK, 4),		6	},
	}
};

t_patterns			Pattern::capture(e_player const & player)
{
	t_patterns		patterns;
	t_pattern		pattern;

	pattern.push_back(player);
	pattern.push_back(!player);
	pattern.push_back(!player);
	pattern.push_back(player);
	patterns.push_back(pattern);
	return patterns;
}

t_patterns			Pattern::aligned5(e_player const & player)
{
	t_patterns			patterns;
	t_pattern			pattern;

	for (int i = 0; i < 5; ++i)
	{
		pattern.push_back(player);
	}
	patterns.push_back(pattern);
	return patterns;
}

t_patterns			Pattern::freeX(e_player const & player, int const & x)
{
	t_patterns			patterns;
	t_pattern			pattern;

	pattern.push_back(NONE);
	for (int i = 0; i < x; ++i)
	{
		pattern.push_back(player);
	}
	pattern.push_back(NONE);
	patterns.push_back(pattern);
	return patterns;
}

t_patterns			Pattern::legal(e_player const & player)
{
	t_patterns			patterns;
	t_pattern			pattern;

	pattern.push_back(NONE);
	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(NONE);
	patterns.push_back(pattern);
	pattern.clear();

	pattern.push_back(NONE);
	pattern.push_back(player);
	pattern.push_back(NONE);
	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(NONE);
	patterns.push_back(pattern);
	pattern.clear();

	pattern.push_back(NONE);
	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(NONE);
	pattern.push_back(player);
	pattern.push_back(NONE);
	patterns.push_back(pattern);
	pattern.clear();

	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(player);
	pattern.push_back(player);
	patterns.push_back(pattern);
	pattern.clear();

	return patterns;
}

