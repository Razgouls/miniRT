/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:00:07 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 13:23:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

double			ft_distance(t_vector v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

double			ft_scalaire(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vector		ft_cross_product(t_vector v1, t_vector v2)
{
	t_vector res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

double			ft_orient(t_vector a, t_vector b,
					t_vector c, t_vector n)
{
	t_vector tmp;

	tmp = ft_cross_product(ft_sous_vector(b, a), ft_sous_vector(c, a));
	return (ft_scalaire(tmp, n));
}

t_vector		ft_normalize(t_vector v)
{
	double		norme;
	t_vector	tmp;

	norme = ft_distance(v);
	tmp.x = v.x / norme;
	tmp.y = v.y / norme;
	tmp.z = v.z / norme;
	return (tmp);
}
