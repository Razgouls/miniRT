/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:04:08 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:27:01 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector		ft_calc_view(double width,
					double height, int dis, t_scene *s)
{
	t_vector		v;

	v = ft_multi_reel(s->camera[s->current_camera].vect_orient, dis);
	v = ft_add_vector(v,
		ft_multi_reel(s->camera[s->current_camera].up_vect, (height / 2.0)));
	v = ft_add_vector(v,
		s->camera[s->current_camera].origin);
	v = ft_sous_vector(v,
		ft_multi_reel(s->camera[s->current_camera].right_vect, (width / 2.0)));
	return (v);
}

t_vector		ft_calcule_dir(t_scene *s, int x, int y)
{
	double		x_indentx;
	double		y_indenty;
	t_vector	dir;

	x_indentx = (s->width / s->reso.res[0]) * x;
	y_indenty = (s->height / s->reso.res[1]) * y;
	dir = ft_multi_reel(s->camera[s->current_camera].right_vect, x_indentx);
	dir = ft_add_vector(dir, s->camera[s->current_camera].view);
	dir = ft_sous_vector(dir,
		ft_multi_reel(s->camera[s->current_camera].up_vect, y_indenty));
	dir = ft_sous_vector(dir,
		s->camera[s->current_camera].origin);
	return (dir);
}
