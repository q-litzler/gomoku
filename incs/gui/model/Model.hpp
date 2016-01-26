/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:00:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:32:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL_CLASS_HPP
# define MODEL_CLASS_HPP

# include <libs/glfw/glfw3.h>
# include <libs/glm/glm.hpp>
# include <libs/glm/gtc/matrix_transform.hpp>

class Model
{
	public:
		Model(GLfloat const & scale, GLfloat const & rotation);
		virtual ~Model(void);

		virtual glm::mat4	getMatrix(void) const = 0;
		glm::mat4			getProjection(void) const;
		glm::vec3			getLightPosition(void) const;


	private:
		Model(void);

	protected:
		GLfloat	const	_originScale;
		GLfloat const	_originRotation;
		GLfloat			_scale;			
		GLfloat			_rotation;
		glm::mat4		_projection;
		glm::vec3		_lightPosition;
};

#endif /* ! MODEL_CLASS_HPP */

