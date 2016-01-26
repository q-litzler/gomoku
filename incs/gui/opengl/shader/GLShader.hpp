/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLShader.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 19:56:50 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:30:08 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLSHADER_CLASS_HPP
# define GLSHADER_CLASS_HPP

# include <libs/glfw/glfw3.h>

struct GLShader
{
	public:
		GLShader(GLuint const & id);
		virtual ~GLShader(void);

		void				use(void) const;

	protected:

		GLuint const		_id;

	private:

};

#endif /* ! GLSHADER_CLASS_HPP */
