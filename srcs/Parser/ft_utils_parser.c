/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:15:45 by user42            #+#    #+#             */
/*   Updated: 2021/02/01 14:15:56 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_p_virgule_aux_2(char c)
{
	if (c < '0' || c > '9')
		return (0);
	return (1);
}

int		ft_parser_virgule_aux(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i + 1])
	{
		if (str[i] == c && str[i + 1] == c)
			return (0);
		i++;
	}
	if (!ft_p_virgule_aux_2(str[i]))
		return (0);
	return (1);
}

int		ft_p_virgule(char **strs, char c)
{
	int		i;

	i = 1;
	while (strs[i])
	{
		if (ft_parser_virgule_aux(strs[i], c) == 0)
		{
			printf("Error : Problème de ponctuation\n");
			return (0);
		}
		i++;
	}
	return (1);
}
