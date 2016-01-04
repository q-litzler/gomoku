/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShader.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:57:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 20:01:13 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <gui/opengl/shader/GLShader.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLShader::GLShader(char const * fileVertex, char const * fileFragment)
{
	_id = glCreateProgram();
	compile(_vertex, fileVertex, GL_VERTEX_SHADER);
	compile(_fragment, fileFragment, GL_FRAGMENT_SHADER);
	glLinkProgram(_id);
}

GLShader::~GLShader(void)
{
	
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

GLuint		GLShader::getPosition(void) const {
	return _attr.vertex.position;
}

GLuint		GLShader::getColor(void) const {
	return _attr.vertex.color;
}

GLuint		GLShader::getNormal(void) const {
	return _attr.vertex.normal;
}

GLuint		GLShader::getTexture(void) const {
	return _attr.vertex.texture;
}

GLuint		GLShader::getMaterial(void) const {
	return _attr.vertex.material;
}

GLuint		GLShader::getInstance(void) const {
	return _attr.vertex.instance;
}

void		GLShader::uniforms(Model3D const & model3D, Camera const & camera, s_mtl const & mtl) const
{
	glUniform3fv(_attr.matrix.camera, 1, glm::value_ptr(camera.getPosition()));
	glUniformMatrix4fv(_attr.matrix.view, 1, GL_FALSE, glm::value_ptr(camera.getLookAt()));
	glUniformMatrix4fv(_attr.matrix.model, 1, GL_FALSE, glm::value_ptr(model3D.getMatrix()));
	glUniformMatrix4fv(_attr.matrix.projection, 1, GL_FALSE, glm::value_ptr(model3D.getProjection()));
	glUniform3fv(_attr.light.position, 1, glm::value_ptr(model3D.getLightPosition()));
	glUniform3fv(_attr.light.ambient, 1, glm::value_ptr(mtl.ambient));
	glUniform3fv(_attr.light.diffuse, 1, glm::value_ptr(mtl.diffuse));
	glUniform3fv(_attr.light.specular, 1, glm::value_ptr(mtl.specular));
	glUniform1f(_attr.light.shininess, 25.0f);
	glUniform1f(_attr.light.coefficient, 1.0f);
	glUniform1f(_attr.light.attenuation, 0.0f);
}

void		GLShader::use(void) const
{
	glUseProgram(_id);
}

void		GLShader::freeResources(void)
{
	glDeleteProgram(_id);
	glDeleteShader(_vertex);
	glDeleteShader(_fragment);
}

FILE *		GLShader::readFile(char const *path)
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

void		GLShader::readShader(GLint const & shader, char const * file) {
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

void		GLShader::compile(GLuint & program, char const * file, GLenum const & type)
{
	program = glCreateShader(type);
	readShader(program, file);
	glCompileShader(program);
	checkStatus(program);
	glAttachShader(_id, program);
}

void		GLShader::checkStatus(GLuint & program)
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
