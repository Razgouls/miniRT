/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_miniRT_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/15 11:13:39 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/15 11:13:40 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_miniRT.h"

t_vector3D	ft_multi_reel(t_vector3D p1, double p2)
{
	t_vector3D		res;

	res.x = p1.x * p2;
	res.y = p1.y * p2;
	res.z = p1.z * p2;
	return (res); 
}

t_vector3D	ft_divi_reel(t_vector3D p1, double p2)
{
	t_vector3D		res;

	res.x = p1.x / p2;
	res.y = p1.y / p2;
	res.z = p1.z / p2;
	return (res); 
}

t_vector3D	ft_divi_vector(t_vector3D p1, t_vector3D p2)
{
	t_vector3D		res;

	res.x = p1.x / p2.x;
	res.y = p1.y / p2.y;
	res.z = p1.z / p2.z;
	return (res); 
}

t_vector3D	ft_add_vector(t_vector3D p1, t_vector3D p2)
{
	t_vector3D		res;

	res.x = p1.x + p2.x;
	res.y = p1.y + p2.y;
	res.z = p1.z + p2.z;
	return (res);
}

t_vector3D	ft_multi_vector(t_vector3D p1, t_vector3D p2)
{
	t_vector3D		res;

	res.x = p1.x * p2.x;
	res.y = p1.y * p2.y;
	res.z = p1.z * p2.z;
	return (res);
}

t_vector3D	ft_sous_vector(t_vector3D p1, t_vector3D p2)
{
	t_vector3D tmp;

	tmp.x = p1.x - p2.x;
	tmp.y = p1.y - p2.y;
	tmp.z = p1.z - p2.z;
	return (tmp);
}

t_vector3D	ft_normalize(t_vector3D v)
{
	double		norme;
    t_vector3D tmp;

	norme = ft_distance(v);
	tmp.x = v.x / norme;
	tmp.y = v.y / norme;
	tmp.z = v.z / norme;
	return (tmp);
}

t_vector3D	ft_point_intersect_ray(t_vector3D origin, t_vector3D dir, double t)
{
	t_vector3D tmp;

	tmp = ft_multi_reel(dir, t);
	tmp = ft_add_vector(origin, tmp);
	return (tmp);
}

t_vector3D	ft_cross_product(t_vector3D v1, t_vector3D v2)
{
	t_vector3D res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}

t_vector3D	ft_calc_base_top(t_vector3D origin, double height)
{
	t_vector3D origin_top;

	origin_top.x = origin.x;
	origin_top.y = origin.y + height;
	origin_top.z = origin.z;
	return (origin_top);
}

double		ft_orient(t_vector3D a, t_vector3D b, t_vector3D c, t_vector3D n)
{
	t_vector3D tmp;

	tmp = ft_cross_product(ft_sous_vector(b, a), ft_sous_vector(c, a));
	return (ft_vect(tmp, n));

}

double		ft_determinant_matrice(t_vector3D v1, t_vector3D v2)
{
	double	res;

	res = (v1.x * v2.y) - (v1.y * v2.x);
	return (res);
}

t_vector3D	ft_init_vector(double x, double y, double z)
{
	t_vector3D res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

double		ft_aire_tr(t_vector3D a, t_vector3D b, t_vector3D c)
{
	t_vector3D	ab;
	t_vector3D	ac;
	t_vector3D	bc;

	ab = ft_sous_vector(b, a);
	ac = ft_sous_vector(c, a);
	bc = ft_sous_vector(c, b);

	double disab;
	double disac;
	double disbc;

	disab = ft_distance(ab);
	disac = ft_distance(ac);
	disbc = ft_distance(bc);

	double res;

	res = 0.5 * ft_distance(ft_cross_product(ab, ac));
	return (res);
}

void		ft_affichage_vector(t_vector3D v)
{
	printf("x : %f\t y : %f\t z : %f\n", v.x, v.y, v.z);
}

double		ft_vect(t_vector3D v1, t_vector3D v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		ft_distance(t_vector3D v)
{
	return (sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2)));
}

double	ft_scalaire(t_vector3D v1, t_vector3D v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

int     ft_give_i(int keycode)
{
    int i;

	i = 0;
    if (keycode == '1')
        i = 0;
    else if (keycode == '2')
        i = 1;
    else if (keycode == '3')
        i = 2;
    else if (keycode == '4')
        i = 3;
    else if (keycode == '5')
        i = 4;
    else if (keycode == '6')
        i = 5;
    else if (keycode == '7')
        i = 6;
    else if (keycode == '8')
        i = 7;
    else if (keycode == '9')
        i = 8;
    return (i);
}