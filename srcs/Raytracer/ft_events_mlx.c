/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_events_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:31:41 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 16:34:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			ft_close_clavier_aux(int keycode, t_scene *s)
{
	if (ft_check_keycode(keycode) == 2 &&
		ft_check_keycode(s->choose_object.last_keycode) == 1)
	{
		ft_translation_objects(keycode, s->choose_object.current_object);
		return (1);
	}
	else if (ft_check_keycode(keycode) == 3 &&
		ft_check_keycode(s->choose_object.last_keycode) == 1)
	{
		ft_rotation_objects(keycode, s->choose_object.current_object);
		return (1);
	}
	else if (ft_check_keycode(keycode) == 2)
	{
		ft_translation_camera(keycode, s);
		return (1);
	}
	else if (ft_check_keycode(keycode) == 3)
	{
		ft_rotation_camera(keycode, &(s->camera[s->current_camera]));
		return (1);
	}
	return (0);
}

int			ft_close_clavier(int keycode, t_scene *s)
{
	if (ft_check_keycode(keycode) == 1)
		ft_check_object_select(keycode, s);
	else if (ft_close_clavier_aux(keycode, s))
	{
		s->data.buffer = (unsigned int *)mlx_get_data_addr(s->data.image,
			&s->data.pixel_bits, &s->data.line_bytes, &s->data.endian);
		free(s->image.dat);
		ft_raytracer(s);
		return (0);
	}
	else if (keycode == 65307 &&
		ft_check_keycode(s->choose_object.last_keycode) == 1)
		s->choose_object.last_keycode = -1;
	else if (keycode == 65307)
		ft_close_mouse(s);
	else if (keycode == 65361 && s->current_camera - 1 >= 0)
		s->current_camera -= 1;
	else if (keycode == 65363 && s->current_camera + 1 < s->index_cam)
		s->current_camera += 1;
	s->data.buffer = (unsigned int *)mlx_get_data_addr(s->data.image,
		&s->data.pixel_bits, &s->data.line_bytes, &s->data.endian);
	free(s->image.dat);
	ft_raytracer(s);
	return (0);
}

int			ft_close_mouse(t_scene *s)
{
	mlx_clear_window(s->data.mlx_ptr, s->data.mlx_win);
	mlx_destroy_window(s->data.mlx_ptr, s->data.mlx_win);
	exit(0);
	return (0);
}
