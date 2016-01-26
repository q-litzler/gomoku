/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSFont.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:35:00 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:49:49 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSHFONT_CLASS_HPP
# define GLSHFONT_CLASS_HPP

# include <gui/opengl/shader/GLShader.hpp>

struct GLSFont: public GLShader
{
	public:
		GLSFont(GLuint const & id);
		virtual ~GLSFont(void);

		GLuint const		vertexPosition;
		GLuint const		vertexTexture;
		GLuint const		vertexMaterial;
		GLuint const		matrixProjection;
		GLuint const		fragmentTexture;
		GLuint const		fragmentColor;
};

#endif /* ! GLSHFONT_CLASS_HPP */
