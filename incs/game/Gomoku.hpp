/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:04:56 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/13 16:09:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_CLASS_HPP
# define GOMOKU_CLASS_HPP

# include <Define.hpp>
# include <game/AI.hpp>
# include <game/Board.hpp>
# include <game/Replay.hpp>
# include <gui/Camera.hpp>
# include <gui/IGUIModule.hpp>
# include <gui/model/Model3D.hpp>
# include <gui/model/Model2D.hpp>

class Gomoku
{
	public:
		Gomoku(Board & board, e_mode const & mode);
		~Gomoku(void);

		e_mode			getMode(void) const;
		Board			getBoard(void) const;
		Intersection	getGhost(void) const;
		e_player		getPlayer(void) const;
		e_player		getVictory(void) const;
		t_captured		getCaptured(e_player const & player) const;
		t_replay		getReplay(void) const;

		void			setPlayer(e_player const & player);
		void			setIntelligence(e_player const & player, e_intelligence const & intelligence);

		void			gameLoop(void);
		void			setup(void);
		void			reset(void);
		void			moveGhost(Coord const & coord);
		void			turn(void);
		void			save(void);
		void			replay(char const * path);

	private:
		Gomoku(void);
		Coord			turnMode(void);
		void			victory5(t_matches const & matches);
		void			capture(t_matches const & matches);
		void			removeStone(t_board const & board, int const & index);

		IGUIModule *	_moduleGUI;
		Board &			_board;
		e_mode			_mode;
		e_player		_player;
		e_intelligence	_intelligence[MAX_PLAYERS];
		Intersection	_ghost;
		e_player		_victory;
		t_captured		_captured[MAX_PLAYERS];
		t_replay		_replay;
		t_replay		_load;
		t_replay::const_iterator	_it;
};

#endif /* ! GOMOKU_CLASS_HPP */
