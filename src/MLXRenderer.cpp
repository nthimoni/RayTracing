/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MLXRenderer.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:02:38 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/31 03:59:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLXRenderer.hpp"
#include "mlx.h"
#include <cstdio>

MLXRenderer::MLXRenderer(int width, int height, const char* title) 
						:_title(title), _width(width), _height(height),
						_buffer(width, height, _mlx_ptr),
						_next(width, height, _mlx_ptr){}


MLXRenderer::~MLXRenderer()
{
	mlx_destroy_window(_mlx_ptr, _mlx_win);
	mlx_destroy_display(_mlx_ptr);
	free(_mlx_ptr);
}

bool MLXRenderer::isInit() const
{
	return _mlx_ptr && _mlx_win && _buffer.init() && _next.init();
}

void MLXRenderer::clear()
{
	_nbSamples = 0;
	_buffer.clear();
	_next.clear();
}

void MLXRenderer::fillSample(int x, int y, const Color& color, int spp)
{
	_next.setPixel(x, y, color, spp);
}

void MLXRenderer::render()
{
	int count = 0;
	Color tmp;
	for (int x = 0; x < _width; x++)
	{
		for (int y = 0; y < _height; y++)
		{
			tmp = _buffer.getPixel(x, y) * _nbSamples;
			tmp += _next.getPixel(x, y);
			if (_buffer.getPixel(x, y).toInt(1) != tmp.toInt(_nbSamples + 1))
				count++;
			_buffer.setPixel(x, y, (tmp *(1/ (_nbSamples + 1.0))), 1);
		}
	}
	std::cerr << "Changes : " << count << std::endl;
	mlx_put_image_to_window(_mlx_ptr, _mlx_win, _buffer.getImg(), 0, 0);
	_nbSamples++;
}
