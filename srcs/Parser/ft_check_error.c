/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:02:42 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/20 08:06:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_check_error_res(char **strs, int boolean)
{
	int i;

	i = 1;
	if (boolean == 1)
		return (ft_printf("Error : L'id %s existe déjà\n", strs[0]));
	while (strs[i])
	{
		if (i == 3)
			return (ft_printf("Error : Trop de paramètres résolution\n"));
		if (ft_atoi(strs[i]) <= 0)
			return (ft_printf("Error : La résolution est incorrecte\n"));
		i++;
	}
	if (i < 3)
	{
		return (ft_printf("Error : Paramètre(s) manquant(s)\
		pour la résolution\n"));
	}
	return (0);
}

int		ft_check_error_ambient(char **strs, int boolean)
{
	if (boolean == 1)
		return (ft_printf("Error : L'id %s existe déjà\n", strs[0]));
	if (!strs[1] || !strs[2])
	{
		return (ft_printf("Error : Paramètre(s) manquant(s)\
		pour la lumiere ambiente\n"));
	}
	if (strs[3])
	{
		return (ft_printf("Error : Trop de paramètres pour \
		la lumiere ambiente\n"));
	}
	if (ft_atof(strs[1]) < 0 || ft_atof(strs[1]) > 1)
	{
		return (ft_printf("Error : Le ratio de la lumiere\
		ambiante est incorrecte\n"));
	}
	return (ft_printf_error_colors(ft_split(strs[2], ',')));
}

int		ft_check_error_camera(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error : Paramètre(s) manquant(s) caméra\n"));
	if (strs[4])
		return (ft_printf("Error : Trop de paramètres caméra\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_vector(ft_split(strs[2], ',')))
		return (1);
	if (ft_atof(strs[3]) < 0 || ft_atof(strs[3]) > 180)
	{
		return (ft_printf("Error : Le FOV doit être \
		compris entre 0 et 180\n"));
	}
	return (0);
}

int		ft_check_error_light(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error : Paramètre(s) manquant(s) lumière\n"));
	if (strs[4])
		return (ft_printf("Error : Trop de paramètres lumière\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_atof(strs[2]) < 0 || ft_atof(strs[2]) > 1)
	{
		return (ft_printf("Error : Ratio de luminosité\
		incorrect\n"));
	}
	if (ft_printf_error_colors(ft_split(strs[3], ',')))
		return (1);
	return (0);
}
