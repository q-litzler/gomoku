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

# include <iostream>

# include <libs/GL/glew.h>
# include <libs/glm/gtc/type_ptr.hpp>

# include <gui/opengl/shader/GLSStone.hpp>
# include <gui/opengl/object/GLparser.hpp>
# include <gui/opengl/object/IGLObject.hpp>
# include <gui/opengl/object/GLObject.hpp>

# define UNIT 0.582492f
# define MAX_STONES 19 * 19

class GLStone: public IGLObject
{
	public:
		GLStone(Model3D & model3D, Camera & camera, GLSStone const * shader, char const * objFile);
		virtual ~GLStone(void);

		virtual void			draw(void) const;
		virtual void			rotate(GLfloat const & angle);
		virtual void			move(glm::vec3 const & position);
		virtual void			scale(GLfloat const & delta);
		virtual void			reset(void);
		void					add(int const & x, int const & z, GLfloat const & alpha);
		void					clear(void);

	private:
		void					uniforms(void) const;
		void					generateCBO(void);
		void					indexing(void);
		void					generate(void);

		Model3D &				_model3D;
		Camera &				_camera;
		GLSStone const *		_shader;
		int						_instances;
		s_obj					_obj;
		s_mtl					_mtl;

		GLuint					_vao;
		GLuint					_vbo;
		GLuint					_nbo;
		GLuint					_cbo;
		GLuint					_ibo;
};

#endif /* ! GLSTONE_CLASS_HPP */