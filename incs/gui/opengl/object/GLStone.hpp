/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLStone.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 17:06:08 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/01 16:23:11 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSTONE_CLASS_HPP
# define GLSTONE_CLASS_HPP

# include <gui/opengl/object/GLObject.hpp>

# define UNIT 0.582492f
# define MAX_STONES 19 * 19

class GLStone: public GLObject
{
	public:
		GLStone(Model3D & model3D, Camera & camera, GLShader const * shader, char const * objFile);
		virtual ~GLStone(void);

		virtual void			draw(void);
		void					add(int const & x, int const & z, GLfloat const & alpha);
		void					clear(void);

	private:
		int						_instances;
		void					generateCBO(void);
		void					indexing(void);
		void					generate(void);

		GLuint					_cbo;
		GLuint					_ibo;
};

#endif /* ! GLSTONE_CLASS_HPP */