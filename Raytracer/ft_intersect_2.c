/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:25:21 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 13:25:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double			ft_inter(t_inter *inter, double height)
{
	inter->det = ft_calc_determinant(inter->abc.x, inter->abc.y, inter->abc.z);
	if (inter->det < 0)
		return (-1);
	inter->t1 = ((-inter->abc.y - sqrt(inter->det)) / (2 * inter->abc.x));
	inter->t2 = ((-inter->abc.y + sqrt(inter->det)) / (2 * inter->abc.x));
	if (inter->t1 > inter->t2 || (inter->t1 <= 0 && inter->t2 >= 0))
		inter->t1 = inter->t2;
	else if (inter->t1 > 0 && inter->t2 > 0)
	{
		inter->inter = ft_intersect_ray(inter->ray.o,
						inter->ray.dir, inter->t1);
		if (inter->inter.y < 0 || inter->inter.y > height)
		{
			inter->t1 = inter->t2;
			inter->inv_normale = -1;
		}
	}
	inter->inter = ft_intersect_ray(inter->ray.o,
						inter->ray.dir, inter->t1);
	if (inter->inter.y < 0 || inter->inter.y > height)
		return (-1);
	return (0);
}

double			ft_intersect_cylindre(t_ray ray, t_cylindre *cy)
{
	t_inter		inter;

	inter.inv_normale = 1;
	ray.o = ft_add_vector(ray.o, ft_multi_reel(cy->base.origin, -1));
	ray.o = ft_multi_mat_vect(cy->base.inv_matrice, ray.o);
	ray.dir = ft_trans_orient(ray, (void *)cy);
	inter.ray = ray;
	inter.abc.x = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	inter.abc.y = 2 * (((ray.o.x) * ray.dir.x) + ((ray.o.z) * ray.dir.z));
	inter.abc.z = pow(ray.o.x, 2) + pow(ray.o.z, 2) - pow(cy->radius, 2);
	if (ft_inter(&inter, cy->height) == -1)
		return (-1);
	inter.inter.y = 0;
	cy->base.normale = ft_multi_mat_vect(cy->base.matrice, inter.inter);
	cy->base.normale = ft_divi_reel(cy->base.normale, cy->radius);
	cy->base.normale = ft_multi_reel(cy->base.normale, inter.inv_normale);
	return (inter.t1);
}

double			ft_intersect_cone(t_ray ray, t_cone *cone)
{
	t_inter		inter;
	double		tmp;
	double		tan;

	ray.o = ft_add_vector(ray.o, ft_multi_reel(cone->base.origin, -1));
	ray.o = ft_multi_mat_vect(cone->base.inv_matrice, ray.o);
	ray.dir = ft_trans_orient(ray, (void *)cone);
	inter.ray = ray;
	inter.inv_normale = 1;
	tmp = cone->height - ray.o.y;
	tan = pow(cone->radius / cone->height, 2);
	inter.abc.x = pow(ray.dir.x, 2) +
		pow(ray.dir.z, 2) - (tan * pow(ray.dir.y, 2));
	inter.abc.y = (2 * ray.o.x * ray.dir.x) +
		(2 * ray.o.z * ray.dir.z) + (2 * tan * tmp * ray.dir.y);
	inter.abc.z = pow(ray.o.x, 2) + pow(ray.o.z, 2) - (tan * pow(tmp, 2));
	if (ft_inter(&inter, cone->height) == -1)
		return (-1);
	inter.inter.y = sqrt(pow(inter.inter.x, 2) +
		pow(inter.inter.z, 2)) * (cone->radius / cone->height);
	cone->base.normale = ft_multi_mat_vect(cone->base.matrice, inter.inter);
	cone->base.normale = ft_normalize(cone->base.normale);
	cone->base.normale = ft_multi_reel(cone->base.normale, inter.inv_normale);
	return (inter.t1);
}

double			ft_intersect_square(t_ray ray, t_square *sq)
{
	t_vector	intersect;
	double		t1;
	double		t2;

	ray.o = ft_add_vector(ray.o, ft_multi_reel(sq->base.origin, -1));
	ray.o = ft_multi_mat_vect(sq->base.inv_matrice, ray.o);
	ray.dir = ft_trans_orient(ray, (void *)sq);
	t1 = -(ray.o.y) / ray.dir.y;
	if (t1 <= 0)
		return (-1);
	intersect = ft_intersect_ray(ray.o, ray.dir, t1);
	t2 = sq->height / 2;
	if (intersect.x < -t2 || intersect.x > t2 || intersect.y < -t2 ||
intersect.y > t2 || intersect.z < -t2 || intersect.z > t2)
		return (-1);
	sq->base.normale = ft_init_vector(0, 1, 0);
	if (sq->base.origin.y > ray.o.y)
		sq->base.normale = ft_init_vector(0, -1, 0);
	sq->base.normale = ft_multi_mat_vect(sq->base.matrice, sq->base.normale);
	return (t1);
}
