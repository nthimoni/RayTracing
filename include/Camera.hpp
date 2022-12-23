/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:40:18 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 03:08:46 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_HPP
# define CAMERA_HPP 

#include "Vec3.hpp"
#include "Point3.hpp"
#include "Ray.hpp"
#include <vector>

class Camera
{
	public:
		Camera();
		Camera(const Point3& origin, unit ratio);
		Camera(const Camera& ent) = default;
		~Camera() = default;

		Ray getRay(unit u, unit v) const;

		Camera& operator=(const Camera& ent) = default;
	private:
		void setCameraProperties(const Point3& origin, unit ratio);
	private:
		Point3 _origin;
		Point3 _lowerLeftCorner;
		Vec3 _horizontal;
		Vec3 _vertical;
};

#endif 
