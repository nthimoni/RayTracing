/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point3.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:19:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/22 03:35:10 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point3.hpp"
#include "Tup3.hpp"
#include "Vec3.hpp"

Point3::Point3(const unit x, const unit y, const unit z) : Tup3{x, y, z} {}

void Point3::log(const char* name) const
{
	if (name)
		std::clog << name << " " << "(Point3) : ";
	else
		std::clog << "Point3 : ";
	std::clog << x << " " << y << " " << z << std::endl;
}

Vec3 Point3::operator-(const Point3& rhs) const
{
	return Vec3{x - rhs.x, y - rhs.y, z - rhs.z};
}

bool Point3::operator==(const Point3& rhs) const
{
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

bool Point3::operator!=(const Point3& rhs) const
{
	return x != rhs.x || y == rhs.y || z == rhs.z;
}

Point3 Point3::operator+(const Vec3& rhs) const
{
	return Point3{x + rhs.x, y + rhs.y, z + rhs.z};
}

Point3 Point3::operator-(const Vec3& rhs) const
{
	return Point3{x - rhs.x, y - rhs.y, z - rhs.z};
}

Point3& Point3::operator+=(const Vec3& rhs)
{
	x += rhs.x;	
	y += rhs.y;	
	z += rhs.z;	

	return *this;
}
