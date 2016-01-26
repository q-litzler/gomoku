/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSBuilder.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:57:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 20:01:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <gui/opengl/shader/GLSBuilder.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLSBuilder::GLSBuilder(char const * fileVertex, char const * fileFragment)
{
	_id = glCreateProgram();
	compile(_vertex, fileVertex, GL_VERTEX_SHADER);
	compile(_fragment, fileFragment, GL_FRAGMENT_SHADER);
	glLinkProgram(_id);
}

GLSBuilder::~GLSBuilder(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

GLuint		GLSBuilder::getId(void) const { return _id; }


/*******************************************
	Member functions
*******************************************/

void		GLSBuilder::freeResources(void)
{
	glDeleteProgram(_id);
	glDeleteShader(_vertex);
	glDeleteShader(_fragment);
}

FILE *		GLSBuilder::readFile(char const *path)
{
	FILE		*file;

	file = fopen(path, "r");
	if (!file)
	{
		std::cerr << path << " shader file exception" << std::endl;
		throw std::exception();
	}
	return (file);
}

void		GLSBuilder::readShader(GLint const & shader, char const * file) {
	struct stat		st;
	FILE			*src;
	GLchar			buff[2048];
	GLchar const	*ptr;

	bzero(buff, 2048);
	src = readFile(file);
	stat(file, &st);
	fread(buff, st.st_size, 1, src);
	ptr = buff;
	glShaderSource(shader, 1, &ptr, NULL);
	fclose(src);
}

void		GLSBuilder::compile(GLuint & program, char const * file, GLenum const & type)
{
	program = glCreateShader(type);
	readShader(program, file);
	glCompileShader(program);
	checkStatus(program);
	glAttachShader(_id, program);
}

void		GLSBuilder::checkStatus(GLuint & program)
{
	GLint	status;

	glGetShaderiv(program, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		char buffer[512];
		glGetShaderInfoLog(program, 512, NULL, buffer);
		std::cout << buffer << std::endl;
		throw std::exception();
	}
}

