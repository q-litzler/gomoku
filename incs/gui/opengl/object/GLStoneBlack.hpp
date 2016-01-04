/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStoneBlack.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/31 15:27:42 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 15:31:29 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSTONEBLACK_CLASS_HPP
# define GLSTONEBLACK_CLASS_HPP

# include <gui/opengl/object/GLStone.hpp>

class GLStoneBlack: public GLStone
{
	public:
		GLStoneBlack(Model3D & model3D, Camera & camera, GLShader const * shader);
		virtual ~GLStoneBlack(void);

	private:

};

#endif /* ! GLSTONEBLACK_CLASS_HPP */
