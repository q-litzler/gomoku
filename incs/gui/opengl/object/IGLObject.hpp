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

# include <gui/Model3D.hpp>
# include <gui/Camera.hpp>
# include <gui/opengl/shader/GLShader.hpp>

class IGLObject
{
	public:
		IGLObject(Model3D & model3D, Camera & camera, GLShader const * shader):
		_model3D(model3D), _camera(camera), _shader(shader) {};
		virtual			~IGLObject(void) {};

		virtual void	draw(void) = 0;

	protected:
		Model3D	&			_model3D;
		Camera	&			_camera;
		GLShader const *	_shader;

	private:
		IGLObject(void);
};

#endif /* ! IGLOBJECT_CLASS_HPP */
