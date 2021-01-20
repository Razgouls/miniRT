/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:42:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int				ft_rotation_camera(int keycode, t_scene *s)
{
	t_camera camera;

	camera = s->camera[s->current_camera];
	if (keycode == 'u')
		camera.vect_orient.y = camera.vect_orient.y + VALUE_ROTATION;
	else if (keycode == 'h')
		camera.vect_orient.x = camera.vect_orient.x - VALUE_ROTATION;
	else if (keycode == 'j')
		camera.vect_orient.y = camera.vect_orient.y - VALUE_ROTATION;
	else if (keycode == 'k')
		camera.vect_orient.x = camera.vect_orient.x + VALUE_ROTATION;
	else if (keycode == 'o')
		camera.vect_orient.x = camera.vect_orient.z + VALUE_ROTATION;
	else if (keycode == 'l')
		camera.vect_orient.z = camera.vect_orient.z - VALUE_ROTATION;
	camera.vect_orient.x = ft_clamp(camera.vect_orient.x, -1, 1);
	camera.vect_orient.y = ft_clamp(camera.vect_orient.y, -1, 1);
	camera.vect_orient.z = ft_clamp(camera.vect_orient.z, -1, 1);
	s->camera[s->current_camera] = camera;
	return (0);
}

int				ft_rotation_objects(int keycode, void *content)
{
	t_base_form *b;

	b = (t_base_form *)content;
	if (ft_strcmp(b->id, "tr") != 0 && ft_strcmp(b->id, "sp") != 0)
	{
		b->vect_orient = ft_rotate_vector(b->vect_orient, keycode);
		b->matrice = ft_init_matrice_rot(b->vect_orient, 0);
		b->inv_matrice = ft_init_matrice_rot(b->vect_orient, 1);
		content = (void *)b;
	}
	return (0);
}

t_vector		ft_rotate_vector(t_vector v, int keycode)
{
	t_vector tmp;

	if (keycode == 'h')
		tmp = ft_add_vector(v, ft_init_vector(0, 0, -VALUE_ROTATION));
	else if (keycode == 'u')
		tmp = ft_add_vector(v, ft_init_vector(VALUE_ROTATION, 0, 0));
	else if (keycode == 'k')
		tmp = ft_add_vector(v, ft_init_vector(0, 0, VALUE_ROTATION));
	else if (keycode == 'j')
		tmp = ft_add_vector(v, ft_init_vector(-VALUE_ROTATION, 0, 0));
	else if (keycode == 'o')
		tmp = ft_add_vector(v, ft_init_vector(0, -VALUE_ROTATION, 0));
	else if (keycode == 'l')
		tmp = ft_add_vector(v, ft_init_vector(0, VALUE_ROTATION, 0));
	tmp.x = ft_clamp(tmp.x, -1, 1);
	tmp.y = ft_clamp(tmp.y, -1, 1);
	tmp.z = ft_clamp(tmp.z, -1, 1);
	return (tmp);
}

double			ft_vect_orient_to_rad(t_vector vect_orient, int axe)
{
	if (axe == 1)
		return (PI * vect_orient.x);
	if (axe == 2)
		return (PI * vect_orient.y);
	if (axe == 3)
		return (PI * vect_orient.z);
	return (0);
}

t_matrice		ft_init_matrice_rot(t_vector vect_orient, int sign)
{
	t_vector	angle;
	t_matrice	m;

	angle.x = ft_vect_orient_to_rad(vect_orient, 1);
	angle.y = ft_vect_orient_to_rad(vect_orient, 2);
	angle.z = ft_vect_orient_to_rad(vect_orient, 3);
	if (sign == 1)
		angle = ft_multi_reel(angle, -1);
	m.v_x = ft_init_vector_2(cos(angle.y) * cos(angle.z), (sin(angle.x) *
		sin(angle.y) * cos(angle.z)) - (cos(angle.x) * sin(angle.z)),
		(cos(angle.x) * sin(angle.y) * cos(angle.z)) +
		(sin(angle.x) * sin(angle.z)), 0);
	m.v_y = ft_init_vector_2(cos(angle.y) * sin(angle.z), (sin(angle.x) *
		sin(angle.y) * sin(angle.z)) + (cos(angle.x) * cos(angle.z)),
		(cos(angle.x) * sin(angle.y) * sin(angle.z)) -
		(sin(angle.x) * cos(angle.z)), 0);
	m.v_z = ft_init_vector_2(-sin(angle.y), sin(angle.x) *
		cos(angle.y), cos(angle.x) * cos(angle.y), 0);
	m.v_p = ft_init_vector_2(0, 0, 0, 1);
	return (m);
}
