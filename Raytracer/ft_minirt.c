/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:10:26 by elieolive         #+#    #+#             */
/*   Updated: 2021/01/22 18:33:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

unsigned int	ft_change_color(t_vector color)
{
	unsigned char	rgb[3];
	unsigned int	res;

	rgb[0] = (unsigned char)(color.x * 255);
	rgb[1] = (unsigned char)(color.y * 255);
	rgb[2] = (unsigned char)(color.z * 255);
	res = (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
	return (res);
}

static int		ft_close_clavier(int keycode, t_scene *s)
{
	if (ft_check_keycode(keycode) == 1)
		ft_check_object_select(keycode, s);
	else if (ft_check_keycode(keycode) == 2 &&
		ft_check_keycode(s->choose_object.last_keycode) == 1)
		ft_translation_objects(keycode, s->choose_object.current_object);
	else if (ft_check_keycode(keycode) == 3 &&
		ft_check_keycode(s->choose_object.last_keycode) == 1)
		ft_rotation_objects(keycode, s->choose_object.current_object);
	else if (ft_check_keycode(keycode) == 2)
		ft_translation_camera(keycode, s);
	else if (ft_check_keycode(keycode) == 3)
		ft_rotation_camera(keycode, s);
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
	ft_raytracer(s);
	return (0);
}

int				ft_close_mouse(t_scene *s)
{
	mlx_clear_window(s->data.mlx_ptr, s->data.mlx_win);
	mlx_destroy_window(s->data.mlx_ptr, s->data.mlx_win);
	exit(0);
	return (0);
}

int					ft_raytracer(t_scene *s)
{
	int			i;
	int			j;

	j = -1;
	s->camera[s->current_camera].view = ft_calc_view(s->width, s->height, 1, s);
	s->image.h = 400;
	s->image.w = 400;
	s->image.dat = malloc(sizeof(Pixel) * s->image.w * s->image.h);
	while (++j < s->reso.res[1])
	{
		i = -1;
		while (++i < s->reso.res[0])
			s->data.buffer[j * s->reso.res[0] + i] = ft_change_color(ft_get_color(s, i, j));
	}
	export_bmp(*s);
	mlx_put_image_to_window(s->data.mlx_ptr,
		s->data.mlx_win, s->data.image, 0, 0);
	mlx_loop(s->data.mlx_ptr);
	return (0);
}

int				ft_init_window(t_scene *s)
{
	t_data		data;

	if (s->reso.res[0] > X_RES || s->reso.res[0] < 0)
		s->reso.res[0] = X_RES;
	if (s->reso.res[1] > Y_RES || s->reso.res[1] < 0)
		s->reso.res[1] = Y_RES;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr,
		s->reso.res[0], s->reso.res[1], "MiniRT")) == NULL)
		return (EXIT_FAILURE);
	data.image = mlx_new_image(data.mlx_ptr, s->reso.res[0], s->reso.res[1]);
	mlx_key_hook(data.mlx_win, ft_close_clavier, s);
	mlx_hook(data.mlx_win, 33, 1L << 17, ft_close_mouse, s);
	data.buffer = (unsigned int *)mlx_get_data_addr(data.image,
		&data.pixel_bits, &data.line_bytes, &data.endian);
	s->width = 1;
	s->height = (float)s->reso.res[1] / s->reso.res[0];
	s->data = data;
	ft_raytracer(s);
	free(s->image.dat);
	return (EXIT_SUCCESS);
}
