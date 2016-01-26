/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IGLObject.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 12:21:55 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:42:05 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IGLOBJECT_CLASS_HPP
# define IGLOBJECT_CLASS_HPP

# include <gui/model/Model3D.hpp>
# include <gui/Camera.hpp>

class IGLObject
{
	public:
		IGLObject(void) {}
		virtual			~IGLObject(void) {};

		virtual void	draw(void) const = 0;
		virtual void	rotate(GLfloat const & angle) = 0;
		virtual void	move(glm::vec3 const & position) = 0;
		virtual void	scale(GLfloat const & delta) = 0;
		virtual void	reset(void) = 0;
};

#endif /* ! IGLOBJECT_CLASS_HPP */
