/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_translation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:26:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int				ft_translation_camera(int keycode, t_scene *s)
{
	t_camera	camera;

	camera = s->camera[s->current_camera];
	if (keycode == 'a')
		camera.origin.x = camera.origin.x - VALUE_TRANSLATION;
	else if (keycode == 'w')
		camera.origin.y = camera.origin.y + VALUE_TRANSLATION;
	else if (keycode == 'd')
		camera.origin.x = camera.origin.x + VALUE_TRANSLATION;
	else if (keycode == 's')
		camera.origin.y = camera.origin.y - VALUE_TRANSLATION;
	else if (keycode == 'r')
		camera.origin.z = camera.origin.z + VALUE_TRANSLATION;
	else if (keycode == 'f')
		camera.origin.z = camera.origin.z - VALUE_TRANSLATION;
	s->camera[s->current_camera] = camera;
	return (0);
}

int				ft_translation_objects(int keycode, void *content)
{
	t_base_form		*b;
	t_triangle		*tr;

	b = (t_base_form *)content;
	if (ft_strcmp(b->id, "tr") == 0)
	{
		tr = (t_triangle *)content;
		tr->p1 = ft_translate_vector(tr->p1, keycode);
		tr->p2 = ft_translate_vector(tr->p2, keycode);
		tr->p3 = ft_translate_vector(tr->p3, keycode);
		content = (void *)tr;
	}
	else
	{
		b->origin = ft_translate_vector(b->origin, keycode);
		content = (void *)b;
	}
	return (0);
}

t_vector		ft_translate_vector(t_vector v, int keycode)
{
	t_vector		tmp;

	if (keycode == 'a')
		tmp = ft_add_vector(v, ft_init_vector(-VALUE_TRANSLATION, 0, 0));
	else if (keycode == 'w')
		tmp = ft_add_vector(v, ft_init_vector(0, VALUE_TRANSLATION, 0));
	else if (keycode == 'd')
		tmp = ft_add_vector(v, ft_init_vector(VALUE_TRANSLATION, 0, 0));
	else if (keycode == 's')
		tmp = ft_add_vector(v, ft_init_vector(0, -VALUE_TRANSLATION, 0));
	else if (keycode == 'r')
		tmp = ft_add_vector(v, ft_init_vector(0, 0, VALUE_TRANSLATION));
	else
		tmp = ft_add_vector(v, ft_init_vector(0, 0, -VALUE_TRANSLATION));
	return (tmp);
}

t_matrice		ft_init_matrice_trans(t_vector trans, int sign)
{
	t_matrice	m;

	if (sign == 1)
		trans = ft_multi_reel(trans, -1);
	m.v_x = ft_init_vector_2(1, 0, 0, trans.x);
	m.v_y = ft_init_vector_2(0, 1, 0, trans.y);
	m.v_z = ft_init_vector_2(0, 0, 1, trans.z);
	m.v_p = ft_init_vector_2(0, 0, 0, 1);
	return (m);
}

t_vector		ft_trans_orient(t_ray ray, void *content)
{
	t_base_form		*base;
	t_vector		new_origin;
	t_vector		new_orient;
	t_vector		new_dir;

	base = (t_base_form *)content;
	new_origin = ft_multi_mat_vect(base->inv_matrice, ft_init_vector(0, 0, 0));
	new_orient = ft_multi_mat_vect(base->inv_matrice, ray.dir);
	new_dir = ft_sous_vector(new_orient, new_origin);
	return (new_dir);
}
