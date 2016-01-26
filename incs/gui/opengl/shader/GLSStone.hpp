/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLSStone.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 14:48:22 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/31 14:03:24 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSSTONE_CLASS_HPP
# define GLSSTONE_CLASS_HPP

# include <gui/opengl/shader/GLShader.hpp>

struct GLSStone: public GLShader
{
	public:
		GLSStone(GLuint const & id);
		virtual ~GLSStone(void);

		GLuint const		vertexPosition;
		GLuint const		vertexNormal;
		GLuint const		vertexColor;
		GLuint const		vertexInstance;
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

#endif /* ! GLSSTONE_CLASS_HPP */
