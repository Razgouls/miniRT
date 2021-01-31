/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 17:58:38 by user42            #+#    #+#             */
/*   Updated: 2021/01/23 09:06:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

void		fill_bmp(char **data, t_scene s)
{
	int i;
	int x;
	int y;

	i = 122;
	y = s.reso.res[1];
	while (y--)
	{
		x = -1;
		while (++x < s.reso.res[0])
		{
			*(*data + i++) = (s.image.dat[s.reso.res[0] * y + x].b);
			*(*data + i++) = (s.image.dat[s.reso.res[0] * y + x].g);
			*(*data + i++) = (s.image.dat[s.reso.res[0] * y + x].r);
		}
	}
}

void		header_bmp(char **data, t_scene s)
{
	unsigned int size;

	size = s.reso.res[1] * s.reso.res[0] * 3;
	*(unsigned short *)*data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*data + 2) = (size + 122);
	*(unsigned int *)(*data + 6) = 0u;
	*(unsigned char *)(*data + 10) = 122;
	*(unsigned int *)(*data + 14) = 122 - 14;
	*(unsigned int *)(*data + 18) = s.reso.res[0];
	*(unsigned int *)(*data + 22) = s.reso.res[1];
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = (unsigned int)size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

int			export_bmp(t_scene s)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*data;

	size = s.reso.res[1] * s.reso.res[0] * 3;
	if (!(data = malloc((size + 122))))
		return (-1);
	i = 0;
	while (i < size + 122)
		data[i++] = 0;
	header_bmp(&data, s);
	fill_bmp(&data, s);
	if ((fd = open("bmp_image.bmp", O_CREAT | O_TRUNC | O_RDWR, 0644)) <= 0)
		return (-1);
	write(fd, data, (size + 122));
	close(fd);
	return (0);
}
