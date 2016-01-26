/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Define.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 18:05:25 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 15:29:42 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CLASS_HPP
# define _CLASS_HPP

# include <game/Intersection.hpp>
# include <vector>
# include <list>
# include <forward_list>
# include <queue>

# define MAX_FONTS		2
# define MAX_PLAYERS	2
# define INITIAL		9
# define CAPTURED10 	10

enum e_replay
{
	BOARD = 0,
	EVENT
};

enum e_mode
{
	REGULAR = 0,
	REPLAY,
	SEARCH
};

enum e_intelligence
{
	HUMAN = 0,
	AI
};

enum e_loop
{
	ESC = 0,
	CONTINUE
};

enum e_player
{
	NONE = -1,
	WHITE,
	BLACK
};

enum e_pattern
{
	CAPTURE = 0,
	LEGAL,
	VICTORY5,
	FREE3,
	FREE4
};

enum e_font
{
	FONT10 = 0,
	FONT12	
};

struct s_minimax;

typedef std::vector<Intersection>				t_board;
typedef std::forward_list<s_minimax>			t_children;

struct s_minimax
{
	t_board				state;
	Coord				move;
	int					alpha;
	int					beta;
	int					h;
	s_minimax *			parent;
	t_children			children;
};

typedef std::list<Intersection>					t_captured;
typedef std::vector<t_board>					t_direction;
typedef std::list<t_board >						t_matches;
typedef std::vector<int>						t_pattern;
typedef std::list<t_pattern >					t_patterns;
typedef std::pair<Intersection, t_board >		t_event;
typedef std::deque<t_event >					t_replay;

#endif /* ! _CLASS_HPP */
