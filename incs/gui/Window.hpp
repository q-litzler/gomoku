/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Window.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:20:25 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/20 19:22:26 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_CLASS_HPP
# define WINDOW_CLASS_HPP

# include <iostream>

struct Window
{
	public:
		Window(std::string const & name, int const & width, int const & height);
		~Window(void);

		std::string const &		name;
		int const				width;
		int const				height;
};

#endif /* ! WINDOW_CLASS_HPP */
