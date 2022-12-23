/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HittableList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 00:51:47 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 01:34:24 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HITTABLELIST_HPP
# define HITTABLELIST_HPP 

# include "Hittable.hpp"
# include <memory>
# include <vector>

class HittableList : public Hittable
{
	public:
		HittableList() = default;
		HittableList(std::shared_ptr<Hittable> obj);
		HittableList(const HittableList& ent) = default;
		~HittableList() = default;

		void clear();
		void add(std::shared_ptr<Hittable> obj);
		virtual bool hit(const Ray& ray, unit t_min, unit t_max, Inter& inter) const override;

		HittableList& operator=(const HittableList& ent) = default;
	private:
		std::vector<std::shared_ptr<Hittable>> objs;
};

#endif 
