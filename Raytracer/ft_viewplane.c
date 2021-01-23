/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_viewplane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:04:08 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/23 10:33:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

t_vector		ft_calcule_dir(t_scene *s, int x, int y)
{
	t_vector	dir;
	double		angle;

	angle = s->camera[s->current_camera].fov * PI / 180;
	dir.x = x - s->reso.res[0] * 0.5;
	dir.y = s->reso.res[1] * 0.5 - y;
	dir.z = (s->reso.res[1] * 0.5) / (angle * 0.5);
	return (dir);
}
