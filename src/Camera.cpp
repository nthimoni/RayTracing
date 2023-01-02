/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Camera.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 02:55:42 by nthimoni          #+#    #+#             */
/*   Updated: 2023/01/01 17:51:24 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Camera.hpp"
#include "Ray.hpp"

Camera::Camera()
{
	setCameraProperties({0, 0, 0}, 16.0 / 9.0);
}

Camera::Camera(const Point3& origin, unit ratio)
{
	setCameraProperties(origin, ratio);
}

void Camera::setCameraProperties(const Point3& origin, unit ratio)
{
	unit viewportHeight = 2.0;
	unit viewportWidth = viewportHeight * ratio;
	unit focalLength = 1.0;

	_origin = origin;
	_horizontal = {viewportWidth, 0, 0};
	_vertical = {0, viewportHeight, 0};
	_lowerLeftCorner = origin - _horizontal/2 - _vertical/2 - Vec3{0, 0, focalLength};
}

Ray Camera::getRay(unit u, unit v) const
{
	return Ray{_origin, _lowerLeftCorner + _horizontal*u + _vertical*v - _origin};
}
