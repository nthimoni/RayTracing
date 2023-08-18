/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:40:47 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/12 17:41:38 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_HPP
# define RAYTRACING_HPP 

# include <cmath>
# include <random>
# include <iostream>
# include <iomanip>

using unit = double;

// GENERAL
constexpr int maxDepth = 50;
constexpr int spp = 1;
constexpr int threadCount = 40;

// IMG
constexpr unit ratio = 16.0 / 9.0;
constexpr int image_width = 800;
constexpr int image_height = static_cast<int>(image_width / ratio);


constexpr unit infinity = std::numeric_limits<unit>::infinity();
constexpr unit delta = 1e-8;

inline unit degreesToRadians(const unit degrees)
{
	return degrees * M_PI / 180.0;
}

inline static unit random_unit() {
	static std::random_device rd;
    static std::mt19937 generator(rd());
    static std::uniform_real_distribution<unit> distribution(0.0, 0.99999999999);
    return distribution(generator);
}

inline unit random_unit(unit min, unit max)
{
    return min + (max-min) * random_unit();
}

inline unit clamp(unit x, unit min, unit max)
{
	if (x > max)
		return max;
	if (x < min)
		return min;
	return x;
}

#endif 
