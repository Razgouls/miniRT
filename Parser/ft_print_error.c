/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 10:48:43 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:25:19 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_printf_error_colors(char **strs, char **colors)
{
	int i;
	int	color;

	i = 0;
	while (colors[i])
	{
		color = (int)ft_atof(colors[i]);
		if (color < 0 || color > 255 || i > 2)
		{
			ft_printf("Error n : Les valeurs RGB sont erronées\n");
			ft_free_tab(colors);
			return (1);
		}
		i++;
	}
	if (i < 3)
	{
		ft_printf("Error n : Manque couleurs RGB\n");
		ft_free_tab(colors);
		return (1);
	}
	ft_free_tab(colors);
	return (0);
}

int		ft_printf_error_origin(char **origin, int index)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (origin[i])
		i++;
	if (i < 3)
		ft_printf("Error n : origin manquantes\n");
	if (i > 3)
		ft_printf("Error n : Trop de coor origin\n");
	(index == 0) ? ft_free_tab(origin) : NULL;
	if (i < 3 || i > 3)
		return (1);
	return (0);
}

int		ft_printf_error_vector(char **origin)
{
	int		i;
	double	tmp;

	if (ft_printf_error_origin(origin, 1))
	{
		ft_free_tab(origin);
		return (1);
	}
	i = 0;
	while (origin[i])
	{
		tmp = ft_atof(origin[i]);
		if (tmp < -1 || tmp > 1)
		{
			ft_printf("Error n : Vecteur : x, y, z\
			doit être compris entre -1 et 1 : ");
			ft_printf("%s,%s,%s\n", origin[0], origin[1], origin[2]);
			ft_free_tab(origin);
			return (1);
		}
		i++;
	}
	ft_free_tab(origin);
	return (0);
}
