/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_parser_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:23:31 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:24:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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
	base.matrice = ft_init_matrice_rot(base.vect_orient, 0);
	base.inv_matrice = ft_init_matrice_rot(base.vect_orient, 1);
	cone->radius = ft_atof(strs[3]) / 2;
	cone->height = ft_atof(strs[4]);
	cone->base = base;
	ft_lstadd_back(list, ft_lstnew(cone));
	ft_free_tab(strs);
	return (0);
}
