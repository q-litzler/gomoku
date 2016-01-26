/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShaderBoard.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:35:00 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:49:49 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSBOARD_CLASS_HPP
# define GLSBOARD_CLASS_HPP

# include <gui/opengl/shader/GLShader.hpp>

struct GLSBoard: public GLShader
{
	public:
		GLSBoard(GLuint const & id);
		virtual ~GLSBoard(void);

		GLuint const		vertexPosition;
		GLuint const		vertexNormal;
		GLuint const		vertexTexture;
		GLuint const		vertexMaterial;
		GLuint const		matrixModel;
		GLuint const		matrixView;
		GLuint const		matrixProjection;
		GLuint const		matrixCamera;
		GLuint const		lightPosition;
		GLuint const		lightAmbient;
		GLuint const		lightDiffuse;
		GLuint const		lightSpecular;
		GLuint const		lightCoefficient;
		GLuint const		lightShininess;
		GLuint const		lightAttenuation;		
};

#endif /* ! GLSBOARD_CLASS_HPP */
