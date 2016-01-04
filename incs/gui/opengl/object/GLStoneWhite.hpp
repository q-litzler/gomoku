/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStoneWhite.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:29:03 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 15:31:32 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSTONEWHITE_CLASS_HPP
# define GLSTONEWHITE_CLASS_HPP

# include <gui/opengl/object/GLStone.hpp>

class GLStoneWhite: public GLStone
{
	public:
		GLStoneWhite(Model3D & model3D, Camera & camera, GLShader const * shader);
		virtual ~GLStoneWhite(void);

	private:

};

#endif /* ! GLSTONEWHITE_CLASS_HPP */
