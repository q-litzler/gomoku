/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:07:04 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:51:01 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/Camera.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Camera::Camera(glm::vec3 const & position) : _position(glm::vec3(0.0f, 0.0f, 0.0f)) 
{
	_distance = glm::vec3(0.0f, 0.0f, 0.0f);
	_target = glm::vec3(0.0f, 0.0f, 0.0f);
	_axis = glm::normalize(_position - _target);
	_right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0, 0.0f), _axis));
	_up = glm::cross(_axis, _right);
	_lookAt = glm::mat4();
	setPosition(position);
}

Camera::~Camera(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

glm::vec3		Camera::getPosition(void) const
{
	return _position;
}

glm::mat4		Camera::getLookAt(void) const
{
	return glm::lookAt(_position, _target, _up);
}

void			Camera::setPosition(glm::vec3 position)
{
	_position = position;
	_axis = glm::normalize(_position - _target);
	_right = glm::normalize(glm::cross(glm::vec3(0.0f, 1.0, 0.0f), _axis));
	_up = glm::cross(_axis, _right);
}

void			Camera::setTarget(glm::vec3 target)
{
	_target = target;
}

/*******************************************
	Member functions
*******************************************/

void			Camera::move(glm::vec3 position)
{
	_position -= position;
	setPosition(_position);
}
