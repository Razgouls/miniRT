/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:00:25 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:25:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_fill_plane(char **strs, t_list **list)
{
	t_plane		*plane;
	t_base_form	base;

	if (ft_check_error_plane(strs) || ft_p_virgule(strs, ',') == 0)
		return (1);
	if (!(plane = malloc(sizeof(*plane))))
		return (1);
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	base.matrice = ft_init_matrice_rot(base.vect_orient, 0);
	base.inv_matrice = ft_init_matrice_rot(base.vect_orient, 1);
	plane->base = base;
	ft_lstadd_back(list, ft_lstnew(plane));
	return (0);
}

int		ft_fill_square(char **strs, t_list **list)
{
	t_square	*square;
	t_base_form	base;

	if (ft_check_error_square(strs) || ft_p_virgule(strs, ',') == 0)
		return (1);
	if (!(square = malloc(sizeof(*square))))
		return (1);
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	base.matrice = ft_init_matrice_rot(base.vect_orient, 0);
	base.inv_matrice = ft_init_matrice_rot(base.vect_orient, 1);
	square->height = ft_atof(strs[3]);
	square->base = base;
	ft_lstadd_back(list, ft_lstnew(square));
	return (0);
}

int		ft_fill_sphere(char **strs, t_list **list)
{
	t_sphere	*sphere;
	t_base_form	base;

	if (ft_check_error_sphere(strs) || ft_p_virgule(strs, ',') == 0)
		return (1);
	if (!(sphere = malloc(sizeof(*sphere))))
		return (1);
	ft_fill_base(strs, &base);
	sphere->radius = ft_atof(strs[2]) / 2;
	sphere->base = base;
	ft_lstadd_back(list, ft_lstnew(sphere));
	return (0);
}

int		ft_fill_cylindre(char **strs, t_list **list)
{
	t_cylindre	*cylindre;
	t_base_form	base;

	if (ft_check_error_cylindre(strs) || ft_p_virgule(strs, ',') == 0)
		return (1);
	if (!(cylindre = malloc(sizeof(*cylindre))))
		return (1);
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	base.matrice = ft_init_matrice_rot(base.vect_orient, 0);
	base.inv_matrice = ft_init_matrice_rot(base.vect_orient, 1);
	cylindre->radius = ft_atof(strs[3]) / 2;
	cylindre->height = ft_atof(strs[4]);
	cylindre->base = base;
	ft_lstadd_back(list, ft_lstnew(cylindre));
	return (0);
}

int		ft_fill_triangle(char **strs, t_list **list)
{
	t_triangle	*triangle;
	t_base_form	base;

	if (ft_check_error_triangle(strs) || ft_p_virgule(strs, ',') == 0)
		return (1);
	if (!(triangle = malloc(sizeof(*triangle))))
		return (1);
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[1], ','), &triangle->p1);
	ft_fill_base_vector(ft_split(strs[2], ','), &triangle->p2);
	ft_fill_base_vector(ft_split(strs[3], ','), &triangle->p3);
	triangle->base = base;
	ft_lstadd_back(list, ft_lstnew(triangle));
	return (0);
}
