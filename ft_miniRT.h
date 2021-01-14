/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:52:58 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/08 14:54:30 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_MINIRT_H
# define FT_MINIRT_H

#include "libft/libft.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <mlx.h>

#define X_RES 1200
#define Y_RES 600
#define VALUE_TRANSLATION 0.5
#define VALUE_TRANSLATION_LIGHTX 0
#define VALUE_TRANSLATION_LIGHTY 0
#define VALUE_TRANSLATION_LIGHTZ 0
#define VALUE_TRANSLATION_CAMERAX 0
#define VALUE_TRANSLATION_CAMERAY 0
#define VALUE_TRANSLATION_CAMERAZ 0


typedef struct			s_identifiant
{
	int					resolution;
	int					ambient_light;
}						t_identifiant;

typedef struct    		s_data
{
    void          		*mlx_ptr;
    void          		*mlx_win;
    void				*image;
    int 				pixel_bits;
	int 				line_bytes;
	int 				endian;
    unsigned int 		*buffer;
}                 		t_data;

typedef struct 			s_racine
{
	double				t1;
	double				t2;
}						t_racine;

typedef struct			s_vector3D
{
	double				x;
	double				y;
	double				z;
}						t_vector3D;
	
typedef struct			s_resolution
{
	char				id;
	int					res[2];
}						t_resolution;
	
typedef struct			s_ambient_light
{
	char				id;
	double				ratio;
	t_vector3D			colors;
}						t_ambient_light;
	
typedef struct			s_camera
{
	char				id;
	t_vector3D			viewPlaneUpLeft;
	t_vector3D			origin;
	t_vector3D			vect_orient;
	t_vector3D			right_vect;
	t_vector3D			up_vect;
	double				fov;
}						t_camera;
	
typedef struct			s_light
{
	char				id;
	t_vector3D			origin;
	double				ratio;
	t_vector3D			colors;
}						t_light;

typedef	struct			s_base_form
{
	char				id[3];
	t_vector3D			origin;
	t_vector3D			vect_orient;	
	t_vector3D			colors;
	t_vector3D			normale;
}						t_base_form;

typedef struct			s_sphere
{
	t_base_form			base;
	double				radius;
}						t_sphere;
	
typedef struct			s_plane
{
	t_base_form			base;
}						t_plane;
	
typedef struct			s_square
{
	t_base_form			base;
	double				height;
}						t_square;
	
typedef struct			s_cylindre
{
	t_base_form			base;
	double				radius;
	double				height;
}						t_cylindre;
	
typedef struct			s_triangle
{
	t_base_form			base;
	t_vector3D			p1;
	t_vector3D			p2;
	t_vector3D			p3;
}						t_triangle;

typedef struct 			s_cone
{
	t_base_form			base;
	double				radius;
	double				height;
}						t_cone;

typedef struct 			s_box
{
	t_plane				f1;
	t_plane 			f2;
	t_plane 			f3;
	t_plane 			f4;
	t_plane 			f5;
	t_plane 			f6;
}						t_box;


typedef struct			s_choose_object
{
	void				*current_object;
	int					last_keycode;
}						t_choose_object;

typedef struct			s_scene
{
	int 				index_cam;
	int 				index_light;
	int 				current_camera;
	double 				height;
	double 				width;
	t_resolution		resolution;
	t_ambient_light		ambient_light;
	t_camera			camera[10];
	t_light				light[10];
	t_list				*list;
	t_data				data;
	t_choose_object		choose_object;
}						t_scene;

typedef struct			s_ray
{
	t_vector3D			origin;
	t_vector3D			dir;
	t_vector3D			intersect;
}						t_ray;

typedef struct 			s_calc_tri
{
	t_vector3D			edge1;
	t_vector3D			edge2;
	double				a;
	double				b;
	double				c;
}						t_calc_tri;

