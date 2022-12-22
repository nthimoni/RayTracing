/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point3.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:12:19 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/22 03:37:06 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT3_HPP
# define POINT3_HPP 

#include "Tup3.hpp"
#include "Vec3.hpp"

class Point3 : public Tup3
{
	public:
		Point3() = default;
		Point3(const unit x, const unit y, const unit z);
		Point3(const Point3& ent) = default;
		virtual ~Point3() = default;

		void log(const char* name) const;

		Point3& operator=(const Point3& ent) = default;	

		Point3 operator+(const Vec3& rhs) const;
		Point3 operator-(const Vec3& rhs) const;
		Point3& operator+=(const Vec3& rhs);
		Vec3 operator-(const Point3& rhs) const;
		bool operator==(const Point3& rhs) const;
		bool operator!=(const Point3& rhs) const;
};

#endif 
