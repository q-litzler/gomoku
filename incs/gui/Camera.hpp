/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:06:09 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:51:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_CLASS_HPP
# define CAMERA_CLASS_HPP

#include <libs/glfw/glfw3.h>
#include <libs/glm/glm.hpp>
#include <libs/glm/gtc/matrix_transform.hpp>
#include <libs/glm/gtc/type_ptr.hpp>

class Camera
{
	public:
		Camera(glm::vec3 const & postion);
		~Camera(void);
		glm::mat4		getLookAt(void) const;
		void			setPosition(glm::vec3 position);
		glm::vec3		getPosition() const ;
		void			setTarget(glm::vec3 position);
		void			move(glm::vec3 position);

	private:

		glm::vec3		_position;
		glm::vec3		_distance;
		glm::vec3		_target;
		glm::vec3		_axis;
		glm::vec3 		_right;
		glm::vec3 		_up;
		glm::vec3 		_camDown;
		glm::mat4		_lookAt;

};

#endif /* ! CAMERA_CLASS_HPP */
