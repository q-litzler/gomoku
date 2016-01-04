/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserTGA.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qlitzler <qlitzler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 14:45:08 by qlitzler          #+#    #+#             */
/*   Updated: 2016/01/03 16:26:25 by qlitzler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gui/ParserTGA.hpp>
#include <libs/GL/glew.h>

/*******************************************
	Constructors - Destructor
*******************************************/

ParserTGA::ParserTGA(char const * path)
{
	_src = fopen(path, "r");
	if (_src == nullptr)
	{
		std::cerr << "tga exception" << std::endl;
		throw std::exception();
	}
	_image = readTga(_src, &_img.width, &_img.height);
	fclose(_src);
}

ParserTGA::~ParserTGA(void)
{
	
}

/*******************************************
	Accessors
*******************************************/

short				ParserTGA::getWidth(void) const { return _img.width; };
short				ParserTGA::getHeight(void) const { return _img.height; };
unsigned char *		ParserTGA::getImage(void) const { return _image; };


/*******************************************
	Member functions
*******************************************/

void				ParserTGA::freeImage()
{
	delete _image;
}

void				ParserTGA::initImage(s_img * header, FILE * fp)
{
	int				skipover;

	skipover = 0;
	header->id_length = fgetc(fp);
	header->color_map_type = fgetc(fp);
	header->data_type_code = fgetc(fp);
	fread(&header->color_map_origin, 2, 1, fp);
	fread(&header->color_map_length, 2, 1, fp);
	header->color_map_depth = fgetc(fp);
	fread(&header->x_origin, 2, 1, fp);
	fread(&header->y_origin, 2, 1, fp);
	fread(&header->width, 2, 1, fp);
	fread(&header->height, 2, 1, fp);
	header->bits_per_pixel = fgetc(fp);
	header->image_descriptor = fgetc(fp);
	skipover += header->id_length;
	skipover += header->color_map_type * header->color_map_length;
	fseek(fp, skipover, SEEK_CUR);
}

unsigned char *		ParserTGA::readTga(FILE * fp, short int * w, short int * h)
{
	unsigned char	*image;
	unsigned long	imagesize;
	int				pixelsize;

	initImage(&_img, fp);
	pixelsize = _img.bits_per_pixel / 8;
	imagesize = _img.width * _img.height * pixelsize;
	if ((image = (unsigned char *)malloc(imagesize)) == NULL)
	{
		printf("malloc of image failed\n");
		return (NULL);
	}
	if (fread(image, sizeof(unsigned char), imagesize, fp) != imagesize)
	{
		printf("Unexpected end of file\n");
		free(image);
		return (NULL);
	}
	*w = _img.width;
	*h = _img.height;
	return (image);
}


