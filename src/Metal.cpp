/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Metal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:57:27 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/31 17:26:35 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Metal.hpp"
#include "Vec3.hpp"


Metal::Metal(const Color& color, unit fuziness)
	: _color(color), _fuziness(fuziness < 1 ? fuziness : 1) {}


bool Metal::scatter(const Ray& in, const Inter& inter,
		Color& attenuation, Ray& scattered) const
{
	Vec3 reflected = in.direction().reflect(inter.normal).getUnitVec();
	scattered = Ray(inter.pos, reflected + Inter::randomInUnitSphere() * _fuziness);
	attenuation = _color;
	return (scattered.direction().dot(inter.normal) > 0);
}
