/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 12:01:43 by user42            #+#    #+#             */
/*   Updated: 2021/01/20 08:11:24 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

double			ft_aire_tr(t_vector a, t_vector b, t_vector c)
{
	t_vector	ab;
	t_vector	ac;
	double		res;

	ab = ft_sous_vector(b, a);
	ac = ft_sous_vector(c, a);
	res = 0.5 * ft_distance(ft_cross_product(ab, ac));
	return (res);
}

int				ft_give_i(int keycode)
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

t_vector		ft_multi_mat_vect(t_matrice m, t_vector v)
{
	t_vector	res;

	res.x = m.v_x.x * v.x + m.v_x.y * v.y + m.v_x.z * v.z + m.v_x.t * 1;
	res.y = m.v_y.x * v.x + m.v_y.y * v.y + m.v_y.z * v.z + m.v_y.t * 1;
	res.z = m.v_z.x * v.x + m.v_z.y * v.y + m.v_z.z * v.z + m.v_z.t * 1;
	return (res);
}

int				ft_check_object_select(int keycode, t_scene *s)
{
	int		index;
	int		i;
	void	*content;
	t_list	*tmp_list;

	tmp_list = s->list;
	index = -1;
	i = ft_give_i(keycode);
	while (tmp_list && ++index <= i)
	{
		content = tmp_list->content;
		tmp_list = tmp_list->next;
	}
	s->choose_object.current_object = content;
	s->choose_object.last_keycode = keycode;
	return (0);
}

int				ft_check_keycode(int keycode)
{
	if (keycode == '1' || keycode == '2' || keycode == '3' ||
		keycode == '4' || keycode == '5' || keycode == '6' ||
		keycode == '7' || keycode == '8' || keycode == '9')
		return (1);
	else if (keycode == 'a' || keycode == 'w' || keycode == 'd' ||
			keycode == 's' || keycode == 'r' || keycode == 'f')
		return (2);
	else if (keycode == 'h' || keycode == 'u' || keycode == 'k' ||
			keycode == 'j' || keycode == 'o' || keycode == 'l')
		return (3);
	return (0);
}
