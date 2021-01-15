/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_parser_res_aligth.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 17:21:47 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/15 11:36:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

int		ft_fill_res(char **strs, t_identifiant *id, t_scene *s)
{
	t_resolution	reso;

	if (ft_check_error_res(strs, id->resolution))
	{
		ft_free_tab(strs);
		return (1);
	}
	reso.id = strs[0][0];
	id->resolution = 1;
	reso.res[0] = ft_atoi(strs[1]);
	reso.res[1] = ft_atoi(strs[2]);
	s->resolution = reso;
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_ambient_light(char **strs, t_identifiant *id, t_scene *s)
{
	t_ambient_light	ambient_light;

	if (ft_check_error_ambient(strs, id->ambient_light))
	{
		ft_free_tab(strs);
		return (1);
	}
	ambient_light.id = strs[0][0];
	id->ambient_light = 1;
	ambient_light.ratio = ft_atof(strs[1]);
	ft_fill_base_color(ft_split(strs[2], ','), &ambient_light.colors);
	s->ambient_light = ambient_light;
	ft_free_tab(strs);
	return (0);
}

int				ft_fill_camera(char **strs, t_scene *s)
{
	t_camera	camera;
	int			i;

	i = 0;
	if (ft_check_error_camera(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	camera.id = strs[0][0];
	ft_fill_base_vector(ft_split(strs[1], ','), &camera.origin);
	ft_fill_base_vector(ft_split(strs[2], ','), &camera.vect_orient);
	camera.origin = ft_add_vector(camera.origin, ft_init_vector(VALUE_TRANSLATION_CAMERAX, VALUE_TRANSLATION_CAMERAY, VALUE_TRANSLATION_CAMERAZ));
	camera.fov = ft_atof(strs[3]);
	camera.right_vect = ft_init_vector(1.0, 0.0, 0.0);
	camera.up_vect = ft_init_vector(0.0, 1.0, 0.0);
	s->camera[s->index_cam] = camera;
	s->index_cam += 1;
	ft_free_tab(strs);
	return (0);
}

int				ft_fill_light(char **strs, t_scene *s)
{
	t_light	light;

	if (ft_check_error_light(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	light.id = strs[0][0];
	ft_fill_base_vector(ft_split(strs[1], ','),  &light.origin);
	light.origin = ft_add_vector(light.origin, ft_init_vector(VALUE_TRANSLATION_LIGHTX, VALUE_TRANSLATION_LIGHTY, VALUE_TRANSLATION_LIGHTZ));
	light.ratio = ft_atof(strs[2]);
	ft_fill_base_color(ft_split(strs[3], ','), &light.colors);
	s->light[s->index_light] = light;
	s->index_light += 1;
	ft_free_tab(strs);
	return (0);
}