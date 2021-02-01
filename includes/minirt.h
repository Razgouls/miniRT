/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 13:52:58 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/27 10:27:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../libft/includes/libft.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include "mlx.h"

# define X_RES 2000
# define Y_RES 1200
# define VALUE_TRANSLATION 0.5
# define VALUE_ROTATION 0.05
# define VALUE_TRANSLATION_LIGHTX 0
# define VALUE_TRANSLATION_LIGHTY 0
# define VALUE_TRANSLATION_LIGHTZ 0
# define VALUE_TRANSLATION_CAMERAX 0
# define VALUE_TRANSLATION_CAMERAY 0
# define VALUE_TRANSLATION_CAMERAZ 0
# define PI 3.14159265358979

typedef struct			s_pixel
{
	unsigned char		r;
	unsigned char		g;
	unsigned char		b;
}						t_pixel;

typedef struct			s_image
{
	int					w;
	int					h;
	t_pixel				*dat;
}						t_image;

typedef struct			s_identifiant
{
	int					resolution;
	int					ambient_light;
}						t_identifiant;

typedef struct			s_data
{
	void				*mlx_ptr;
	void				*mlx_win;
	void				*image;
	int					pixel_bits;
	int					line_bytes;
	int					endian;
	unsigned int		*buffer;
}						t_data;

typedef struct			s_racine
{
	double				t1;
	double				t2;
}						t_racine;

typedef struct			s_vector
{
	double				x;
	double				y;
	double				z;
}						t_vector;

typedef	struct			s_vectorf
{
	double				x;
	double				y;
	double				z;
	double				t;
}						t_vectorf;

typedef struct			s_material
{
	t_vector			ambiente;
	t_vector			diffuse;
	t_vector			speculaire;
}						t_material;

typedef struct			s_matrice
{
	t_vectorf			v_x;
	t_vectorf			v_y;
	t_vectorf			v_z;
	t_vectorf			v_p;
}						t_matrice;

typedef struct			s_resolution
{
	char				id;
	int					res[2];
}						t_resolution;

typedef struct			s_ambient_light
{
	char				id;
	double				ratio;
	t_vector			colors;
}						t_ambient_light;

typedef struct			s_camera
{
	char				id;
	t_vector			origin;
	t_vector			vect_orient;
	t_vector			right_vect;
	t_vector			up_vect;
	t_matrice			matrice;
	t_vector			viewPlaneUpLeft;
	t_matrice			inv_matrice;
	double				fov;
}						t_camera;

typedef struct			s_light
{
	char				id;
	t_vector			origin;
	double				ratio;
	t_vector			colors;
}						t_light;

typedef	struct			s_base_form
{
	char				id[3];
	t_vector			origin;
	t_vector			vect_orient;
	t_vector			colors;
	t_vector			normale;
	t_matrice			matrice;
	t_matrice			inv_matrice;
	t_material			material;
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
	t_vector			p1;
	t_vector			p2;
	t_vector			p3;
}						t_triangle;

typedef struct			s_cone
{
	t_base_form			base;
	double				radius;
	double				height;
}						t_cone;

typedef struct			s_ray
{
	t_vector			o;
	t_vector			dir;
	t_vector			intersect;
}						t_ray;

typedef	struct			s_inter
{
	int					inv_normale;
	void				*content;
	double				t1;
	double				t2;
	double				det;
	t_ray				ray;
	t_vector			inter;
	t_vector			abc;
}						t_inter;

typedef struct			s_box
{
	t_plane				f1;
	t_plane				f2;
	t_plane				f3;
	t_plane				f4;
	t_plane				f5;
	t_plane				f6;
}						t_box;

typedef struct			s_choose_object
{
	void				*current_object;
	int					last_keycode;
}						t_choose_object;

typedef struct			s_scene
{
	int					index_cam;
	int					index_light;
	int					current_camera;
	double				height;
	double				width;
	t_resolution		reso;
	t_ambient_light		ambient_light;
	t_camera			camera[10];
	t_light				light[10];
	t_list				*list;
	t_data				data;
	t_choose_object		choose_object;
	t_image				image;
	int					check_save;
}						t_scene;

typedef struct			s_calc_tri
{
	t_vector			edge1;
	t_vector			edge2;
	double				a;
	double				b;
	double				c;
}						t_calc_tri;

int						ft_fill_res(char **strs, t_identifiant *id, t_scene *s);
int						ft_fill_ambient_light(char **strs,
							t_identifiant *id, t_scene *s);
