/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HittableList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nthimoni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 01:00:23 by nthimoni          #+#    #+#             */
/*   Updated: 2022/12/23 01:16:42 by nthimoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HittableList.hpp"

HittableList::HittableList(std::shared_ptr<Hittable> obj)
{
	objs.push_back(obj);
}

void HittableList::clear()
{
	objs.clear();
}
void HittableList::add(std::shared_ptr<Hittable> obj)
{
	objs.push_back(obj);
}

bool HittableList::hit(const Ray &ray, unit t_min, unit t_max, Inter &inter) const
{
	Inter tmpInter;
	bool hitSmthing = false;
	unit closestInter = t_max;

	for (const auto& obj : objs)
	{
		if (obj->hit(ray, t_min, closestInter, tmpInter))
		{
			hitSmthing = true;
			closestInter = tmpInter.t;
			inter = tmpInter;
		}
	}
	return hitSmthing;
}
