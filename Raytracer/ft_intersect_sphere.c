/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/17 16:55:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

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

double		ft_intersect_sphere(t_ray ray, t_sphere *sphere)
{
	t_racine	racines;
	t_vector3D	abc;
	double		det;

	ray.origin = ft_add_vector(ray.origin, ft_multi_reel(sphere->base.origin, -1));
	abc.x = ft_vect(ray.dir, ray.dir);
	abc.y = 2 * ft_vect(ray.dir, ray.origin);
	abc.z = ft_vect(ray.origin, ray.origin) - pow(sphere->radius, 2);
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
	sphere->base.normale = ft_point_intersect_ray(ray.origin, ray.dir, racines.t1);
    sphere->base.normale = ft_divi_reel(sphere->base.normale, sphere->radius);
	return (racines.t1);
}

double		ft_intersect_plane(t_ray ray, t_plane *plane)
{
	double	t;
	t_ray	tmp_ray;

	tmp_ray = ray;
	ray.origin = ft_add_vector(ray.origin, ft_multi_reel(plane->base.origin, -1));
	ray.origin = ft_multi_mat_vect(plane->base.inv_matrice, ray.origin);
	ray.dir = ft_trans_orient(ray, (void *)plane);
	t = -(ray.origin.y / ray.dir.y);
	if (t < 0)
		return (-1);
	plane->base.normale = ft_init_vector(0, 1, 0);
	plane->base.normale = ft_multi_mat_vect(plane->base.matrice, plane->base.normale);
	return (t);
}

double		ft_intersect_triangle(t_ray ray, t_triangle *tr)
{
	t_vector3D	intersect;
	double		t;

	t = -(ray.origin.y - tr->p1.y) / ray.dir.y;
	if (t < 0)
		return (-1);
	intersect = ft_point_intersect_ray(ray.origin, ray.dir, t);
	if (ft_aire_tr(tr->p1, tr->p2, tr->p3) < ft_aire_tr(tr->p1, intersect, tr->p2) + ft_aire_tr(tr->p2, intersect, tr->p3) + ft_aire_tr(tr->p1, intersect, tr->p3) - 0.001)
		return (-1);
	tr->base.normale = ft_init_vector(0, 1, 0);
	return (t);
}

double		ft_intersect_cylindre(t_ray ray, t_cylindre *cylindre)
{
	t_vector3D	abc;
	t_racine	racines;
	t_vector3D	intersect;
	double		det;

	ray.origin = ft_add_vector(ray.origin, ft_multi_reel(cylindre->base.origin, -1));
	ray.origin = ft_multi_mat_vect(cylindre->base.inv_matrice, ray.origin);
	ray.dir = ft_trans_orient(ray, (void *)cylindre);
	abc.x = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	abc.y = 2 * (((ray.origin.x) * ray.dir.x) + ((ray.origin.z) * ray.dir.z));
	abc.z = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - pow(cylindre->radius, 2);
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det < 0)
		return (-1);
	racines.t1 = ((-abc.y - sqrt(det)) / (2 * abc.x));
	racines.t2 = ((-abc.y + sqrt(det)) / (2 * abc.x));
	if (racines.t1 > racines.t2 || (racines.t1 <= 0 && racines.t2 >= 0))
		racines.t1 = racines.t2;
	intersect = ft_point_intersect_ray(ray.origin, ray.dir, racines.t1);
	if (intersect.y < 0 || intersect.y > cylindre->height)
		return (-1);
	intersect.y = 0;
	cylindre->base.normale = ft_multi_mat_vect(cylindre->base.matrice, intersect);
	cylindre->base.normale = ft_divi_reel(cylindre->base.normale, cylindre->radius);
    return (racines.t1);
}

double		ft_intersect_cone(t_ray ray, t_cone *cone)
{
	t_racine	racines;
	t_vector3D	tmp;
	t_vector3D	abc;
	double		tan;
	double		det;

	ray.origin = ft_add_vector(ray.origin, ft_multi_reel(cone->base.origin, -1));
	ray.origin = ft_multi_mat_vect(cone->base.inv_matrice, ray.origin);
	ray.dir = ft_trans_orient(ray, (void *)cone);
	tmp.x = ray.origin.x;
	tmp.y = cone->height - ray.origin.y;
	tmp.z = ray.origin.z;
	tan = pow(cone->radius / cone->height, 2);
	abc.x = pow(ray.dir.x, 2) + pow(ray.dir.z, 2) - (tan * pow(ray.dir.y, 2));
	abc.y = (2 * tmp.x * ray.dir.x) + (2 * tmp.z * ray.dir.z) + (2 * tan * tmp.y * ray.dir.y);
	abc.z = pow(tmp.x, 2) + pow(tmp.z, 2) - (tan * pow(tmp.y, 2));
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det < 0)
		return (-1);
	racines.t1 = ((-abc.y - sqrt(det)) / (2 * abc.x));
	racines.t2 = ((-abc.y + sqrt(det)) / (2 * abc.x));
	if (racines.t1 > racines.t2 || (racines.t1 <= 0 && racines.t2 >= 0))
		racines.t1 = racines.t2;
	t_vector3D intersect = ft_point_intersect_ray(ray.origin, ray.dir, racines.t1);
	if ((intersect.y < 0) || (intersect.y > cone->height)) 
		return (-1);
	intersect.y = sqrt(pow(intersect.x, 2) + pow(intersect.z, 2)) * (cone->radius / cone->height);
	cone->base.normale = ft_multi_mat_vect(cone->base.matrice, intersect);
    cone->base.normale = ft_normalize(intersect);
    return (racines.t1);
}

double		ft_intersect_square(t_ray ray, t_square *square)
{
	t_vector3D	intersect;
	double		t1;
	double		t2;

	ray.origin = ft_add_vector(ray.origin, ft_multi_reel(square->base.origin, -1));
	ray.origin = ft_multi_mat_vect(square->base.inv_matrice, ray.origin);
	ray.dir = ft_trans_orient(ray, (void *)square);
	t1 = -(ray.origin.y) / ray.dir.y;
	if (t1 <= 0)
		return (-1);
	intersect = ft_point_intersect_ray(ray.origin, ray.dir, t1);
	t2 = square->height / 2;
	if (intersect.x < -t2 || intersect.x > t2 || intersect.y < -t2 || intersect.y > t2 || intersect.z < -t2 || intersect.z > t2)
		return (-1);
	square->base.normale = ft_init_vector(0, 1, 0);
	square->base.normale = ft_multi_mat_vect(square->base.matrice, square->base.normale);
	return (t1);
}



