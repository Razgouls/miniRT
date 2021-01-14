/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_number.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 01:20:19 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/29 01:20:20 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strlen_number(int n)
{
	int				i;
	int				cmp;
	unsigned int	tmp;

	i = 0;
	cmp = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		tmp = n * -1;
		cmp = 1;
	}
	else
		tmp = n;
	while (tmp >= 1)
	{
		tmp /= 10;
		i++;
	}
	return (i + cmp);
}
