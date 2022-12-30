/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Metal.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:57:27 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/29 03:26:58 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Metal.hpp"


Metal::Metal(const Color& color) : _color(color) {}


bool Metal::scatter(const Ray& in, const Inter& inter,
		Color& attenuation, Ray& scattered) const
{
	Vec3 reflected = in.direction().reflect(inter.normal).getUnitVec();
	scattered = Ray(inter.pos, reflected);
	attenuation = _color;
	return (scattered.direction().dot(inter.normal) > 0);
}
