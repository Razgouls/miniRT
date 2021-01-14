/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:58:23 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/05 00:58:26 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_convert_base(char *t, int n, int i, char *base)
{
	int len;

	len = ft_strlen(base);
    if (n >= 16)
    {
        ft_convert_base(t, n / len, i + 1, base);
        ft_convert_base(t, n % len, i, base);
    }
    else
        t[i] = base[n];
}
