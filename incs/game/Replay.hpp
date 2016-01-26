/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replay.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:05:22 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:14:15 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLAY_CLASS_HPP
# define REPLAY_CLASS_HPP

# include <regex>
# include <fstream>
# include <sstream>

# include <Define.hpp>

struct	s_regex_replay;

class Replay
{
	public:
		Replay(char const * path);
		~Replay(void);

		static void						save(t_replay const & replay);

		void							parse(t_replay & replay);		

	private:
		void							move(std::smatch const & captured, t_replay & replay);
		Replay(void);
		std::ifstream					_file;
		static const s_regex_replay		_regex[1];
};

struct	s_regex_replay {
	std::regex const	pattern;
	void				(Replay::*f)(std::smatch const & captured, t_replay & replay);
};

#endif /* ! REPLAY_CLASS_HPP */
