/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:08:19 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/05 00:08:21 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int cmp;

	cmp = 0;
	i = 0;
	while (dest[i])
	{
		i++;
		cmp++;
	}
	i = 0;
	while (src[i])
	{
		dest[cmp + i] = src[i];
		i++;
	}
	dest[cmp + i] = '\0';
	return (dest);
}

