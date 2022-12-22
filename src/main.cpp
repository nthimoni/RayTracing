/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:47:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/22 18:56:56 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

#include "raytracing.hpp"
#include "Vec3.hpp"
#include "Point3.hpp"
#include "Color.hpp"
#include "Ray.hpp"


unit hit_sphere(const Point3& center, unit radius, const Ray& r)
{
	Vec3 oc{center, r.origin()};
	unit a = r.direction().dot(r.direction());
	unit b = 2.0 * oc.dot(r.direction());
	unit c = oc.dot(oc) - radius * radius;
	unit discriminant = b*b - 4*a*c;
	if (discriminant < 0)
		return -1;
	else
		return (-b - std::sqrt(discriminant)) / (2.0 * a);
}

Color background(const Ray& ray)
{
	unit t = hit_sphere(Point3(0, 0, -1), 0.5, ray);
	if (t > 0)
	{
		Vec3 normal = (ray.at(t) - Point3(0, 0, -1)).getUnitVec();
		return Color{normal.x + 1, normal.y + 1, normal.z + 1} * 0.5;
	}
	Vec3 unit_direction{ray.direction().getUnitVec()};
	t = 0.5 * (unit_direction.y + 1.0);
	return Color(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}


int main()
{
	// IMG
	const unit ratio = 16.0 / 9.0;
    const int image_width = 1500;
    const int image_height = static_cast<int>(image_width / ratio);

	// CAM
	unit view_height = 2.0;
	unit view_width = ratio * view_height;
	unit focal_length = 1.0;

	Point3 origin{0.0, 0.0, 0.0};
	Vec3 horizontal{view_width, 0, 0};
	Vec3 vertical{0, view_height, 0};
	Point3 lower_left_corner = origin - horizontal / 2
								- vertical / 2
								- Vec3{0, 0, focal_length};

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	 for (int j = image_height-1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (image_width-1);
            auto v = double(j) / (image_height-1);
            Ray r(origin, lower_left_corner + horizontal*u + vertical*v - origin);
            Color pixel_color = background(r);
			std::cout << pixel_color << '\n';
        }
	 }

	return 0;
}
