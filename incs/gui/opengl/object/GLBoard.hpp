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

# include <libs/GL/glew.h>
# include <libs/glm/gtc/type_ptr.hpp>

# include <gui/opengl/shader/GLSBoard.hpp>
# include <gui/opengl/object/GLparser.hpp>
# include <gui/opengl/object/IGLObject.hpp>
# include <gui/opengl/object/GLObject.hpp>

class GLBoard: public IGLObject
{
	public:
		GLBoard(Model3D & model3D, Camera & camera, GLSBoard const * shader);
		virtual ~GLBoard(void);

		virtual void			draw(void) const;
		virtual void			rotate(GLfloat const & angle);
		virtual void			move(glm::vec3 const & position);
		virtual void			scale(GLfloat const & delta);
		virtual void			reset(void);

	private:
		void					indexing(void);
		void					generate(void);
		void					uniforms(void) const;

		Model3D &				_model3D;
		Camera &				_camera;
		GLSBoard const *		_shader;
		s_obj					_obj;
		s_mtl					_mtl;

		GLuint					_vao;
		GLuint					_vbo;
		GLuint					_nbo;
		GLuint					_pbo;
		GLuint					_tbo;
};

#endif /* ! GLBOARD_CLASS_HPP */
