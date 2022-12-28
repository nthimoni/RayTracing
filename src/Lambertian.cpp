/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lambertian.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:42:59 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 21:22:46 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lambertian.hpp"
#include "Color.hpp"
#include "Ray.hpp"

Lambertian::Lambertian(const Color& col) : _color(col) {};

bool Lambertian::scatter(const Ray& in, const Inter& inter,
		Color& attenuation, Ray& scattered) const
{
	(void)in;
	Vec3 scatterDirection = inter.normal + inter.randomInUnitSphere().getUnitVec();

	if (scatterDirection.nearZero())
		scatterDirection = inter.normal;

	scattered = Ray(inter.pos, scatterDirection);
	attenuation = _color;
	return true;
}
