/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model3D.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:00:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:32:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <gui/model/Model3D.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Model3D::Model3D(GLfloat const & scale, GLfloat const & rotation):
Model(scale, rotation)
{
	_projection = glm::perspective(
		glm::radians(45.0f),
		1920.0f / 1080.0f,
		1.0f, 150.0f
	);
	_lightPosition = glm::vec3(5.0f, 10.0f, 0.0f);
	return;
}

Model3D::~Model3D(void)
{
	return;
}

/*******************************************
	Accessors
*******************************************/


glm::mat4	Model3D::getMatrix(void) const
{
	return
	glm::rotate(
		glm::mat4(1.0f),
		_rotation,
		glm::vec3(0.0f, 1.0f, 0.0f)
	) *
	glm::scale(
		glm::mat4(1.0f), 
		glm::vec3(_scale, _scale, _scale)
	) *
	glm::translate(
		glm::mat4(1.0f), 
		glm::vec3(0.0f, 0.0f, 0.0f)
	);
}

/*******************************************
	Member functions
*******************************************/

void		Model3D::reset(void)
{ 
	_rotation = _originRotation;
	_scale = _originScale;
}

void		Model3D::rotate(GLfloat const & angle)
{
	_rotation += angle;
}

void		Model3D::scale(GLfloat const & delta)
{
	_scale *= delta;
}

/*******************************************
	Non-Member functions
*******************************************/

Model3D *	Model3D::newInstance(void)
{
	return new Model3D(1.0f, 44.0f);
}