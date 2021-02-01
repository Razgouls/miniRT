/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raytracer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:04:21 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 09:05:14 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector			ft_get_light_at(t_ray ray, void *content,
						t_ray ray_light, t_light light)
{
	double		angle;
	double		c;
	t_vector	v;
	t_base_form	*b;

	b = (t_base_form *)content;
	v = ft_sous_vector(ray_light.o, ray.intersect);
	v = ft_normalize(v);
	c = ft_radian_to_degres((acos(ft_scalaire(b->normale, ray.dir)) /
		(ft_distance(b->normale) * ft_distance(ray.dir))));
	if (c < 90)
		return (ft_init_vector(0, 0, 0));
	angle = ft_scalaire(b->normale, v);
	if (angle < 0)
		return (ft_init_vector(0, 0, 0));
	else
	{
		v = ft_multi_vector(light.colors, b->colors);
		v = ft_multi_reel(v, angle);
		v = ft_multi_reel(v, light.ratio);
		return (v);
	}
}

void				*ft_select_obj(t_list *list, t_ray *ray)
{
	double	dis_tmp;
	double	dis;
	void	*object;

	dis = 10000;
	object = NULL;
	while (list)
	{
		dis_tmp = ft_intersect(*ray, list->content);
		if (dis_tmp < dis && dis_tmp > 0)
		{
			dis = dis_tmp;
			object = list->content;
		}
		list = list->next;
	}
	if (object)
		ray->intersect = ft_intersect_ray(ray->o, ray->dir, dis);
	return (object);
}

double				ft_select_light_inter(t_scene s,
						t_ray *ray_light, t_ray ray, void *obj)
{
	int			blocked;
	double		dist_object;
	void		*current_obj;
	double		t;

	blocked = 1;
	ray_light->dir = ft_sous_vector(ray.intersect,
		s.light[s.index_light - 1].origin);
	dist_object = ft_distance(ray_light->dir);
	ray_light->dir = ft_normalize(ray_light->dir);
	ray_light->o = s.light[s.index_light - 1].origin;
	while (s.list)
	{
		current_obj = s.list->content;
		if (current_obj != obj)
		{
			t = ft_intersect(*ray_light, current_obj);
			if (t < dist_object && t > 0)
				blocked = 0;
		}
		s.list = s.list->next;
	}
	return (blocked);
}

t_vector			ft_raytracer2(t_ray ray, t_scene s)
{
	void		*obj;
	t_list		*tmp_first_list;
	t_vector	colors;
	t_ray		ray_li;

	tmp_first_list = s.list;
	obj = ft_select_obj(tmp_first_list, &ray);
	colors = ft_multi_reel(s.ambient_light.colors, s.ambient_light.ratio);
	if (obj)
	{
		while (s.index_light > 0)
		{
			if (ft_select_light_inter(s, &ray_li, ray, obj))
			{
				colors = ft_add_vector(colors,
				ft_get_light_at(ray, obj, ray_li, s.light[s.index_light - 1]));
			}
			s.index_light -= 1;
		}
	}
	return (colors);
}

t_vector			ft_get_color(t_scene *s, int i, int j)
{
	t_vector	color;
	t_ray		ray;

	ray.o = s->camera[s->current_camera].origin;
	ray.dir = ft_normalize(ft_calcule_dir(s, i, j));
	color = ft_raytracer2(ray, *s);
	s->image.dat[s->reso.res[0] * j + i] = ft_change_color_to_pixel(
		ft_init_vector(color.x * 255, color.y * 255, color.z * 255));
	color = ft_init_vector(ft_clamp(color.x, 0, 1),
	ft_clamp(color.y, 0, 1), ft_clamp(color.z, 0, 1));
	return (color);
}
