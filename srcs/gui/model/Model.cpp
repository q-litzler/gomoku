/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:00:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:32:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/model/Model.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

Model::Model(GLfloat const & scale, GLfloat const & rotation):
_originScale(scale), _originRotation(rotation), _scale(scale), _rotation(rotation)
{
	
}

Model::~Model(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

glm::vec3	Model::getLightPosition(void) const { return _lightPosition; }
glm::mat4	Model::getProjection(void) const { return _projection; }

/*******************************************
	Member functions
*******************************************/


