/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lambertian.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:42:59 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 06:28:28 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lambertian.hpp"
#include "Color.hpp"
#include "Ray.hpp"

Lambertian::Lambertian(const Color& col) : color(col) {};

bool Lambertian::scatter(const Ray& in, const Inter& inter,
		Color& attenuation, Ray& scattered) const
{
	(void)in;
	Vec3 scatterDirection = inter.normal + inter.randomInUnitSphere().getUnitVec();
	scattered = Ray(inter.pos, scatterDirection);
	attenuation = color;
	return true;
}
