/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:47:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 21:34:38 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>
#include <memory>

#include "raytracing.hpp"
#include "Hittable.hpp"
#include "Material.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
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
		Ray scattered;
		Color attenuation;
		if (inter.material->scatter(ray, inter, attenuation, scattered))
			return attenuation * defineColor(scattered, scene, depth - 1);
		Point3 target = inter.pos + inter.normal + inter.randomInUnitSphere().getUnitVec();
		return defineColor(Ray{inter.pos, target - inter.pos}, scene, depth - 1) * 0.5;
	}
	Vec3 unit_direction{ray.direction().getUnitVec()};
	auto t = 0.5 * (unit_direction.y + 1.0);
	return Color(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}


int main()
{
	// GENERAL
	constexpr int maxDepth = 3;
	constexpr int sampelsPerPixel = 1000;
	// IMG
	constexpr unit ratio = 16.0 / 9.0;
    constexpr int image_width = 800;
    constexpr int image_height = static_cast<int>(image_width / ratio);

	// CAM
	Camera cam{{0, 0, 0}, ratio};

	//SCENE
	HittableList scene;
	auto material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    auto material_center = std::make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    auto material_left   = std::make_shared<Metal>(Color(0.8, 0.8, 0.8));
    auto material_right  = std::make_shared<Metal>(Color(0.8, 0.6, 0.2));

	scene.add(std::make_shared<Sphere>(Point3(0, 0, -1), 0.5, material_center));
	scene.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    scene.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));
	//scene.add(std::make_shared<Sphere>(Point3(0.5, 0, -1), 0.5));
	//scene.add(std::make_shared<Sphere>(Point3(-0.5, 0, -1), 0.5));
	scene.add(std::make_shared<Sphere>(Point3(0, -150.5, -1), 150, material_ground));





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
