/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hittable.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:54:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 21:12:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLE_HPP
# define HITTABLE_HPP 

# include "Point3.hpp"
# include "Vec3.hpp"
# include "Ray.hpp"
# include "raytracing.hpp"
# include <memory>

class Material;

struct Inter
{
	Point3 pos;
	Vec3 normal;
	std::shared_ptr<Material> material;
	unit t;
	bool frontFace;
	inline void setFaceNormal(const Ray& ray, const Vec3& outwardNormal)
	{
		frontFace = ray.direction().dot(outwardNormal) < 0;
		normal = frontFace ? outwardNormal : -outwardNormal;
	}
	static inline Vec3 randomInUnitSphere()
	{
		while (1)
		{
			Vec3 v = Vec3::random(-1, 1);
			if (v.lengthSquared() < 1)
				return v;
		}
	}
};

class Hittable
{
	public:
		virtual bool hit(const Ray& ray, unit t_min, unit t_max, Inter& inter) const = 0;
	protected:
		std::shared_ptr<Material> _mat;
};

#endif 
