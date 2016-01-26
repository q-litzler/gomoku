/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model3D.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 23:59:56 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/29 15:34:45 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL3D_CLASS_HPP
# define MODEL3D_CLASS_HPP

# include <gui/model/Model.hpp>

class Model3D: public Model
{
	public:
		Model3D(GLfloat const & scale, GLfloat const & rotation);
		virtual ~Model3D(void);

		virtual glm::mat4	getMatrix(void) const;

		void				rotate(GLfloat const & angle);
		void				scale(GLfloat const & delta);
		void				reset(void);

		static Model3D *	newInstance(void);

	private:
		Model3D(void);

};

#endif /* ! MODEL3D_CLASS_HPP */
