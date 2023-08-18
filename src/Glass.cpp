/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Glass.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 16:41:37 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/18 19:22:41 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Glass.hpp"
#include "Ray.hpp"
#include "Vec3.hpp"

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
	if (cantRefract)
		newDirection = direction.reflect(inter.normal);
	else
		newDirection = direction.refract(inter.normal, refractionRatio);

	scattered = Ray(inter.pos, newDirection);

	return true;
}
