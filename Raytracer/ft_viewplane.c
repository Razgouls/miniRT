/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:04:08 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/16 12:04:09 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

t_vector3D		ft_calculer_viewplane_up_left(double width, double height, int dis, t_scene *s)
{
	t_vector3D		viewPlaneUpLeft;

	viewPlaneUpLeft = ft_multi_reel(s->camera[s->current_camera].vect_orient, dis);
	viewPlaneUpLeft = ft_add_vector(viewPlaneUpLeft, ft_multi_reel(s->camera[s->current_camera].up_vect, (height / 2.0)));
	viewPlaneUpLeft = ft_add_vector(viewPlaneUpLeft, s->camera[s->current_camera].origin);
	viewPlaneUpLeft = ft_sous_vector(viewPlaneUpLeft, ft_multi_reel(s->camera[s->current_camera].right_vect, (width / 2.0)));
	return (viewPlaneUpLeft);
}

t_vector3D		ft_calcule_dir(t_scene *s, int x, int y)
{
	double		x_indentx;
	double		y_indenty;
	t_vector3D	dir;

	x_indentx = (s->width / s->resolution.res[0]) * x;
	y_indenty = (s->height / s->resolution.res[1]) * y;

	dir = ft_multi_reel(s->camera[s->current_camera].right_vect, x_indentx);
	dir = ft_add_vector(dir, s->camera[s->current_camera].viewPlaneUpLeft);
	dir = ft_sous_vector(dir, ft_multi_reel(s->camera[s->current_camera].up_vect, y_indenty));
	dir = ft_sous_vector(dir, s->camera[s->current_camera].origin);
    return (dir);
}
