/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/16 12:03:32 by eoliveir         ###   ########.fr       */
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
	t_vector3D 	tmp_vect;

	tmp_vect = ft_sous_vector(ray.origin, sphere->base.origin);
	abc.x = ft_vect(ray.dir, ray.dir);
	abc.y = 2 * ft_vect(ray.dir, tmp_vect);
	abc.z = ft_vect(tmp_vect, tmp_vect) - pow(sphere->radius, 2);
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det < 0)
		return (-1);
	else if (det == 0)
		return (-abc.y);
	else
	{
		det = sqrt(det);
		racines.t1 = (-abc.y + det) * 0.5 * abc.x;
		racines.t2 = (-abc.y - det) * 0.5 * abc.x;
		if (racines.t1 > racines.t2)
			racines.t1 = racines.t2;
	}
	sphere->base.normale = ft_sous_vector(ft_point_intersect_ray(ray.origin, ray.dir, racines.t1), sphere->base.origin);
    sphere->base.normale = ft_divi_reel(sphere->base.normale, sphere->radius);
	return (racines.t1);
}

double		ft_intersect_plane(t_ray ray, t_plane *plane)
{
	double t;
	double tmp;
	
	tmp = ft_scalaire(plane->base.vect_orient, ray.dir);
	if (tmp == 0)
		return (-1);
	t = -(ray.origin.y - plane->base.origin.y) / ray.dir.y;
	if (t < 0)
		return (-1);
	if (tmp < 0)
		plane->base.normale = plane->base.vect_orient;
	else
		plane->base.normale = ft_multi_reel(plane->base.vect_orient, -1);
	return (t);
}

double		ft_barycentre(t_ray ray, t_triangle triangle, t_calc_tri edge)
{
	double		det;
	t_vector3D	normale;
	t_vector3D	dist_origin_fist;
	t_vector3D	q;

	normale = ft_cross_product(ray.dir, edge.edge2);
	det = ft_vect(edge.edge1, normale);
	if (det <= 0)
		return (-1);
	edge.a = 1.0 / det;
	dist_origin_fist = ft_sous_vector(ray.origin, triangle.p1);
	edge.b = edge.a * ft_vect(dist_origin_fist, normale);
	if (edge.b < 0.0 || edge.b > 1.0)
		return (-1);
	q = ft_cross_product(dist_origin_fist, edge.edge1);
	edge.c = edge.a * ft_vect(ray.dir, q);
	if (edge.c < 0.0 || edge.b + edge.c > 1.0)
		return (-1);
	return (edge.a * ft_vect(edge.edge2, q));
}

double		ft_intersect_triangle(t_ray ray, t_triangle *triangle)
{
	t_calc_tri	edge;
	double		t;

	edge.edge1 = ft_sous_vector(triangle->p2, triangle->p1);
	edge.edge2 = ft_sous_vector(triangle->p3, triangle->p1);
	t = ft_barycentre(ray, *triangle, edge);
	if (t > 0)
		triangle->base.normale = ft_cross_product(edge.edge1, edge.edge2);
	return (t);
}

double		ft_calcule_area(t_vector3D v1, t_vector3D v2, t_vector3D v3)
{
	double	det;
	det = ((v1.x - v3.x) * (v2.y - v3.y)) - ((v2.x - v3.x) * (v1.y - v3.y));
	return (det / 2);
}

double		ft_intersect_cylindre(t_ray ray, t_cylindre *cylindre)
{
	t_vector3D	abc;
	t_racine	racines;
	t_vector3D	intersect;
	double		det;

	abc.x = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	abc.y = 2 * (((ray.origin.x - cylindre->base.origin.x) * ray.dir.x) + ((ray.origin.z - cylindre->base.origin.z) * ray.dir.z));
	abc.z = pow(ray.origin.x - cylindre->base.origin.x, 2) + pow(ray.origin.z - cylindre->base.origin.z, 2) - pow(cylindre->radius, 2);
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det <= 0)
		return (-1);
	racines.t1 = ((-abc.y - sqrt(det)) / (2 * abc.x));
	racines.t2 = ((-abc.y + sqrt(det)) / (2 * abc.x));
	if (racines.t1 > racines.t2)
		racines.t1 = racines.t2;
	intersect = ft_point_intersect_ray(ray.origin, ray.dir, racines.t1);
	if ((intersect.y < cylindre->base.origin.y) || (intersect.y > cylindre->base.origin.y + cylindre->height))
		return (-1);
	cylindre->base.normale = ft_sous_vector(intersect, cylindre->base.origin);
	cylindre->base.normale.y = 0;
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

	tmp.x = ray.origin.x - cone->base.origin.x;
	tmp.y = cone->height - ray.origin.y + cone->base.origin.y;
	tmp.z = ray.origin.z - cone->base.origin.z;
	tan = pow(cone->radius / cone->height, 2);
	abc.x = pow(ray.dir.x, 2) + pow(ray.dir.z, 2) - (tan * pow(ray.dir.y, 2));
	abc.y = (2 * tmp.x * ray.dir.x) + (2 * tmp.z * ray.dir.z) + (2 * tan * tmp.y * ray.dir.y);
	abc.z = pow(tmp.x, 2) + pow(tmp.z, 2) - (tan * pow(tmp.y, 2));
	det = ft_calc_determinant(abc.x, abc.y, abc.z);
	if (det < 0)
		return (-1);
	racines.t1 = ((-abc.y - sqrt(det)) / (2 * abc.x));
	racines.t2 = ((-abc.y + sqrt(det)) / (2 * abc.x));
	if (racines.t1 > racines.t2)
		racines.t1 = racines.t2;
	t_vector3D intersect = ft_point_intersect_ray(ray.origin, ray.dir, racines.t1);
	if ((intersect.y < cone->base.origin.y) || (intersect.y > cone->base.origin.y + cone->height)) 
		return (-1);
	double tmp2 = sqrt(pow(intersect.x - cone->base.origin.x, 2) + pow(intersect.z - cone->base.origin.z, 2));
	cone->base.normale = ft_sous_vector(intersect, cone->base.origin);
	cone->base.normale.y = tmp2 * (cone->radius / cone->height);
    cone->base.normale = ft_normalize(cone->base.normale);
    return (racines.t1);
}

double		ft_intersect_square(t_ray ray, t_square *square)
{
	t_vector3D	intersect;
	t_plane		plane;
	double		t1;
	double		t2;

	plane.base = square->base;
	t1 = ft_intersect_plane(ray, &plane);
	if (t1 <= 0)
		return (-1);
	intersect = ft_point_intersect_ray(ray.origin, ray.dir, t1);
	intersect = ft_sous_vector(intersect, square->base.origin);
	t2 = square->height / 2;
	if (intersect.x < -t2 || intersect.x > t2 || intersect.y < -t2 || intersect.y > t2 || intersect.z < -t2 || intersect.z > t2)
		return (-1);
	square->base = plane.base;
	return (t1);
}



