/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Img.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 06:14:52 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/31 05:41:25 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Img.hpp"
#include "mlx.h"
#include <cstring>
#include <vector>

Img::Img(int width, int height, void* mlx_ptr) :
	width(width), height(height), _mlx_ptr(mlx_ptr), _tab(width)
{
	for (int i = 0; i < width;i++)
		for (int u = 0; u < height; u++)
			_tab[i].push_back({0, 0, 0});
	std::cout <<"size: " <<  _tab.size() << " " << _tab[0].size() << std::endl;
}

Img::~Img()
{
	//mlx_destroy_image(_mlx_ptr, _img);
}

void Img::setPixel(int x, int y, const Color& color, int spp)
{
	_tab[x][y] = color * (1.0 / spp);

	//char *dst = _addr + (y * _line_length + x * (_bpp / 8));
	//*(unsigned int*)dst = color.toInt(spp);
}

Color Img::getPixel(int x, int y)
{
	return _tab[x][y];
	//char *dst = _addr + (y * _line_length + x * (_bpp / 8));
	//return Color(*(unsigned int*)dst);
}

void Img::clear()
{
	std::memset(_addr, 0, width * height * (_bpp / 8));
}

bool Img::init() const
{
	return _mlx_ptr && _img;
}

void* Img::getImg() const
{
	for (int i = 0; i < width; i++)
	{
		for (int j = 0; j < height; j++)
		{
			char *dst = _addr + (j * _line_length + i * (_bpp / 8));
			*(unsigned int*)dst = _tab[i][j].toInt(1);
		}
	}
	return _img;
}
