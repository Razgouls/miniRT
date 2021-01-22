/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 09:30:11 by user42            #+#    #+#             */
/*   Updated: 2021/01/22 13:52:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#pragma pack(1)  // desative l'alignement m�moire

int ft_sauver(t_scene scene,const char* fichier)
{
	t_bmphead head;
	t_pixel p;
	int i, j, tailledata, pitch;
	unsigned char bgrpix[3];
	char corrpitch[4] = {0, 3, 2, 1};
	FILE* F = fopen(fichier, "wb");
	if (!F)
		return -1;
	memset(&head, 0, sizeof(t_bmphead));
	head.signature[0] = 'B';
	head.signature[1] = 'M';
	head.offsetim = sizeof(t_bmphead); // je vais toujours �crire sur le m�me moule.
	head.imhead.size_imhead = sizeof(t_bmpimhead);
	head.imhead.width = scene.reso.res[0];
	head.imhead.height = scene.reso.res[1];
	head.imhead.nbplans = 1;
	head.imhead.bpp = 24;
	pitch = corrpitch[(3 * head.imhead.width) % 4];
	tailledata = 3 * head.imhead.height * head.imhead.width + head.imhead.height * pitch;
	head.imhead.sizeim = tailledata;
	head.taille = head.offsetim + head.imhead.sizeim;
	fwrite(&head, sizeof(t_bmphead), 1, F);
	for(j = 0; j < scene.reso.res[1]; j++)
	{
		for(i = 0; i < scene.reso.res[0]; i++)
		{
			p = ft_get_pixel(scene, i, scene.reso.res[1] - j - 1);
			bgrpix[0] = p.b;
			bgrpix[1] = p.g;
			bgrpix[2] = p.r;
			fwrite(&bgrpix, 1, 3, F);
		}
		bgrpix[0] = bgrpix[1] = bgrpix[2] = 0;
		fwrite(&bgrpix, 1, pitch, F);
	}
	fclose(F);
	return 0;
}


