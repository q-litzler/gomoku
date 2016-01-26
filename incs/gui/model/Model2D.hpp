/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Model2D.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 00:00:04 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:32:02 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MODEL2D_CLASS_HPP
# define MODEL2D_CLASS_HPP

# include <gui/model/Model.hpp>

class Model2D: public Model
{
	public:
		Model2D(GLfloat const & scale, GLfloat const & rotation);
		virtual ~Model2D(void);

		virtual glm::mat4	getMatrix(void) const;

		static Model2D *	newInstance(void);

	private:
		Model2D(void);

};

#endif /* ! MODEL2D_CLASS_HPP */
