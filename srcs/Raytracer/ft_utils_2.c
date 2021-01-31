/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:00:59 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 09:03:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

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

t_pixel			ft_change_color_to_pixel(t_vector v)
{
	t_pixel p;

	p.r = (unsigned char)v.x;
	p.g = (unsigned char)v.y;
	p.b = (unsigned char)v.z;
	return (p);
}

t_pixel			ft_get_pixel(t_scene s, int i, int j)
{
	return (s.image.dat[s.reso.res[0] * j + i]);
}
