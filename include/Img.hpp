/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Img.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 05:54:40 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/06 22:01:14 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMG_HPP
# define IMG_HPP 

#include "mlx.h"
#include "Color.hpp"
#include <array>

class Img
{
	public:
		Img() = delete;
		Img(const Img& ent) = delete;
		Img(int width, int height, void* mlx_ptr);
		~Img();

		void setPixel(int x, int y, const Color& color, int spp);
		Color getPixel(int x, int y);
		void clear();
		bool init() const;
		void* getImg() const;

		Img& operator=(const Img& ent) = delete;

		const int width = 400;
		const int height = 400;
	private:
		void *_mlx_ptr;
		void* _img = mlx_new_image(_mlx_ptr, width, height);
		int _bpp = 0;
		int _line_length = 0;
		int _endian = 0;
		char *_addr = mlx_get_data_addr(_img, &_bpp, &_line_length, &_endian);
		std::vector<std::vector<Color>> _tab{(unsigned long)width, {height}};
};

#endif 
