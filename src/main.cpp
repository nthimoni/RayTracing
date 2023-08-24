/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 04:47:17 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/24 20:40:58 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <thread>
#include <unistd.h>
#include <vector>

#include "MLXRenderer.hpp"
#include "raytracing.hpp"
#include "Hittable.hpp"
#include "Lambertian.hpp"
#include "Metal.hpp"
#include "Glass.hpp"
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
		{
			return attenuation * defineColor(scattered, scene, depth - 1);
		}
		Point3 target = inter.pos + inter.normal + inter.randomInUnitSphere().getUnitVec();
		return defineColor(Ray{inter.pos, target - inter.pos}, scene, depth - 1) * 0.5;
	}
	Vec3 unit_direction{ray.direction().getUnitVec()};
	auto t = 0.5 * (unit_direction.y + 1.0);
	return Color(1.0, 1.0, 1.0) * (1.0 - t) + Color(0.5, 0.7, 1.0) * t;
}



void threadRoutine(int threadId, const HittableList& scene, MLXRenderer& renderer, const Camera& cam)
{
	for (int j = image_height-1; j >= 0; --j)
	{
		//std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
		for (int i = threadId; i < image_width ; i += threadCount)
		{
			Color pixelColor{0, 0, 0};
			for (int s = 0; s < spp; s++)
			{
				auto u = (i + random_unit()) / (image_width-1);
				auto v = (j + random_unit()) / (image_height-1);
				Ray r = cam.getRay(u, v);
				pixelColor += defineColor(r, scene, maxDepth);
			}
			//pixelColor.print(std::cout, sampelsPerPixel);
			//std::cout << '\n';
			renderer.fillSample(i, image_height - 1 - j, pixelColor, spp);
		}
	}
}

int main()
{
	// CAM
	Camera cam{{0, 0, 0}, ratio};

	//SCENE
	HittableList scene;
	auto material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
    //auto material_left = std::make_shared<Lambertian>(Color(0.7, 0.3, 0.3));
    auto material_left = std::make_shared<Glass>(1.5);
    auto material_center   = std::make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.5);
    auto material_center2   = std::make_shared<Metal>(Color(0.8, 0.8, 0.8), 0.0);
    auto material_right  = std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 0);
	auto red = std::make_shared<Lambertian>(Color(0.9, 0.1, 0.1));
	auto green = std::make_shared<Lambertian>(Color(0.3, 0.6, 0.1));
	auto blue = std::make_shared<Lambertian>(Color(0.2, 0.2, 0.8));
	auto little = std::make_shared<Lambertian>(Color(0.2, 0.8, 1));
	auto purple = std::make_shared<Lambertian>(Color(0.8, 0.0, 0.8));

	scene.add(make_shared<Sphere>(Point3(-1, 0, -1), 0.3, red));
	//scene.add(make_shared<Sphere>(Point3(-0.3, -0.2, -0.4), 0.11, material_center2));
	scene.add(make_shared<Sphere>(Point3(-0.3, -0.2, -0.4), 0.11, material_left));
	scene.add(make_shared<Sphere>(Point3(1, 0, 1), 0.5, material_ground));
	scene.add(make_shared<Sphere>(Point3( 1, 0, -1), 0.5, blue));
	scene.add(make_shared<Sphere>(Point3( 0.5, 0.3, -0.9), 0.06, green));
	scene.add(make_shared<Sphere>(Point3(0.15, -0.4, -0.6), 0.06, material_left));
	scene.add(make_shared<Sphere>(Point3(0.35, 0.4, -0.6), 0.09, purple));
	//scene.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5, material_center));
	scene.add(make_shared<Sphere>(Point3(0, 0, -1), 0.5, material_center));
	scene.add(make_shared<Sphere>(Point3(0.5, -0.4, -0.7), 0.06, red));
	//scene.add(std::make_shared<Sphere>(Point3(0.5, 0, -1), 0.5));
	//scene.add(std::make_shared<Sphere>(Point3(-0.5, 0, -1), 0.5));
	scene.add(std::make_shared<Sphere>(Point3(0, -150.5, -1), 150, material_ground));




//	scene.add(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
//scene.add(make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
//scene.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
//scene.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),  -0.4, material_left));
//scene.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

	//auto material_ground = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
	//auto material_center = std::make_shared<Glass>(1.5);
	//auto material_left   = std::make_shared<Glass>(1.5);
	////auto material_right  = std::make_shared<Metal>(Color(0.8, 0.6, 0.2), 1.0);
	//auto material_right  = std::make_shared<Lambertian>(Color(0.8, 0.6, 0.2));

	//scene.add(make_shared<Sphere>(Point3( 0.0, -100.5, -1.0), 100.0, material_ground));
    //scene.add(make_shared<Sphere>(Point3( 0.0,    0.0, -1.0),   0.5, material_center));
    //scene.add(make_shared<Sphere>(Point3(-1.0,    0.0, -1.0),   0.5, material_left));
    //scene.add(make_shared<Sphere>(Point3( 1.0,    0.0, -1.0),   0.5, material_right));

	MLXRenderer renderer{image_width, image_height, "RayTracing"};
	if (!renderer.isInit())
		return 0;

	std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
	for (int b = 0; b < 100000; b++)
	{

		std::vector<std::thread> threads(threadCount);
		for (int i = threadCount - 1; i > 0; --i)
		{
			std::thread t(threadRoutine, i, std::ref(scene), std::ref(renderer),
					std::ref(cam));
			threads.push_back(std::move(t));
		}
		threadRoutine(0, scene, renderer, cam);



		for (auto& t : threads)
		{
			if(t.joinable())
				t.join();
		}
		renderer.render();
	}
	

	return 0;
}
