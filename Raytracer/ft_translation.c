/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intersect_sphere.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:03:30 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/16 12:03:32 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

int             ft_translation_camera(int keycode, t_scene *s)
{
    t_camera camera;

    camera = s->camera[s->current_camera];
    if (keycode == 'a')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(-VALUE_TRANSLATION, 0, 0));
    else if (keycode == 'w')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(0, VALUE_TRANSLATION, 0));
    else if (keycode == 'd')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(VALUE_TRANSLATION, 0, 0));
    else if (keycode == 's')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(0, -VALUE_TRANSLATION, 0));
    else if (keycode == 'r')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(0, 0, VALUE_TRANSLATION));
    else if (keycode == 'f')
        camera.origin = ft_add_vector(camera.origin, ft_init_vector(0, 0, -VALUE_TRANSLATION));
    s->camera[s->current_camera] = camera;
    return (0);
}

int             ft_check_object_select(int keycode, t_scene *s)
{
    int     index;
    int     i;
    void    *content;
    t_list  *tmp_list;

    tmp_list = s->list;
    index = -1;
    i = ft_give_i(keycode);
    while (tmp_list && ++index <= i)
    {
        content = tmp_list->content;
        tmp_list = tmp_list->next;
    }
    s->choose_object.current_object = content;
    s->choose_object.last_keycode = keycode;
    return (0);
}

int             ft_translation_objects(int keycode, void *content)
{
    t_base_form *b;
    t_triangle  *tr;

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

t_vector3D      ft_translate_vector(t_vector3D v, int keycode)
{
    t_vector3D tmp;

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
    else //f
        tmp = ft_add_vector(v, ft_init_vector(0, 0, -VALUE_TRANSLATION));
    return (tmp);
}
