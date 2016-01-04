/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLBoard.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 20:28:49 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 16:40:06 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLBOARD_CLASS_HPP
# define GLBOARD_CLASS_HPP

# include <libs/glm/gtc/type_ptr.hpp>

# include <gui/opengl/object/GLObject.hpp>

class GLBoard: public GLObject
{
	public:
		GLBoard(Model3D & model3D, Camera & camera, GLShader const * shader);
		virtual ~GLBoard(void);

		virtual void			draw(void);

	private:
		void					indexing(void);
		void					generate(void);

		GLuint					_tbo;
		GLuint					_pbo;
};

#endif /* ! GLBOARD_CLASS_HPP */
