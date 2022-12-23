/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hittable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:54:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 01:47:10 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_HPP
# define HITTABLE_HPP 

# include "Point3.hpp"
# include "Vec3.hpp"
# include "Ray.hpp"
# include "raytracing.hpp"

struct Inter
{
	Point3 pos;
	Vec3 normal;
	unit t;
	bool frontFace;
	inline void setFaceNormal(const Ray& ray, const Vec3& outwardNormal)
	{
		frontFace = ray.direction().dot(outwardNormal);
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
	public:
		virtual bool hit(const Ray& ray, unit t_min, unit t_max, Inter& inter) const = 0;
};

#endif 
