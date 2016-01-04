/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShaderBoard.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:35:00 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:49:49 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSHADERBOARD_CLASS_HPP
# define GLSHADERBOARD_CLASS_HPP

# include <gui/opengl/shader/GLShader.hpp>

class GLShaderBoard: public GLShader
{
	public:
		GLShaderBoard(void);
		virtual ~GLShaderBoard(void);

		virtual void	uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const;
};

#endif /* ! GLSHADERBOARD_CLASS_HPP */
