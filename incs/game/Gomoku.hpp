/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gomoku.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:04:56 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 20:52:00 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_CLASS_HPP
# define GOMOKU_CLASS_HPP

# include <gui/IGUIModule.hpp>
# include <gui/Model3D.hpp>
# include <gui/Camera.hpp>
# include <game/Board.hpp>

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

class Gomoku
{
	public:
		Gomoku(Board & board);
		~Gomoku(void);

		Board			getBoard(void) const;
		Intersection	getGhost(void) const;
		int				getPlayer(void) const;
		int				getVictory(void) const;

		void			gameLoop(void);
		void			setup(void);
		void			reset(void);
		void			moveGhost(int const & x, int const & y);
		void			addStone(void);
		void			victoryByCapture(void);

	private:
		Gomoku(void);

		IGUIModule *	_moduleGUI;
		Board &			_board;
		Model3D *		_model3D;
		Camera *		_camera;
		int				_player;
		Intersection	_ghost;
		int				_victory;
		std::vector<Intersection>	_captured[2];
};

#endif /* ! GOMOKU_CLASS_HPP */
