/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 12:02:42 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/09 12:02:43 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

int		ft_check_error_res(char **strs, int boolean)
{
	int i;

	i = 1;
	if (boolean == 1)
		return (ft_printf("Error n : L'id %s existe déjà\n", strs[0]));
	while (strs[i])
	{
		if (i == 3)
			return (ft_printf("Error n : Trop de paramètres pour la résolution\n"));
		if (ft_atoi(strs[i]) <= 0)
			return (ft_printf("Error n : La résolution est incorrecte : %s %s\n", strs[1], strs[2]));
		i++;
	}
	if (i < 3)
		return (ft_printf("Error n : Paramètre(s) manquant(s) pour la résolution\n"));
	return (0);
}

int		ft_check_error_ambient(char **strs, int boolean)
{
	if (boolean == 1)
		return (ft_printf("Error n : L'id %s existe déjà\n", strs[0]));
	if (!strs[1] || !strs[2])
		return (ft_printf("Error n : Paramètre(s) manquant(s) pour la lumiere ambiente\n"));
	if (strs[3])
		return (ft_printf("Error n : Trop de paramètres pour la lumiere ambiente\n"));
	if (ft_atof(strs[1]) < 0 || ft_atof(strs[1]) > 1)
		return (ft_printf("Error n : Le ratio de la lumiere ambiante est incorrecte : %s\n", strs[1]));
	return (ft_printf_error_colors(strs, ft_split(strs[2], ','), 0));
}

int		ft_check_error_camera(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error n : Paramètre(s) manquant(s) pour la caméra\n"));
	if (strs[4])
		return (ft_printf("Error n : Trop de paramètres pour la caméra\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_vector(ft_split(strs[2], ',')))
		return (1);
	if (ft_atof(strs[3]) < 0 || ft_atof(strs[3]) > 180)
		return (ft_printf("Error n : Le FOV doit être compris entre 0 et 180 : %s\n", strs[3]));
	return (0);
}

int		ft_check_error_light(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error n : Paramètre(s) manquant(s) pour la lumière\n"));
	if (strs[4])
		return (ft_printf("Error n : Trop de paramètres pour la lumière\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_atof(strs[2]) < 0 || ft_atof(strs[2]) > 1)
		return (ft_printf("Error n : Le ratio de luminosité est incorrect : %s\n", strs[2]));
	if (ft_printf_error_colors(strs, ft_split(strs[3], ','), 0))
		return (1);
	return (0);
}