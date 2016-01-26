/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLObject.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:16:28 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/01 16:23:28 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLObject.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLObject::~GLObject(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Non-Member functions
*******************************************/

void			GLObject::indexingBO(std::vector<GLfloat> & bo, std::vector<GLuint> & ebo, e_dimension const & dimensions)
{
	std::vector<GLfloat>			copy;
	std::vector<GLuint>::iterator	it;

	for (it = ebo.begin(); it != ebo.end(); ++it)
	{
		for (int i = 0; i < dimensions; ++i)
		{
			copy.push_back(bo[*it * dimensions + i]);
		}
	}
	bo = copy;
}

void			GLObject::generateBO(GLuint & buffer, std::vector<GLfloat> const & bo, int const & size, GLenum type)
{
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), &bo[0], type);
}

void			GLObject::generateBO(GLuint & buffer, int const & size, GLenum type)
{
	glGenBuffers(1, &buffer);
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(GLfloat), nullptr, type);
}

void			GLObject::setBO(GLuint const & bo, GLint const & sbo, e_dimension const & dimension)
{
	glBindBuffer(GL_ARRAY_BUFFER, bo);
	glVertexAttribPointer(sbo, dimension, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(sbo);
}
