/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 00:22:15 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/22 03:02:32 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ray.hpp"
#include "Point3.hpp"

Ray::Ray(const Point3& point, const Vec3& direction)
	: _ori(point), _dir(direction) {}

Point3 Ray::at(unit t) const
{
	return _ori + (_dir * t);
}

Point3 Ray::origin() const
{
	return _ori;
}

Vec3 Ray::direction() const
{
	return _dir;
}
