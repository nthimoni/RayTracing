/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lambertian.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 05:38:17 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 20:52:26 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAMBERTIAN_HPP
# define LAMBERTIAN_HPP 

#include "Color.hpp"
#include "Material.hpp"

class Lambertian : public Material
{
	public:
		Lambertian() = default;
		Lambertian(const Lambertian& ent) = default;
		Lambertian(const Color& col);
		~Lambertian() = default;

		virtual bool scatter(const Ray& in, const Inter& inter,
				Color& attenuation, Ray& scattered) const override;

		Lambertian& operator=(const Lambertian& ent) = default;;
	private:
		Color _color;
};

#endif 
