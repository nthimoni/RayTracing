/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 21:26:12 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 01:45:02 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_HPP
# define SPHERE_HPP 

# include "Hittable.hpp"
#include "Point3.hpp"

class Sphere : public Hittable
{
	public:
		Sphere() = default;
		Sphere(const Point3& center, unit radius);
		Sphere(const Sphere& ent);
		virtual ~Sphere() = default;

		virtual bool hit(const Ray& ray, unit t_min, unit t_max, Inter& inter) const override;

		Sphere& operator=(const Sphere& ent) = default;

	private:
		Point3 _center;
		unit _radius;
};

#endif 
