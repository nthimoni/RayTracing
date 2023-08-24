/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 22:22:15 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/24 17:41:16 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "Vec3.hpp"
#include "Point3.hpp"

Vec3::Vec3(const unit x, const unit y, const unit z) : Tup3(x, y ,z) {}

Vec3::Vec3(const Point3& src, const Point3& dst)
	: Tup3(dst.x - src.x, dst.y - src.y, dst.z - src.z) {}

unit Vec3::length() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
}

unit Vec3::lengthSquared() const
{
	return this->x * this->x + this->y * this->y + this->z * this->z;
}

void Vec3::norm()
{
	unit length = this->length();
	x /= length;
	y /= length;
	z /= length;
}

Vec3 Vec3::getUnitVec() const
{
	return *this / this->length();
}

void Vec3::log(const char* name) const
{
	if (name)
		std::clog << name << " " << "(Vec3) : ";
	else
		std::clog << "Vec3 : ";
	std::clog << x << " " << y << " " << z << std::endl;
}

unit Vec3::dot(const Vec3& ent) const
{
	return x * ent.x + y * ent.y + z * ent.z;
}

Vec3 Vec3::cross(const Vec3& ent) const
{
	return Vec3{y * ent.z - z * ent.y,
				z * ent.x - x * ent.z,
				x * ent.y - y * ent.x};
}

bool Vec3::nearZero() const
{
	return (std::abs(x) < delta && std::abs(y) < delta && std::abs(z) < delta);
}

Vec3 Vec3::reflect(const Vec3& n) const
{
	return *this - (n * 2 * this->dot(n));
}

Vec3 Vec3::refract(const Vec3& n, unit ir) const
{
	auto reverse = -(*this);
	auto cos_theta = fmin(reverse.dot(n), 1.0);
	Vec3 r_out_perp = (*this + (n * cos_theta)) * ir;
	Vec3 r_out_parallel = n * -sqrt(fabs(1.0 - r_out_perp.lengthSquared()));
	return r_out_perp + r_out_parallel;
}

Vec3& Vec3::operator+=(const Vec3& ent)
{
	x += ent.x;
	y += ent.y;
	z += ent.z;

	return *this;
}

Vec3& Vec3::operator-=(const Vec3& ent)
{
	x -= ent.x;
	y -= ent.y;
	z -= ent.z;

	return *this;
}

Vec3& Vec3::operator*=(const unit factor)
{
	x *= factor;
	y *= factor; 
	z *= factor;

	return *this;
}

Vec3& Vec3::operator/=(const unit factor)
{
	x /= factor;
	y /= factor; 
	z /= factor;

	return *this;
}

Vec3 Vec3::operator+(const Vec3& ent) const
{
	return Vec3{x + ent.x, y + ent.y, z + ent.z};
}

Vec3 Vec3::operator-(const Vec3& ent) const
{
	return Vec3{x - ent.x, y - ent.y, z - ent.z};
}

Vec3 Vec3::operator*(const unit factor) const
{
	return Vec3{x * factor, y * factor, z * factor};
}

Vec3 Vec3::operator/(const unit factor) const
{
	return Vec3{x / factor, y / factor, z / factor};
}

Vec3 Vec3::operator+() const
{
	return Vec3{x, y, z};
}

Vec3 Vec3::operator-() const
{
	return Vec3{-x, -y, -z};
}

//comparing x, y, z values
bool Vec3::operator==(const Vec3& rhs) const
{
	return x == rhs.x && y == rhs.y && z == rhs.z;
}

//comparing x, y, z values
bool Vec3::operator!=(const Vec3& rhs) const
{
	return !(*this == rhs);
}

//vector's length comparaison
bool Vec3::operator>(const Vec3& rhs) const
{
	return this->lengthSquared() > rhs.lengthSquared();
}

//vector's length comparaison
bool Vec3::operator<(const Vec3& rhs) const
{
	return this->lengthSquared() < rhs.lengthSquared();
}

//vector's length comparaison
bool Vec3::operator<=(const Vec3& rhs) const
{
	return this->lengthSquared() <= rhs.lengthSquared();
}

//vector's length comparaison
bool Vec3::operator>=(const Vec3& rhs) const
{
	return this->lengthSquared() >= rhs.lengthSquared();
}
