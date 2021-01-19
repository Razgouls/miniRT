/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 14:06:07 by elieolive         #+#    #+#             */
/*   Updated: 2021/01/19 13:24:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int		ft_check_error_sphere(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error n : Paramètre(s) manquant(s) sphère\n"));
	if (strs[4])
		return (ft_printf("Error n : Trop de paramètres sphère\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_atof(strs[2]) < 0)
		return (ft_printf("Error n : Le diamètre < 0 : %s\n", strs[2]));
	if (ft_printf_error_colors(strs, ft_split(strs[3], ',')))
		return (1);
	return (0);
}

int		ft_check_error_plane(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3])
		return (ft_printf("Error n : Paramètre(s) manquant(s)\n"));
	if (strs[4])
		return (ft_printf("Error n : Nombre de paramètres incorrects\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_vector(ft_split(strs[2], ',')))
		return (1);
	if (ft_printf_error_colors(strs, ft_split(strs[3], ',')))
		return (1);
	return (0);
}

int		ft_check_error_square(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3] || !strs[4])
		return (ft_printf("Error n : Paramètre(s) manquant(s)\n"));
	if (strs[5])
		return (ft_printf("Error n : Nombre de paramètres incorrects\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_vector(ft_split(strs[2], ',')))
		return (1);
	if (ft_atof(strs[3]) < 0)
		return (ft_printf("Error n : La hauteur < 0 : %s\n", strs[3]));
	if (ft_printf_error_colors(strs, ft_split(strs[4], ',')))
		return (1);
	return (0);
}

int		ft_check_error_cylindre(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3] || !strs[4] || !strs[5])
		return (ft_printf("Error n : Paramètre(s) manquant(s)\n"));
	if (strs[6])
		return (ft_printf("Error n : Nombre de paramètres incorrects\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_vector(ft_split(strs[2], ',')))
		return (1);
	if (ft_atof(strs[3]) < 0)
		return (ft_printf("Error n : La hauteur < 0 : %s\n", strs[3]));
	if (ft_atof(strs[4]) < 0)
		return (ft_printf("Error n : Le diametre < 0 : %s\n", strs[4]));
	if (ft_printf_error_colors(strs, ft_split(strs[5], ',')))
		return (1);
	return (0);
}

int		ft_check_error_triangle(char **strs)
{
	if (!strs[1] || !strs[2] || !strs[3] || !strs[4])
		return (ft_printf("Error n : Paramètre(s) manquant(s)\n"));
	if (strs[5])
		return (ft_printf("Error n : Nombre de paramètres incorrects\n"));
	if (ft_printf_error_origin(ft_split(strs[1], ','), 0))
		return (1);
	if (ft_printf_error_origin(ft_split(strs[2], ','), 0))
		return (1);
	if (ft_printf_error_origin(ft_split(strs[3], ','), 0))
		return (1);
	if (ft_printf_error_colors(strs, ft_split(strs[4], ',')))
		return (1);
	return (0);
}