int				ft_fill_res(char **strs, t_identifiant *id, t_scene *s);
int				ft_fill_ambient_light(char **strs, t_identifiant *id, t_scene *s);
int				ft_fill_camera(char **strs, t_scene *s);
int				ft_fill_light(char **strs, t_scene *s);
int				ft_fill_plane(char **strs, t_list **list);
int				ft_fill_sphere(char **strs, t_list **list);
int				ft_fill_square(char **strs, t_list **list);
int				ft_fill_cylindre(char **strs, t_list **list);
int				ft_fill_triangle(char **strs, t_list **list);
int				ft_fill_cone(char **strs, t_list **list);
void			ft_affiche_res(t_resolution resolution);
void			ft_affiche_ambient_light(t_ambient_light ambient_light);
void			ft_affiche_camera(t_camera camera);
void			ft_affiche_light(t_light light);
void			ft_affiche_plane(t_plane *list);
void			ft_affiche_sphere(t_sphere *list);
void			ft_affiche_square(t_square *list);
void			ft_affiche_cylindre(t_cylindre *list);
void			ft_affiche_triangle(t_triangle *list);
void			ft_affiche_cone(t_cone *cone);
int				ft_check_error_res(char **strs, int boolean);
int				ft_check_error_ambient(char **strs, int boolean);
int				ft_check_error_camera(char **strs);
int				ft_check_error_light(char **strs);
int				ft_check_error_sphere(char **strs);
int				ft_check_error_plane(char **strs);
int				ft_check_error_square(char **strs);
int				ft_check_error_cylindre(char **strs);
int				ft_check_error_triangle(char **strs);
int				ft_printf_error_colors(char **strs, char **colors, int index);
int				ft_printf_error_origin(char **origin, int index);
int				ft_printf_error_vector(char **origin);
void			ft_fill_base(char **strs, t_base_form *base);
void			ft_fill_base_color(char **colors, t_vector3D *colors_t);
void			ft_fill_base_origin(char **coordo, t_vector3D *origin);
int				ft_clear(t_list **list, char **strs);
int				ft_init_window(t_scene *s);
t_vector3D		ft_multi_reel(t_vector3D p1, double p2);
t_vector3D		ft_add_vector(t_vector3D p1, t_vector3D p2);
t_vector3D		ft_multi_vector(t_vector3D p1, t_vector3D p2);
t_vector3D		ft_sous_vector(t_vector3D p1, t_vector3D p2);
t_vector3D		ft_divi_reel(t_vector3D p1, double p2);
t_vector3D		ft_calculer_viewplane_up_left(double width, double height, int dis, t_scene *s);
t_vector3D		ft_calcule_dir(t_scene *s, int x, int y);
double			ft_intersect(t_ray ray, void *content);
double			ft_intersect_sphere(t_ray ray, t_sphere *sphere);
double			ft_intersect_plane(t_ray ray, t_plane *plane);
double			ft_intersect_triangle(t_ray ray, t_triangle *triangle);
double			ft_intersect_cylindre(t_ray ray, t_cylindre *cylindre);
double			ft_intersect_cone(t_ray ray, t_cone *cone);
double			ft_intersect_square(t_ray ray, t_square *square);
t_vector3D		ft_point_intersect_ray(t_vector3D o, t_vector3D dir, double t);
t_vector3D		ft_init_vector(double x, double y, double z);
t_vector3D		ft_normalize(t_vector3D v);
double			ft_distance(t_vector3D v);
double			ft_scalaire(t_vector3D v1, t_vector3D v2);
unsigned int	ft_change_color(t_vector3D color);
double			ft_clamp(double value, double min, double max);
double			ft_vect(t_vector3D v1, t_vector3D v2);
double			ft_determinant(double a, double b, double c);
t_vector3D		ft_cross_product(t_vector3D v1, t_vector3D v2);
t_vector3D		ft_calc_base_top(t_vector3D origin, double height);
double			ft_orient(t_vector3D a, t_vector3D b, t_vector3D c, t_vector3D n);
int             ft_translation_camera(int keycode, t_scene *s);
int             ft_translation_objects(int keycode, void *content);
int             ft_check_object_select(int keycode, t_scene *s);
int     		ft_give_i(int keycode);
int             ft_close_mouse(t_scene *s);
t_vector3D      ft_translate_vector(t_vector3D v, int keycode);
void			ft_affichage_vector(t_vector3D v);
double			ft_determinant_matrice(t_vector3D v1, t_vector3D v2);
double			ft_aire_tr(t_vector3D a, t_vector3D b, t_vector3D c);
#endif
