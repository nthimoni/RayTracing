/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:40:47 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 04:27:56 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYTRACING_HPP
# define RAYTRACING_HPP 

# include <cmath>
# include <random>
# include <iostream>
# include <iomanip>

using unit = double;

constexpr unit infinity = std::numeric_limits<unit>::infinity();

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
