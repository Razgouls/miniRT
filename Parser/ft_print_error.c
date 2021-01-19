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

int		ft_printf_error_colors(char **strs, char **colors, int in)
{
	int i;

	i = 0;
	while (colors[i])
	{
		if (i > 2)
		{
			ft_printf("Error n : Trop de couleurs RGB : %s\n", strs[3 + in]);
			return (1);
		}
		if ((int)ft_atof(colors[i]) < 0 || (int)ft_atof(colors[i]) > 255)
		{
			ft_printf("Error n : Les valeurs \
			RGB sont erronées : %s\n", strs[3 + in]);
			return (1);
		}
		i++;
	}
	if (i < 3)
	{
		ft_printf("Error n : Manque couleurs RGB : %s\n", strs[3 + in]);
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
		ft_printf("Error n : origin manquantes : ");
	if (i > 3)
		ft_printf("Error n : Trop de origin : ");
	while (++j < i)
		ft_printf("%s,", origin[j]);
	ft_printf("\n");
	(index == 0) ? ft_free_tab(origin) : NULL;
	return (0);
}

int		ft_printf_error_vector(char **origin)
{
	int i;

	if (ft_printf_error_origin(origin, 1))
		return (1);
	i = 0;
	while (origin[i])
	{
		if (ft_atof(origin[i]) < -1 || ft_atof(origin[i]) > 1)
		{
			ft_printf("Error n : Vecteur : x, y, z\
			doit être compris entre -1 et 1 : ");
			ft_printf("%s,%s,%s\n", origin[0], origin[1], origin[2]);
			return (1);
		}
		i++;
	}
	ft_free_tab(origin);
	return (0);
}
