/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Material.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 04:56:14 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/28 06:29:19 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_HPP
# define MATERIAL_HPP 

#include "Hittable.hpp"
#include "Color.hpp"
#include <memory>

class Material
{
	public:
		virtual bool scatter(const Ray& in, const Inter& inter,
				Color& attenuation, Ray& scattered) const = 0;
};

#endif 
