/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Glass.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 20:45:13 by nthimoni          #+#    #+#             */
/*   Updated: 2023/08/18 16:40:16 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLASS_HPP
# define GLASS_HPP 

# include "Material.hpp"

class Glass : public Material
{
	public:
		Glass() = default;
		Glass(const Glass& ent) = default;
		Glass(unit indexOfRefraction);
		~Glass() = default;

		virtual bool scatter(const Ray& in, const Inter& inter,
				Color& attenuation, Ray& scattered) const override;

		Glass& operator=(const Glass& ent) = default;

	private:
		unit _indexOfRefraction;
};

#endif 
