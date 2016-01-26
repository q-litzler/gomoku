/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replay.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:05:22 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:15 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <game/Replay.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Replay::Replay(char const * path)
{
	_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	_file.open(path);
	_file.exceptions(std::ifstream::badbit);
}

Replay::~Replay(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void		Replay::parse(t_replay & replay)
{
	std::string		line;
	std::string		move;

	while (std::getline(_file, line))
	{
		std::stringstream		ss(line);
		while (std::getline(ss, move, ' '))
		{
			for (int i = 0; i < 1; ++i)
			{
				auto begin = std::sregex_iterator(move.begin(), move.end(), _regex[i].pattern);
				for (std::sregex_iterator it = begin; it != std::sregex_iterator(); ++it)
				{
					(this->*_regex[i].f)(std::smatch(*it), replay);
				}
			}
		}
	}
}

void			Replay::save(t_replay const & replay)
{
	std::ofstream				save;
 	std::time_t					result = std::time(nullptr);
 	t_replay::const_iterator	it;
 	int							i;
 	std::stringstream			ss;

 	ss << "replay/" << std::asctime(std::localtime(&result)) << ".txt";
	save.open (ss.str().c_str());
	for (i = 1, it = replay.begin(); it != replay.end(); ++it, ++i)
	{
		Intersection		get = std::get<BOARD>(*it);
		save << get.coord.x << ":" << get.coord.y;
		if (i % 2 == 0)
		{
			save << std::endl;
		} else
		{
			save << " ";
		}
	}
	save.close();
}

void		Replay::move(std::smatch const & captured, t_replay & replay)
{
	t_board		special;

	replay.push_back(
		std::make_pair(
			Intersection(
				Coord(
					std::atoi(captured[1].str().c_str()),
					std::atoi(captured[2].str().c_str())
				)
			),
			special
		)
	);
}

const s_regex_replay		Replay::_regex[1] = {
	{ std::regex("(\\d+):(\\d+)"), &Replay::move},
};
