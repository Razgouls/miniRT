/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/18 13:43:18 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

int             ft_rotation_camera(int keycode, t_scene *s)
{
    t_camera camera;

    camera = s->camera[s->current_camera];
    if (keycode == 'u')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(0, VALUE_ROTATION, 0));
    else if (keycode == 'h')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(-VALUE_ROTATION, 0, 0));
    else if (keycode == 'j')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(0, -VALUE_ROTATION, 0));
    else if (keycode == 'k')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(VALUE_ROTATION, 0, 0));
    else if (keycode == 'o')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(0, 0, VALUE_ROTATION));
    else if (keycode == 'l')
        camera.vect_orient = ft_add_vector(camera.vect_orient, ft_init_vector(0, 0, -VALUE_ROTATION));
    camera.vect_orient.x = ft_clamp(camera.vect_orient.x, -1, 1);
    camera.vect_orient.y = ft_clamp(camera.vect_orient.y, -1, 1);
    camera.vect_orient.z = ft_clamp(camera.vect_orient.z, -1, 1);
    s->camera[s->current_camera] = camera;
    return (0);
}

int             ft_rotation_objects(int keycode, void *content)
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

t_vector3D      ft_rotate_vector(t_vector3D v, int keycode)
{
    t_vector3D tmp;

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
