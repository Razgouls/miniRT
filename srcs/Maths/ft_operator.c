/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 11:56:30 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 13:23:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		ft_multi_reel(t_vector p1, double p2)
{
	t_vector		res;

	res.x = p1.x * p2;
	res.y = p1.y * p2;
	res.z = p1.z * p2;
	return (res);
}

t_vector		ft_divi_reel(t_vector p1, double p2)
{
	t_vector		res;

	res.x = p1.x / p2;
	res.y = p1.y / p2;
	res.z = p1.z / p2;
	return (res);
}

t_vector		ft_add_vector(t_vector p1, t_vector p2)
{
	t_vector		res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	res.z = p1.z + p2.z;
	return (res);
}

t_vector		ft_multi_vector(t_vector p1, t_vector p2)
{
	t_vector		res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	res.z = p1.z * p2.z;
	return (res);
}

t_vector		ft_sous_vector(t_vector p1, t_vector p2)
{
	t_vector tmp;

	tmp.x = p1.x - p2.x;
	tmp.y = p1.y - p2.y;
	tmp.z = p1.z - p2.z;
	return (tmp);
}
