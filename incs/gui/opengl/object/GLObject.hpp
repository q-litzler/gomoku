/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLObject.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:15:58 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:43:28 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBJECT_CLASS_HPP
# define GLOBJECT_CLASS_HPP

# include <vector>
# include <libs/glfw/glfw3.h>

enum e_bo
{
	VBO = 0,
	PBO,
	NBO,
};

enum e_dimension
{
	UV = 2,
	XYZ,
	RGBA
};

class GLObject
{
	public:
		~GLObject(void);
		static void			indexingBO(std::vector<GLfloat> & bo, std::vector<GLuint> & ebo, e_dimension const & dimensions);
		static void			generateBO(GLuint & buffer, std::vector<GLfloat> const & bo, int const & size, GLenum type);
		static void			generateBO(GLuint & buffer, int const & size, GLenum type);
		static void			setBO(GLuint const & bo, GLint const & sbo, e_dimension const & dimension);

	private:
		GLObject(void);
		
};

#endif /* ! GLOBJECT_CLASS_HPP */
