/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MLXRenderer.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 04:29:17 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/06 21:18:12 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLXRENDERER_HPP
# define MLXRENDERER_HPP 

# include "mlx.h"
# include "Color.hpp"
# include "Img.hpp"
#include <memory>

class MLXRenderer
{
	public:
		MLXRenderer() = delete;
		MLXRenderer(int width, int height, const char* title = "Default");
		MLXRenderer(const MLXRenderer& ent) = delete;
		~MLXRenderer();

		bool isInit() const;
		void clear();
		void fillSample(int x, int y, const Color& color, int spp);
		void render();

		MLXRenderer& operator=(const MLXRenderer& ent) = delete;

	private:
		const char* _title = "Default";
		const int _width = 400;
		const int _height = 400;
		void* _mlx_ptr = mlx_init();
		void* _mlx_win = mlx_new_window(_mlx_ptr, _width, _height, (char *)_title);
		int _nbSamples = 0;
		Img _buffer{400, 400, _mlx_ptr};
		Img _next{400, 400, _mlx_ptr};
};

#endif 
