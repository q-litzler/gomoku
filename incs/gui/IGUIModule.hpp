/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGUIModule.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:01:51 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/01 14:21:21 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGUIMODULE_CLASS_HPP
# define IGUIMODULE_CLASS_HPP

# include <vector>

# include <gui/Window.hpp>

class Gomoku;

class IGUIModule
{
	public:
		IGUIModule(Window const & window): _window(window) {};
		virtual ~IGUIModule(void) {};
	
		virtual void		setup(void) = 0;
		virtual int			render(void) = 0;

	protected:
		Window const &		_window;

	private:
		IGUIModule(void);

};

#endif /* ! IGUIMODULE_CLASS_HPP */
