/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 23:19:50 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/22 03:02:05 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_HPP
# define RAY_HPP 

#include "Point3.hpp"
#include "Vec3.hpp"
#include "raytracing.hpp"

class Ray
{
	public:
		Ray() = default;
		Ray(const Ray& ent) = default;
		Ray(const Point3& point, const Vec3& direction);
		~Ray() = default;

		Point3 at(unit t) const;
		Vec3 direction() const;
		Point3 origin() const;

		Ray& operator=(const Ray& ent) = default;
	private:
		Point3 _ori;
		Vec3 _dir;
};

#endif 
