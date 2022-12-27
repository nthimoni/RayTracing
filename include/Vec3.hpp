/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vec3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 21:34:03 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 04:32:53 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC3_HPP
# define VEC3_HPP 

#include "raytracing.hpp"
#include "Tup3.hpp"

class Point3;

class Vec3 : public Tup3
{
	public:
		Vec3() = default;
		Vec3(const unit x, const unit y, const unit z);
		Vec3(const Point3& src, const Point3& dst);
		Vec3(const Vec3& ent) = default;
		virtual ~Vec3() = default;

		unit length() const;
		unit lengthSquared() const;
		void norm();
		Vec3 getUnitVec() const;
		void log(const char* name) const;
		unit dot(const Vec3& ent) const;
		Vec3 cross(const Vec3& ent) const;

		static inline Vec3 random()
			{ return {random_unit(), random_unit(), random_unit()}; }
		static inline Vec3 random(unit min, unit max)
			{ return {random_unit(min, max), random_unit(min, max), random_unit(min, max)};}

		Vec3& operator=(const Vec3& ent) = default;

		Vec3& operator+=(const Vec3& ent);
		Vec3& operator-=(const Vec3& ent);
		Vec3& operator*=(const unit factor);
		Vec3& operator/=(const unit factor);

		Vec3 operator+(const Vec3& ent) const;
		Vec3 operator-(const Vec3& ent) const;
		Vec3 operator*(const unit factor) const;
		Vec3 operator/(const unit factor) const;

		Vec3 operator+() const;
		Vec3 operator-() const;

		//comparing x, y, z values
		bool operator==(const Vec3& rhs) const;
		bool operator!=(const Vec3& rhs) const;

		//vector's length comparaison
		bool operator>(const Vec3& rhs) const;
		bool operator<(const Vec3& rhs) const;
		bool operator<=(const Vec3& rhs) const;
		bool operator>=(const Vec3& rhs) const;
};

#endif 
