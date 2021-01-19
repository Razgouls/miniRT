/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:25:01 by user42            #+#    #+#             */
/*   Updated: 2021/01/19 13:29:32 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double		ft_intersect(t_ray ray, void *content)
{
	t_base_form *b;
	char		*id;

	b = (t_base_form *)content;
	id = b->id;
	if (ft_strcmp(id, "sp") == 0)
		return (ft_intersect_sphere(ray, (t_sphere *)content));
	else if (ft_strcmp(id, "pl") == 0)
		return (ft_intersect_plane(ray, (t_plane *)content));
	else if (ft_strcmp(id, "tr") == 0)
		return (ft_intersect_triangle(ray, (t_triangle *)content));
	else if (ft_strcmp(id, "cy") == 0)
		return (ft_intersect_cylindre(ray, (t_cylindre *)content));
	else if (ft_strcmp(id, "co") == 0)
		return (ft_intersect_cone(ray, (t_cone *)content));
	else if (ft_strcmp(id, "sq") == 0)
		return (ft_intersect_square(ray, (t_square *)content));
	return (-1);
}

double		ft_intersect_sphere(t_ray ray, t_sphere *sp)
{
	t_racine	racines;
	t_vector	abc;
	double		det;

	ray.o = ft_add_vector(ray.o, ft_multi_reel(sp->base.origin, -1));
	abc.x = ft_scalaire(ray.dir, ray.dir);
	abc.y = 2 * ft_scalaire(ray.dir, ray.o);
	abc.z = ft_scalaire(ray.o, ray.o) - pow(sp->radius, 2);
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det < 0)
		return (-1);
	else if (det == 0)
		return (-abc.y / 2 * abc.x);
	else
	{
		det = sqrt(det);
		racines.t1 = (-abc.y + det) * 0.5 * abc.x;
		racines.t2 = (-abc.y - det) * 0.5 * abc.x;
		if (racines.t1 > racines.t2 && !(racines.t1 >= 0 && racines.t2 <= 0))
			racines.t1 = racines.t2;
	}
	sp->base.normale = ft_intersect_ray(ray.o, ray.dir, racines.t1);
	sp->base.normale = ft_divi_reel(sp->base.normale, sp->radius);
	return (racines.t1);
}

double		ft_intersect_plane(t_ray ray, t_plane *pl)
{
	double		t1;

	ray.o = ft_add_vector(ray.o, ft_multi_reel(pl->base.origin, -1));
	ray.o = ft_multi_mat_vect(pl->base.inv_matrice, ray.o);
	ray.dir = ft_trans_orient(ray, (void *)pl);
	t1 = -(ray.o.y) / ray.dir.y;
	if (t1 <= 0.0001)
		return (-1);
	pl->base.normale = ft_init_vector(0, 1, 0);
	if (pl->base.origin.y > ray.o.y)
		pl->base.normale = ft_init_vector(0, -1, 0);
	pl->base.normale = ft_multi_mat_vect(pl->base.matrice, pl->base.normale);
	return (t1);
}

double		ft_intersect_triangle(t_ray ray, t_triangle *tr)
{
	t_vector	inter;
	double		t;

	t = -(ray.o.y - tr->p1.y) / ray.dir.y;
	if (t < 0)
		return (-1);
	inter = ft_intersect_ray(ray.o, ray.dir, t);
	if (ft_aire_tr(tr->p1, tr->p2, tr->p3) <
	ft_aire_tr(tr->p1, inter, tr->p2) + ft_aire_tr(tr->p2, inter, tr->p3) +
	ft_aire_tr(tr->p1, inter, tr->p3) - 0.001)
		return (-1);
	tr->base.normale = ft_init_vector(0, 1, 0);
	return (t);
}
