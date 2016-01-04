/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLParser.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:49:33 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:17 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLPARSER_CLASS_HPP
# define GLPARSER_CLASS_HPP

# define N_REGEX_OBJ	9
# define N_REGEX_MTL	7
# define N_EBO			3

# include <fstream>
# include <regex>
# include <map>

# include <libs/glfw/glfw3.h>
# include <libs/glm/glm.hpp>

struct	s_regex;

struct s_mtl
{
	glm::vec3				diffuse;
	glm::vec3				ambient;
	glm::vec3				filter;
	glm::vec3				specular;
	GLfloat					refraction;
	GLuint					illumination;
};

struct s_obj
{
	std::vector<GLfloat>	vbo;
	std::vector<GLfloat>	pbo;
	std::vector<GLfloat>	nbo;
	std::vector<GLfloat>	cbo;
	std::vector<GLfloat>	ibo;
	std::vector<GLuint>		ebo[N_EBO];
	std::string				usemtl;
	std::string				name;
};

class GLParser
{

	public:
		GLParser(char const * path);
		~GLParser(void);

		s_mtl	getMtl(void);
		s_obj	getObj(void) const;

	private:
		void	parse(int const & n_regex, std::ifstream & file, s_regex const regex[]);
		void	parseObj(int const & i, s_regex const regex[], std::smatch const & captured);
		void	checkPath(char const * path, std::ifstream & file);

		void	mtlPath(std::smatch const & captured);
		void	name(std::smatch const & captured);
		void	usemtl(std::smatch const & captured);
		void	newMtl(std::smatch const & captured);
		void	comment(std::smatch const & captured);
		void	smooth(std::smatch const & captured);
		void	VBO(std::smatch const & captured);
		void	NBO(std::smatch const & captured);
		void	PBO(std::smatch const & captured);
		void	EBO(std::smatch const & captured);
		void	ambient(std::smatch const & captured);
		void	diffuse(std::smatch const & captured);
		void	specular(std::smatch const & captured);
		void	filter(std::smatch const & captured);
		void	refraction(std::smatch const & captured);
		void	illumination(std::smatch const & captured);

		void	fill_bo(std::smatch const & captured, std::vector<GLfloat> & vector);
		void	fill_ebo(std::smatch const & captured);
		void	fill_light(std::smatch const & captured, glm::vec3 & vector);

		static const s_regex			regex_obj[N_REGEX_OBJ];
		static const s_regex			regex_mtl[N_REGEX_MTL];

		std::string						_mtlPath;
		std::ifstream					_fileObj;
		std::ifstream					_fileMtl;

		s_obj							_obj;
		std::map<std::string, s_mtl>	_mtls;
		std::string						_mtlActive;
};

struct	s_regex {
	std::regex const	pattern;
	void (GLParser::*f)(std::smatch const & captured);
};

#endif /* ! GLPARSER_CLASS_HPP */
