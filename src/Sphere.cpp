/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:36:59 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 05:36:31 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sphere.hpp"
#include "Hittable.hpp"
#include "Point3.hpp"
#include "Vec3.hpp"
#include "Material.hpp"
#include <cmath>
#include <memory>

Sphere::Sphere(const Point3& center, const unit radius, std::shared_ptr<Material> mat)
	: _center(center), _radius(radius) { this->mat = mat; }

bool Sphere::hit(const Ray& ray, unit t_min, unit t_max, Inter& inter) const
{
	Vec3 co{_center, ray.origin()};
	unit a = ray.direction().lengthSquared();
	unit half_b = co.dot(ray.direction());
	unit c = co.lengthSquared() - _radius * _radius;
	unit discriminant = half_b*half_b - a*c;
	if (discriminant < 0)
		return false;

	unit sqrtd = std::sqrt(discriminant);

	//first root -> closest to ray.origin()
	unit root = (-half_b - sqrtd) / a;
	if (root < t_min || t_max < root)
	{
		//second root
		root = (-half_b + sqrtd) / a;
		if (root < t_min || t_max < root)
			return false;
	}
	inter.t = root;
	inter.pos = ray.at(inter.t);
	Vec3 tmpNormal{(inter.pos - _center) / _radius};
	inter.setFaceNormal(ray, tmpNormal);

	return true;
}
