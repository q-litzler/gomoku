/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLFont.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 15:15:58 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:43:28 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/opengl/object/GLFont.hpp>
#include <libs/font/ft2build.h>
#include FT_FREETYPE_H

/*******************************************
	Constructors - Destructor
*******************************************/

GLFont::GLFont(Model2D & model2D, GLSFont const * shader, int const & fontSize):
	_model2D(model2D), _shader(shader)
{
	generate();
	freetype(fontSize);
}

GLFont::~GLFont(void)
{
	glDeleteVertexArrays(1, &_vao);
	glDeleteBuffers(1, &_vbo);
	delete &_model2D;
}

/*******************************************
	Accessors
*******************************************/



/*******************************************
	Member functions
*******************************************/

void			GLFont::freetype(int const & fontSize)
{
	FT_Library	ft;
	FT_Face		face;

	if (FT_Init_FreeType(&ft)) {
		throw std::exception();
	}
	if(FT_New_Face(ft, "assets/fonts/Roboto-regular.ttf", 0, &face)) {
		throw std::exception();
	}
	FT_Set_Pixel_Sizes(face, 0, fontSize);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	for (GLubyte c = 0; c < 128; c++)
	{
		FT_GlyphSlot	g;
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			throw std::exception();
			continue;
		}
		g = face->glyph;
		GLuint			tbo;
		glGenTextures(1, &tbo);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, tbo);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, g->bitmap.width, g->bitmap.rows, 0, GL_RED, GL_UNSIGNED_BYTE, g->bitmap.buffer);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		e_character	character = {
			tbo, 
			glm::ivec2(g->bitmap.width, g->bitmap.rows),
			glm::ivec2(g->bitmap_left, g->bitmap_top),
			static_cast<GLuint>(g->advance.x)
		};
		_characters.insert(std::pair<GLchar, e_character>(c, character));
	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
}

void			GLFont::generate(void)
{
	glGenVertexArrays(1, &_vao);
	glBindVertexArray(_vao);

	GLObject::generateBO(_vbo, 6 * 4, GL_DYNAMIC_DRAW);

	GLObject::setBO(_vbo, _shader->vertexPosition, RGBA);
}

void			GLFont::uniforms(glm::vec3 const & color) const
{
	glUniformMatrix4fv(_shader->matrixProjection, 1, GL_FALSE, glm::value_ptr(_model2D.getProjection()));
	glUniform3fv(_shader->fragmentColor, 1, glm::value_ptr(color));
	glUniform1i(_shader->vertexMaterial, 1);
}

void			GLFont::draw(std::string const & text, GLfloat const & x, GLfloat const & y, GLfloat const & scale, glm::vec3 const & color) const
{
	_shader->use();
	uniforms(color);
	glBindVertexArray(_vao);

	GLfloat		_x = x;

	std::string::const_iterator c;
    for (c = text.begin(); c != text.end(); ++c)
    {
		e_character ch = _characters.at(*c);

		GLfloat xpos = _x + ch.bearing.x * scale;
		GLfloat ypos = y - (ch.size.y - ch.bearing.y) * scale;

		GLfloat w = ch.size.x * scale;
		GLfloat h = ch.size.y * scale;
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		glBindTexture(GL_TEXTURE_2D, ch.textureID);
		glBindBuffer(GL_ARRAY_BUFFER, _vbo);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);

		draw();
		_x += (ch.advance >> 6) * scale;
	}
}

void			GLFont::rotate(GLfloat const & angle)
{
	(void)angle;
}

void			GLFont::move(glm::vec3 const & position)
{
	(void)position;
}

void			GLFont::scale(GLfloat const & delta)
{
	(void)delta;
}

void			GLFont::reset(void)
{
	
}

void			GLFont::draw(void) const
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisable(GL_BLEND);
}

