/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Metal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:45:13 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 20:52:11 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAL_HPP
# define METAL_HPP 

# include "Material.hpp"

class Metal : public Material
{
	public:
		Metal() = default;
		Metal(const Metal& ent) = default;
		Metal(const Color& color);
		~Metal() = default;

		virtual bool scatter(const Ray& in, const Inter& inter,
				Color& attenuation, Ray& scattered) const override;

		Metal& operator=(const Metal& ent) = default;

	private:
		Color _color;
};

#endif 
