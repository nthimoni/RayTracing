/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Color.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 20:09:02 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 21:14:49 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>

#include "Color.hpp"
#include "raytracing.hpp"

Color::Color(const int color)
{
	*(int*)_bgra = color;
}

Color::Color(unit r, unit g, unit b, unit a) : _bgra{b, g, r, a} {}
Color::Color(unit r, unit g, unit b) : _bgra{b, g, r, 0} {}

unit& Color::r() { return _bgra[2]; }
unit& Color::g() { return _bgra[1]; }
unit& Color::b() { return _bgra[0]; }
unit& Color::a() { return _bgra[3]; }
const unit& Color::r() const { return _bgra[2]; }
const unit& Color::g() const { return _bgra[1]; }
const unit& Color::b() const { return _bgra[0]; }
const unit& Color::a() const { return _bgra[3]; }

int Color::toInt() const
{
	unsigned char color[4]{static_cast<unsigned char>(_bgra[0] * 255.999),
							static_cast<unsigned char>(_bgra[1] * 255.999),
							static_cast<unsigned char>(_bgra[2] * 255.999),
							static_cast<unsigned char>(_bgra[3] * 255.999)};
	return *(int*)color;
}

Color Color::operator+(const Color& rhs) const
{
	return Color{r() + rhs.r(), g() + rhs.g(), b() + rhs.b()};
}

Color& Color::operator+=(const Color& rhs)
{
	r() += rhs.r();
	g() += rhs.g();
	b() += rhs.b();
	return *this;;
}

Color& Color::operator/=(const unit factor)
{
	r() /= factor;
	g() /= factor;
	b() /= factor;
	return *this;;
}

Color Color::operator*(const Color& other) const
{
	return Color{r() * other.r(), g() * other.g(), b() * other.b()}; 
}
Color Color::operator*(const unit factor) const
{
	return Color{r() * factor, g() * factor, b() * factor}; 
}

void Color::print(std::ostream& out, int spp) const
{
	unit scale = 1.0 / spp;
	unit r = std::sqrt(scale * this->r());
	unit g = std::sqrt(scale * this->g());
	unit b = std::sqrt(scale * this->b());

	out << static_cast<int>(clamp(r, 0, 0.999) * 256)
		<< " " << static_cast<int>(clamp(g, 0, 0.999) * 256)
		<< " " << static_cast<int>(clamp(b, 0, 0.999) * 256);	
}


std::ostream& operator<<(std::ostream& out, const Color& color)
{
	out << static_cast<int>(clamp(color.r(), 0, 0.999) * 256)
		<< " " << static_cast<int>(clamp(color.g(), 0, 0.999) * 256)
		<< " " << static_cast<int>(clamp(color.b(), 0, 0.999) * 256);
	return out;
}
