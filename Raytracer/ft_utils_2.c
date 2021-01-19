/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:00:59 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 13:27:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector		ft_intersect_ray(t_vector origin, t_vector dir, double t)
{
	t_vector tmp;

	tmp = ft_multi_reel(dir, t);
	tmp = ft_add_vector(origin, tmp);
	return (tmp);
}

t_vector		ft_init_vector(double x, double y, double z)
{
	t_vector res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

t_vectorf		ft_init_vector_2(double x, double y, double z, double t)
{
	t_vectorf res;

	res.x = x;
	res.y = y;
	res.z = z;
	res.t = t;
	return (res);
}
