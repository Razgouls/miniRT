/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:04:08 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/27 10:24:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector		ft_view(double height, t_scene *s)
{
	t_vector		view;

	view = ft_multi_reel(s->camera[s->current_camera].vect_orient, 1);
	view = ft_add_vector(view, ft_multi_reel(
			s->camera[s->current_camera].up_vect, height * 0.5));
	view = ft_add_vector(view, s->camera[s->current_camera].origin);
	view = ft_sous_vector(view, ft_multi_reel(
		s->camera[s->current_camera].right_vect, 0.5));
	return (view);
}

t_vector		ft_calcule_dir(t_scene *s, int x, int y)
{
	double		x_indentx;
	double		y_indenty;
	t_vector	dir;
	double		angle;

	x_indentx = (s->width / s->reso.res[0]) * x;
	y_indenty = (s->height / s->reso.res[1]) * y;
	dir = ft_multi_reel(s->camera[s->current_camera].right_vect, x_indentx);
	dir = ft_add_vector(dir, s->camera[s->current_camera].viewPlaneUpLeft);
	dir = ft_sous_vector(dir,
		ft_multi_reel(s->camera[s->current_camera].up_vect, y_indenty));
	dir = ft_sous_vector(dir, s->camera[s->current_camera].origin);
	angle = s->camera[s->current_camera].fov * PI / 180;
	dir.z *= (angle * 0.5);
	return (dir);
}
