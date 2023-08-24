/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Glass.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:41:37 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/24 19:24:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Glass.hpp"
#include "raytracing.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"
#include <cmath>

static inline unit reflectance(unit cosine, unit refIdx);

Glass::Glass(unit indexOfRefraction) : _indexOfRefraction(indexOfRefraction) {}

bool Glass::scatter(const Ray& in, const Inter& inter,
		Color& attenuation, Ray& scattered) const
{
	attenuation = Color(1.0, 1.0, 1.0);
	unit refractionRatio = inter.frontFace ? (1.0/_indexOfRefraction) : _indexOfRefraction;

	Vec3 direction = in.direction().getUnitVec();

	unit cosTheta = fmin((-direction).dot(inter.normal), 1.0);
	unit sinTheta = sqrt(1.0 - cosTheta * cosTheta);

	bool cantRefract = refractionRatio * sinTheta > 1.0;

	Vec3 newDirection;
	if (cantRefract || reflectance(cosTheta, refractionRatio) > random_unit())
		newDirection = direction.reflect(inter.normal);
	else
		newDirection = direction.refract(inter.normal, refractionRatio);

	scattered = Ray(inter.pos, newDirection);

	return true;
}

static inline unit reflectance(unit cosine, unit refIdx)
{
	auto r0 = (1 - refIdx) / (1 + refIdx);
	r0 *= r0;
	return r0 + (1 - r0) * pow((1 - cosine), 5);
}
