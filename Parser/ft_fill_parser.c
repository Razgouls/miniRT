/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 19:00:25 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/15 12:05:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

int		ft_fill_plane(char **strs, t_list **list)
{
	t_plane		*plane;
	t_base_form	base;

	if (ft_check_error_plane(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(plane = malloc(sizeof(*plane))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	plane->base = base;
	plane->base.normale = ft_init_vector(0.0, 1.0, 0.0);
	ft_lstadd_back(list, ft_lstnew(plane));
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_square(char **strs, t_list **list)
{
	t_square	*square;
	t_base_form	base;

	if (ft_check_error_square(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(square = malloc(sizeof(*square))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	square->height = ft_atof(strs[3]);
	square->base = base;
	ft_lstadd_back(list, ft_lstnew(square));
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_sphere(char **strs, t_list **list)
{
	t_sphere	*sphere;
	t_base_form	base;

	if (ft_check_error_sphere(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(sphere = malloc(sizeof(*sphere))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	sphere->radius = ft_atof(strs[2]) / 2;
	sphere->base = base;
	ft_lstadd_back(list, ft_lstnew(sphere));
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_cylindre(char **strs, t_list **list)
{
	t_cylindre	*cylindre;
	t_base_form	base;

	if (ft_check_error_cylindre(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(cylindre = malloc(sizeof(*cylindre))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	base.matrice = ft_init_matrice_rot(base.vect_orient, 0);
	base.inv_matrice = ft_init_matrice_rot(base.vect_orient, 1);
	cylindre->radius = ft_atof(strs[3]) / 2;
	cylindre->height = ft_atof(strs[4]);
	cylindre->base = base;
	ft_lstadd_back(list, ft_lstnew(cylindre));
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_triangle(char **strs, t_list **list)
{
	t_triangle	*triangle;
	t_base_form	base;

	if (ft_check_error_triangle(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(triangle = malloc(sizeof(*triangle))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[1], ','), &triangle->p1);
	ft_fill_base_vector(ft_split(strs[2], ','), &triangle->p2);
	ft_fill_base_vector(ft_split(strs[3], ','), &triangle->p3);
	triangle->base = base;
	ft_lstadd_back(list, ft_lstnew(triangle));
	ft_free_tab(strs);
	return (0);
}

int		ft_fill_cone(char **strs, t_list **list)
{
	t_cone		*cone;
	t_base_form	base;

	if (ft_check_error_cylindre(strs))
	{
		ft_free_tab(strs);
		return (1);
	}
	if (!(cone = malloc(sizeof(*cone))))
		return (ft_clear(list, strs));
	ft_fill_base(strs, &base);
	ft_fill_base_vector(ft_split(strs[2], ','), &base.vect_orient);
	cone->radius = ft_atof(strs[3]) / 2;
	cone->height = ft_atof(strs[4]);
	cone->base = base;
	ft_lstadd_back(list, ft_lstnew(cone));
	ft_free_tab(strs);
	return (0);
}
