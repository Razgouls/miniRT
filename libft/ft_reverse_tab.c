/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:11:47 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/05 00:11:48 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse_tab(char *t)
{
    int		i;
    char	tmp;
    int		length;
    
    i = 0;
    length = ft_strlen(t);
    while (t[i] && i < length / 2)
    {
        tmp = t[i];
        t[i] = t[length - 1 - i];
        t[length - 1 - i] = tmp;
        i++;
    }
}
