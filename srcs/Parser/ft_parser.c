/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:44:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/27 10:25:25 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		ft_fill_struct(char **strs, t_list **l, t_identifiant *id, t_scene *s)
{
	if (!strs[0])
		return (0);
	else if (ft_strcmp(strs[0], "R") == 0)
		return (ft_fill_res(strs, id, s));
	else if (ft_strcmp(strs[0], "A") == 0)
		return (ft_fill_ambient_light(strs, id, s));
	else if (ft_strcmp(strs[0], "c") == 0)
		return (ft_fill_camera(strs, s));
	else if (ft_strcmp(strs[0], "l") == 0)
		return (ft_fill_light(strs, s));
	else if (ft_strcmp(strs[0], "pl") == 0)
		return (ft_fill_plane(strs, l));
	else if (ft_strcmp(strs[0], "sp") == 0)
		return (ft_fill_sphere(strs, l));
	else if (ft_strcmp(strs[0], "sq") == 0)
		return (ft_fill_square(strs, l));
	else if (ft_strcmp(strs[0], "cy") == 0)
		return (ft_fill_cylindre(strs, l));
	else if (ft_strcmp(strs[0], "tr") == 0)
		return (ft_fill_triangle(strs, l));
	else if (ft_strcmp(strs[0], "co") == 0)
		return (ft_fill_cone(strs, l));
	else
		return (ft_printf("Error n : L'id %s est inconnu.\n", strs[0]));
	return (0);
}

int		ft_load_lines(int fd, t_list **l, t_identifiant *id, t_scene *s)
{
	char	**res_split;
	char	*line;
	int		i;

	while ((i = ft_get_next_line(fd, &line)))
	{
		if (ft_strcmp(line, "") != 0 && ft_strcmp(line, "\n") != 0)
		{
			res_split = ft_split_multi(line, "\t\n\v\f\r ");
			if (ft_fill_struct(res_split, l, id, s))
			{
				ft_clear(l, res_split);
				free(line);
				return (1);
			}
			ft_free_tab(res_split);
		}
		free(line);
	}
	return (0);
}

int		ft_init_struct_id(t_identifiant *id, t_scene *s, char **argv)
{
	s->check_save = 0;
	id->resolution = 0;
	id->ambient_light = 0;
	s->index_cam = 0;
	s->index_light = 0;
	s->current_camera = 0;
	if (argv[2] && ft_strcmp(argv[2], "-save") == 0)
		s->check_save = 1;
	else if (argv[2] && ft_strcmp(argv[2], "-save") != 0)
		return (ft_printf("Error : %s non valide\n", argv[2]));
	return (0);
}

int		main(int argc, char **argv)
{
	int				i;
	int				fd;
	t_list			*list;
	t_identifiant	id;
	t_scene			scene;

	i = 0;
	list = NULL;
	if (argc < 2 || argc > 3)
		return (ft_printf("Error : Problème d'arguments\n"));
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i] || argv[1][i + 1] != 'r' || argv[1][i + 2] != 't')
		return (ft_printf("Error : %s non pris en charge\n", argv[1]));
	if (ft_init_struct_id(&id, &scene, argv) ||
		(fd = open(argv[1], O_RDONLY)) < 0)
		return (ft_printf("Error : Impossible d'ouvrir le fichier\n"));
	if (!ft_load_lines(fd, &list, &id, &scene))
	{
		scene.list = list;
		ft_init_window(&scene);
		ft_lstclear(&scene.list, free);
	}
	close(fd);
	return (0);
}
