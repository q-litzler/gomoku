/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserTGA.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 14:44:53 by qlitzler          #+#    #+#             */
/*   Updated: 2015/12/29 13:02:43 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSERTGA_CLASS_HPP
# define PARSERTGA_CLASS_HPP

# include <iostream>

struct		s_img
{
	char			id_length;
	char			color_map_type;
	char			data_type_code;
	short int		color_map_origin;
	short int		color_map_length;
	char			color_map_depth;
	short int		x_origin;
	short int		y_origin;
	short			width;
	short			height;
	char			bits_per_pixel;
	char			image_descriptor;
};

class ParserTGA
{
	public:
		ParserTGA(char const * path);
		~ParserTGA(void);

		void				freeImage(void);
		short				getWidth(void) const;
		short				getHeight(void) const;
		unsigned char *		getImage(void) const;


	private:
		void				initImage(s_img *header, FILE *fp);
		unsigned char *		readTga(FILE *fp, short int *w, short int *h);

		s_img				_img;
		FILE *				_src;
		unsigned char *		_image;
};

#endif /* ! PARSERTGA_CLASS_HPP */
