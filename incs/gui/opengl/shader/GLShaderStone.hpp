/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShaderStone.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:22 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:03:24 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSHADERSTONE_CLASS_HPP
# define GLSHADERSTONE_CLASS_HPP

# include <gui/opengl/shader/GLShader.hpp>

class GLShaderStone: public GLShader
{
	public:
		GLShaderStone(void);
		virtual ~GLShaderStone(void);

		virtual void	uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const;
};

#endif /* ! GLSHADERSTONE_CLASS_HPP */
