/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLParser.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 22:49:52 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/06 22:31:58 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include <gui/opengl/object/GLParser.hpp>

/*******************************************
	Constructors - Destructor
*******************************************/

GLParser::GLParser(char const * path)
{
	std::stringstream	ss;

	checkPath(path, _fileObj);
	parse(N_REGEX_OBJ, _fileObj, GLParser::regex_obj);
	_fileObj.close();

	ss << "assets/mtl/" << _mtlPath;
	checkPath(ss.str().c_str(), _fileMtl);
	parse(N_REGEX_MTL, _fileMtl, GLParser::regex_mtl);
	_fileMtl.close();
}

GLParser::~GLParser(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

s_mtl		GLParser::getMtl(void)
{
	return _mtls[_mtlActive];
}

s_obj		GLParser::getObj(void) const
{
	return _obj;
}

/*******************************************
	Member functions
*******************************************/

void		GLParser::checkPath(char const * path, std::ifstream & file)
{
	file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	file.open(path);
	file.exceptions(std::ifstream::badbit);
}

void		GLParser::parse(int const & n_regex, std::ifstream & file, s_regex const regex[])
{
	std::string				line;

	while (std::getline(file, line))
	{
		for (int i = 0; i < n_regex; ++i)
		{
			auto begin = std::sregex_iterator(line.begin(), line.end(), regex[i].pattern);
			for (std::sregex_iterator it = begin; it != std::sregex_iterator(); ++it)
			{
				(this->*regex[i].f)(std::smatch(*it));
			}
		}
	}
}

void		GLParser::mtlPath(std::smatch const & captured)
{
	_mtlPath = captured[1];
}

void		GLParser::name(std::smatch const & captured)
{
	_obj.name = captured[1];
}

void		GLParser::usemtl(std::smatch const & captured)
{
	_obj.usemtl = captured[1];
}

void		GLParser::newMtl(std::smatch const & captured) {
	s_mtl	mtl;

	_mtlActive = captured[1];
	_mtls.insert(std::make_pair(_mtlActive, mtl));
}

void		GLParser::VBO(std::smatch const & captured)
{
	fill_bo(captured, _obj.vbo);
}

void		GLParser::NBO(std::smatch const & captured)
{
	fill_bo(captured, _obj.nbo);
}

void		GLParser::PBO(std::smatch const & captured)
{
	fill_bo(captured, _obj.pbo);
}

void		GLParser::EBO(std::smatch const & captured)
{
	fill_ebo(captured);
}

void		GLParser::ambient(std::smatch const & captured)
{
	fill_light(captured, _mtls[_mtlActive].ambient);
}

void		GLParser::diffuse(std::smatch const & captured)
{
	fill_light(captured, _mtls[_mtlActive].diffuse);
}

void		GLParser::specular(std::smatch const & captured)
{
	fill_light(captured, _mtls[_mtlActive].specular);
}

void		GLParser::filter(std::smatch const & captured)
{
	fill_light(captured, _mtls[_mtlActive].filter);
}

void		GLParser::refraction(std::smatch const & captured)
{
	_mtls[_mtlActive].refraction = std::atof(captured[1].str().c_str());
}

void		GLParser::illumination(std::smatch const & captured)
{
	_mtls[_mtlActive].illumination = std::atoi(captured[1].str().c_str());
}

void		GLParser::comment(std::smatch const & captured)
{
	(void)captured;
}

void		GLParser::smooth(std::smatch const & captured)
{
	(void)captured;
}

void		GLParser::fill_bo(std::smatch const & captured, std::vector<GLfloat> & vector)
{
	std::smatch::iterator	it;

	for (it = captured.begin() + 1; it != captured.end(); ++it)
	{
		vector.push_back(std::atof((*it).str().c_str()));
	}
}

void		GLParser::fill_ebo(std::smatch const & captured)
{
	std::string 			element;

	for (unsigned long i = 1; i < captured.size(); ++i)
	{
		std::istringstream	str(captured[i]);
		for(int j = 0; std::getline(str, element, '/'); ++j)
		{
			if (i == 4)
			{
				_obj.ebo[j].push_back(_obj.ebo[j][_obj.ebo[j].size() - 3]);
				_obj.ebo[j].push_back(_obj.ebo[j][_obj.ebo[j].size() - 2]);
			}
			_obj.ebo[j].push_back(std::atoi(element.c_str()) - 1);
		}
	}
}

void		GLParser::fill_light(std::smatch const & captured, glm::vec3 & vector)
{
	vector = glm::vec3(
		std::atof(captured[1].str().c_str()),
		std::atof(captured[2].str().c_str()),
		std::atof(captured[3].str().c_str())
	);
}

const s_regex		GLParser::regex_mtl[N_REGEX_MTL] = {
	{ std::regex("newmtl (\\w+)"), &GLParser::newMtl},
	{ std::regex("Kd ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::diffuse },
	{ std::regex("Ka ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::ambient },
	{ std::regex("Tf ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::filter },
	{ std::regex("Ks ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::specular },
	{ std::regex("Ni ([-]?\\d*[.]?\\d+)"), &GLParser::refraction },
	{ std::regex("illum (\\d+)"), &GLParser::illumination },
};

const s_regex		GLParser::regex_obj[N_REGEX_OBJ] = {
	{ std::regex("#.*"), &GLParser::comment },
	{ std::regex("mtllib (\\w+.mtl)"), &GLParser::mtlPath },
	{ std::regex("usemtl (\\w+)"), &GLParser::usemtl },
	{ std::regex("g (\\w+)"), &GLParser::name },
	{ std::regex("s (\\w+)"), &GLParser::smooth },
	{ std::regex("v ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::VBO },
	{ std::regex("vt ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::PBO },
	{ std::regex("vn ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+) ([-]?\\d*[.]?\\d+)"), &GLParser::NBO },
	{ std::regex("f (\\d+\\/\\d+\\/\\d+) (\\d+\\/\\d+\\/\\d+) (\\d+\\/\\d+\\/\\d+) ?(\\d+\\/\\d+\\/\\d+)?"), &GLParser::EBO }
};

