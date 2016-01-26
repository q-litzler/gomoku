/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model2D.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:00:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:32:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/model/Model2D.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Model2D::Model2D(GLfloat const & scale, GLfloat const & rotation):
Model(scale, rotation)
{
	_projection = glm::ortho(0.0f, 800.0f, 0.0f, 600.0f);
}

Model2D::~Model2D(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

glm::mat4	Model2D::getMatrix(void) const
{
	return glm::mat4();
}


/*******************************************
	Member functions
*******************************************/


/*******************************************
	Non-Member functions
*******************************************/

Model2D *	Model2D::newInstance(void)
{
	return new Model2D(0.0f, 0.0f);
}