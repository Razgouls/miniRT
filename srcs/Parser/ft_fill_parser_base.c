/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_parser_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 11:23:31 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:24:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void			ft_fill_base_vector(char **coordo, t_vector *origin)
{
	t_vector	tmp;

	tmp.x = ft_atof(coordo[0]);
	tmp.y = ft_atof(coordo[1]);
	tmp.z = ft_atof(coordo[2]);
	*origin = tmp;
	ft_free_tab(coordo);
}

void			ft_fill_base_color(char **colors, t_vector *colors_t)
{
	colors_t->x = ft_atof(colors[0]) / 255;
	colors_t->y = ft_atof(colors[1]) / 255;
	colors_t->z = ft_atof(colors[2]) / 255;
	ft_free_tab(colors);
}

void			ft_fill_base(char **strs, t_base_form *base)
{
	int				i;

	i = -1;
	while (strs[0][++i])
		base->id[i] = strs[0][i];
	base->id[i] = '\0';
	ft_fill_base_vector(ft_split(strs[1], ','), &base->origin);
	i = 0;
	while (strs[i + 1])
		i++;
	ft_fill_base_color(ft_split(strs[i], ','), &base->colors);
}

void			ft_del(void *element)
{
	free(element);
}

int				ft_clear(t_list **list, char **strs)
{
	ft_free_tab(strs);
	ft_lstclear(list, ft_del);
	return (1);
}