int						ft_fill_camera(char **strs, t_scene *s);
int						ft_fill_light(char **strs, t_scene *s);
int						ft_fill_plane(char **strs, t_list **list);
int						ft_fill_sphere(char **strs, t_list **list);
int						ft_fill_square(char **strs, t_list **list);
int						ft_fill_cylindre(char **strs, t_list **list);
int						ft_fill_triangle(char **strs, t_list **list);
int						ft_fill_cone(char **strs, t_list **list);
int						ft_check_error_res(char **strs, int boolean);
int						ft_check_error_ambient(char **strs, int boolean);
int						ft_check_error_camera(char **strs);
int						ft_check_error_light(char **strs);
int						ft_check_error_sphere(char **strs);
int						ft_check_error_plane(char **strs);
int						ft_check_error_square(char **strs);
int						ft_check_error_cylindre(char **strs);
int						ft_check_error_triangle(char **strs);
int						ft_printf_error_colors(char **colors);
int						ft_printf_error_origin(char **origin, int index);
int						ft_printf_error_vector(char **origin);
void					ft_fill_base(char **strs, t_base_form *base);
void					ft_fill_base_color(char **colors, t_vector *colors_t);
void					ft_fill_base_vector(char **coordo, t_vector *origin);
int						ft_clear(t_list **list, char **strs);
int						ft_init_window(t_scene *s);
t_vector				ft_multi_reel(t_vector p1, double p2);
t_vector				ft_add_vector(t_vector p1, t_vector p2);
t_vector				ft_multi_vector(t_vector p1, t_vector p2);
t_vector				ft_sous_vector(t_vector p1, t_vector p2);
t_vector				ft_divi_reel(t_vector p1, double p2);
t_vector				ft_calcule_dir(t_scene *s, int x, int y);
double					ft_intersect(t_ray ray, void *content);
double					ft_intersect_sphere(t_ray ray, t_sphere *sphere);
double					ft_intersect_plane(t_ray ray, t_plane *plane);
double					ft_intersect_triangle(t_ray ray, t_triangle *triangle);
double					ft_intersect_cylindre(t_ray ray, t_cylindre *cylindre);
double					ft_intersect_cone(t_ray ray, t_cone *cone);
double					ft_intersect_square(t_ray ray, t_square *square);
t_vector				ft_intersect_ray(t_vector o,
							t_vector dir, double t);
t_vector				ft_init_vector(double x, double y, double z);
t_vector				ft_normalize(t_vector v);
double					ft_distance(t_vector v);
double					ft_scalaire(t_vector v1, t_vector v2);
unsigned int			ft_change_color(t_vector color);
double					ft_clamp(double value, double min, double max);
double					ft_vect(t_vector v1, t_vector v2);
double					ft_determinant(double a, double b, double c);
t_vector				ft_cross_product(t_vector v1, t_vector v2);
t_vector				ft_calc_base_top(t_vector origin, double height);
double					ft_orient(t_vector a, t_vector b,
							t_vector c, t_vector n);
int						ft_translation_camera(int keycode, t_scene *s);
int						ft_translation_objects(int keycode, void *content);
int						ft_check_object_select(int keycode, t_scene *s);
int						ft_give_i(int keycode);
int						ft_close_mouse(t_scene *s);
t_vector				ft_translate_vector(t_vector v, int keycode);
void					ft_affichage_vector(t_vector v);
double					ft_determinant_matrice(t_vector v1, t_vector v2);
double					ft_aire_tr(t_vector a, t_vector b, t_vector c);
t_vector				ft_rotation_x(t_vector v, void *content, int sign);
t_vector				ft_rotation_y(t_vector v, void *content, int sign);
t_vector				ft_rotation_z(t_vector v, void *content, int sign);
double					ft_vect_orient_to_rad(t_vector vect_orient, int axe);
t_matrice				ft_init_matrice_rot(t_vector vect_orient, int sign);
void					ft_affichage_matrice(t_matrice m);
t_matrice				ft_init_matrice_trans(t_vector trans, int sign);
t_vector				ft_trans_orient(t_ray ray, void *content);
t_vector				ft_multi_mat_vect(t_matrice m, t_vector v);
double					ft_radian_to_degres(double rad);
int						ft_rotation_camera(int keycode, t_camera *camera);
int						ft_rotation_objects(int keycode, void *content);
t_vector				ft_rotate_vector(t_vector v, int keycode);
void					ft_affichage(t_list *list, t_scene *s);
double					ft_inter(t_inter *inter, double height);
t_vectorf				ft_init_vector_2(double x,
							double y, double z, double t);
int						ft_raytracer(t_scene *s);
int						ft_check_keycode(int keycode);
int						ft_sauver(t_scene s, const char *fichier);
t_pixel					ft_change_color_to_pixel(t_vector v);
t_vector				ft_get_color(t_scene *s, int i, int j);
t_pixel					ft_get_pixel(t_scene s, int i, int j);
int						export_bmp(t_scene s);
void					header_bmp(char **data, t_scene s);
void					fill_bmp(char **data, t_scene s);
t_vector				ft_view(double height, t_scene *s);
int						ft_p_virgule(char **strs, char c);

#endif
