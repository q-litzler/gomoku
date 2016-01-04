/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model3D.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 23:59:56 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/29 15:34:45 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL3D_CLASS_HPP
# define MODEL3D_CLASS_HPP

# include <libs/glfw/glfw3.h>
# include <libs/glm/glm.hpp>
# include <libs/glm/gtc/matrix_transform.hpp>

class Model3D
{
	public:
		Model3D(GLfloat const & scale, GLfloat const & rotation);
		~Model3D(void);

		glm::mat4		getMatrix(void) const;
		glm::mat4		getProjection(void) const;
		glm::vec3		getLightPosition(void) const;

		void			setScale(float delta);
		void			setRotation(GLfloat angle);

	private:
		Model3D(void);

		GLfloat			_scale;			
		GLfloat			_rotation;
		glm::mat4		_projection;
		glm::vec3		_lightPosition;

};

#endif /* ! MODEL3D_CLASS_HPP */
