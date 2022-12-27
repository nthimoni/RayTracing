/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:47:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/27 19:52:17 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <memory>

#include "raytracing.hpp"
#include "Hittable.hpp"
#include "Camera.hpp"
#include "Sphere.hpp"
#include "HittableList.hpp"
#include "Vec3.hpp"
#include "Point3.hpp"
#include "Color.hpp"
#include "Ray.hpp"

Color defineColor(const Ray& ray, const HittableList& scene, int depth)
{
	if (depth <= 0)
		return {0, 0, 0};
	Inter inter;
	if (scene.hit(ray, 0.001, infinity, inter))
	{
		Point3 target = inter.pos + inter.normal + inter.randomInUnitSphere();
		return defineColor(Ray{inter.pos, target - inter.pos}, scene, depth - 1) * 0.5;
	}
	Vec3 unit_direction{ray.direction().getUnitVec()};
	auto t = 0.5 * (unit_direction.y + 1.0);
	return Color(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}


int main()
{
	// GENERAL
	constexpr int maxDepth = 10;
	constexpr int sampelsPerPixel = 15;
	// IMG
	constexpr unit ratio = 16.0 / 9.0;
    constexpr int image_width = 800;
    constexpr int image_height = static_cast<int>(image_width / ratio);

	// CAM
	Camera cam{{0, 0, 0}, ratio};

	//SCENE
	HittableList scene;
	scene.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5));
	scene.add(std::make_shared<Sphere>(Point3(0, -100.5, -1), 100));

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int j = image_height-1; j >= 0; --j) {
		std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < image_width; ++i) {
			Color pixelColor{0, 0, 0};
			for (int s = 0; s < sampelsPerPixel; s++) {
				auto u = (i + random_unit()) / (image_width-1);
				auto v = (j + random_unit()) / (image_height-1);
				Ray r = cam.getRay(u, v);
				pixelColor += defineColor(r, scene, maxDepth);
			}
			pixelColor.print(std::cout, sampelsPerPixel);
			std::cout << '\n';
		}
	}

	return 0;
}
