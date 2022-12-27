/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:00:12 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/27 19:47:30 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_HPP
# define COLOR_HPP 

# include <iostream>
# include "raytracing.hpp"

class Color
{
	public:
		Color() = default;
		Color(const Color& ent) = default;
		Color(const int color);
		Color(unit r, unit g, unit b, unit a);
		Color(unit r, unit g, unit b);
		~Color() = default;

		unit& r();
		unit& g();
		unit& b();
		unit& a();
		const unit& r() const;
		const unit& g() const;
		const unit& b() const;
		const unit& a() const;
		void print(std::ostream& out, int spp) const;
		int toInt() const;

		Color& operator=(const Color& ent) = default;
		Color& operator+=(const Color& rhs);
		Color& operator/=(const unit factor);

		Color operator+(const Color& rhs) const;
		Color operator*(const unit factor) const;
	private:
		unit _bgra[4]{0, 0, 0, 0};
};

std::ostream& operator<<(std::ostream& out, const Color& color);

#endif 
