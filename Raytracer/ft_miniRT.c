/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elieoliveira <eoliveir@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 15:10:26 by elieolive         #+#    #+#             */
/*   Updated: 2020/12/12 15:10:27 by elieolive        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

t_vector3D      ft_get_light_at(void *content, t_vector3D intersect, t_ray ray_light, t_vector3D color_light)
{
    double      angle;
    t_vector3D  vector;
    t_base_form *b;

    b = (t_base_form *)content;
    vector = ft_sous_vector(ray_light.origin, intersect);
    vector = ft_normalize(vector);
    angle = ft_vect(b->normale, vector);
    if (angle <= 0)
        return (ft_init_vector(0, 0, 0));
    else
    {
        vector = ft_multi_vector(color_light, b->colors);
        vector = ft_multi_reel(vector, angle);
        return (vector);
    }
}

t_vector3D      ft_raytracer2(t_ray ray, t_scene s)
{
    double      dis;
    double      dis_tmp;
    void        *object;
    void        *tmp_first_list;
    t_vector3D  colors;
    t_vector3D  intersect;
    double      dist_object;
    t_ray       ray_light;
    void        *current_obj;
    int         blocked;

    dis = 100000;
    object = NULL;
    tmp_first_list = s.list;
    while (s.list)
    {
        dis_tmp = ft_intersect(ray, s.list->content);
        if (dis_tmp < dis && dis_tmp > 0)
        {
            dis = dis_tmp;
            object = s.list->content;
        }
        s.list = s.list->next;
    }
    intersect = ft_point_intersect_ray(ray.origin, ray.dir, dis);
    colors = ft_multi_reel(s.ambient_light.colors, s.ambient_light.ratio);
    if (object)
    {
        while (s.index_light > 0)
        {
            blocked = 1;
            s.list = tmp_first_list;
            ray_light.dir = ft_sous_vector(intersect, s.light[s.index_light - 1].origin);
            dist_object = ft_distance(ray_light.dir);
            ray_light.dir = ft_normalize(ray_light.dir);
            ray_light.origin = s.light[s.index_light - 1].origin;
            while (s.list)
            {
                current_obj = s.list->content;
                if (current_obj != object)
                {
                    double t = ft_intersect(ray_light, current_obj);
                    if (t < dist_object && t > 0)
                        blocked = 0;
                }
                s.list = s.list->next;
            }
            if (blocked)
            {
                t_vector3D v;
                v = ft_get_light_at(object, intersect, ray_light, s.light[s.index_light - 1].colors);
                colors = ft_add_vector(colors, v);
            }
            s.index_light -= 1;
        }
    }
    return (colors);
}

int             ft_raytracer(t_scene *s)
{
    void        *object;
    int         i;
    int         j;
    t_vector3D  color;
    t_ray       ray;

    j = 0;
    object = NULL;
    s->camera[s->current_camera].viewPlaneUpLeft = ft_calculer_viewplane_up_left(s->width, s->height, 1, s);
    while (j < s->resolution.res[1])
    {
        i = 0;
        while (i < s->resolution.res[0])
        {
            ray.origin = s->camera[s->current_camera].origin;
            ray.dir = ft_calcule_dir(s, i, j);
            ray.dir = ft_normalize(ray.dir);
            color = ft_raytracer2(ray, *s);
            color = ft_init_vector(ft_clamp(color.x, 0, 1), ft_clamp(color.y, 0, 1), ft_clamp(color.z, 0, 1));
            s->data.buffer[j * s->resolution.res[0] + i] = ft_change_color(color); 
            i++;
        }
        j++;
    }
    mlx_put_image_to_window(s->data.mlx_ptr, s->data.mlx_win, s->data.image, 0, 0);
    mlx_loop(s->data.mlx_ptr);
    return (0);
}

unsigned int  ft_change_color(t_vector3D color)
{
    unsigned char   rgb[3];
    unsigned int    res;

    rgb[0] = (unsigned char)(color.x * 255);
    rgb[1] = (unsigned char)(color.y * 255);
    rgb[2] = (unsigned char)(color.z * 255);
    res = (rgb[0]<<16) | (rgb[1]<<8) | (rgb[2]);
    return (res); 
}

int             ft_check_keycode(int keycode)
{
    if (keycode == '1' || keycode == '2' || keycode == '3' || keycode == '4' || keycode == '5' || keycode == '6' || keycode == '7' || keycode == '8' || keycode == '9')
        return (1);
    else if (keycode == 'a' || keycode == 'w' || keycode == 'd' || keycode == 's' || keycode == 'r' || keycode == 'f')
        return (2);
    return (0);
}

int             close_clavier(int keycode, t_scene *s)
{
    if  (ft_check_keycode(keycode) == 1)
        ft_check_object_select(keycode, s);
    else if (ft_check_keycode(keycode) == 2 && ft_check_keycode(s->choose_object.last_keycode) == 1)
        ft_translation_objects(keycode, s->choose_object.current_object);
    else if (ft_check_keycode(keycode) == 2)
        ft_translation_camera(keycode, s);
    else if (keycode == 65307 && ft_check_keycode(s->choose_object.last_keycode) == 1)
        s->choose_object.last_keycode = -1;
    else if (keycode == 65307)
        ft_close_mouse(s);
    else if (keycode == 65361 && s->current_camera - 1 >= 0)
        s->current_camera -= 1;
    else if (keycode == 65363 && s->current_camera + 1 < s->index_cam)
        s->current_camera += 1;
    s->data.buffer = (unsigned int *)mlx_get_data_addr(s->data.image, &s->data.pixel_bits, &s->data.line_bytes, &s->data.endian);
    ft_raytracer(s);
    return (0);
}

int             ft_close_mouse(t_scene *s)
{
    mlx_clear_window(s->data.mlx_ptr, s->data.mlx_win);
    mlx_destroy_window(s->data.mlx_ptr, s->data.mlx_win);
    exit(0);
    return (0);
}

int             ft_init_window(t_scene *s)
{
    t_data      data;

    if (s->resolution.res[0] > X_RES || s->resolution.res[0] < 0)
        s->resolution.res[0] = X_RES;
    if (s->resolution.res[1] > Y_RES || s->resolution.res[1] < 0)
        s->resolution.res[1] = Y_RES;
    if ((data.mlx_ptr = mlx_init()) == NULL)
        return (EXIT_FAILURE);
    if ((data.mlx_win = mlx_new_window(data.mlx_ptr, s->resolution.res[0], s->resolution.res[1], "MiniRT")) == NULL)
        return (EXIT_FAILURE);
    data.image = mlx_new_image(data.mlx_ptr, s->resolution.res[0], s->resolution.res[1]);
    mlx_key_hook(data.mlx_win, close_clavier, s);
    mlx_hook(data.mlx_win, 17, 1L<<17, ft_close_mouse, s);
    data.buffer = (unsigned int *)mlx_get_data_addr(data.image, &data.pixel_bits, &data.line_bytes, &data.endian);
    s->width = 1;
    s->height = (float)s->resolution.res[1] / s->resolution.res[0];
    s->data = data;
    ft_raytracer(s);
    return (EXIT_SUCCESS);
}