/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tup3.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 19:30:09 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/21 21:06:58 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUP3_HPP
# define TUP3_HPP 

# include "raytracing.hpp"

// Base class for 3 values tuples (Vec3, Point3 ...)
class Tup3 
{
	public:
		unit x{}, y{}, z{};
		Tup3() = default;
		Tup3(unit x, unit y, unit z);
		Tup3(const Tup3& ent) = default;
		virtual ~Tup3() = default;

		virtual void log(const char* name) const = 0;

		Tup3& operator=(const Tup3& ent) = default;
};

#endif 
