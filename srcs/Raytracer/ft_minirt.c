/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minirt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:10:26 by elieolive         #+#    #+#             */
/*   Updated: 2021/02/01 16:35:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

unsigned int		ft_change_color(t_vector color)
{
	unsigned char	rgb[3];
	unsigned int	res;

	rgb[0] = (unsigned char)(color.x * 255);
	rgb[1] = (unsigned char)(color.y * 255);
	rgb[2] = (unsigned char)(color.z * 255);
	res = (rgb[0] << 16) | (rgb[1] << 8) | (rgb[2]);
	return (res);
}

int					ft_raytracer(t_scene *s)
{
	int			i;
	int			j;

	j = -1;
	s->image.h = s->reso.res[1];
	s->image.w = s->reso.res[0];
	if (!(s->image.dat = malloc(sizeof(t_pixel) * s->image.w * s->image.h)))
		return (0);
	s->camera[s->current_camera].view = ft_view(s->height, s);
	while (++j < s->reso.res[1])
	{
		i = -1;
		while (++i < s->reso.res[0])
			s->data.buffer[j *
				s->reso.res[0] + i] = ft_change_color(ft_get_color(s, i, j));
	}
	if (s->check_save)
		export_bmp(*s);
	mlx_put_image_to_window(s->data.mlx_ptr,
		s->data.mlx_win, s->data.image, 0, 0);
	mlx_hook(s->data.mlx_win, 33, 1L << 17, ft_close_mouse, s);
	mlx_loop(s->data.mlx_ptr);
	return (0);
}

int					ft_init_window(t_scene *s)
{
	t_data		data;

	if (s->reso.res[0] > X_RES || s->reso.res[0] <= 0)
		s->reso.res[0] = X_RES;
	if (s->reso.res[1] > Y_RES || s->reso.res[1] <= 0)
		s->reso.res[1] = Y_RES;
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr,
		s->reso.res[0], s->reso.res[1], "MiniRT")) == NULL)
		return (EXIT_FAILURE);
	data.image = mlx_new_image(data.mlx_ptr, s->reso.res[0], s->reso.res[1]);
	mlx_key_hook(data.mlx_win, ft_close_clavier, s);
	data.buffer = (unsigned int *)mlx_get_data_addr(data.image,
		&data.pixel_bits, &data.line_bytes, &data.endian);
	s->data = data;
	s->width = 1;
	s->height = (float)s->reso.res[1] / s->reso.res[0];
	ft_raytracer(s);
	free(s->image.dat);
	return (EXIT_SUCCESS);
}
