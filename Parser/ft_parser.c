/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:44:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:25:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

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

void	ft_affichage(t_list *list, t_scene *s)
{
	t_list	*tmp;
	int		i;

	tmp = list;
	i = -1;
	ft_affiche_res(s->reso);
	ft_affiche_ambient_light(s->ambient_light);
	while (++i < s->index_cam)
		ft_affiche_camera(s->camera[i]);
	i = -1;
	while (++i < s->index_light)
		ft_affiche_light(s->light[i]);
	i = 0;
	while (list)
	{
		t_base_form *b = (t_base_form *)list->content;
		char *id = b->id;
		if (ft_strcmp(id, "sp") == 0)
			ft_affiche_sphere((t_sphere *)list->content);
		else if (ft_strcmp(id, "pl") == 0)
			ft_affiche_plane((t_plane *)list->content);
		else if (ft_strcmp(id, "sq") == 0)
			ft_affiche_square((t_square *)list->content);
		else if (ft_strcmp(id, "cy") == 0)
			ft_affiche_cylindre((t_cylindre *)list->content);
		else if (ft_strcmp(id, "tr") == 0)
			ft_affiche_triangle((t_triangle *)list->content);
		else if (ft_strcmp(id, "co") == 0)
			ft_affiche_cone((t_cone *)list->content);
		i++;
		list = list->next;
	}
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
			if (ft_fill_struct(res_split,  l, id, s))
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

void	ft_init_struct_id(t_identifiant *id, t_scene *s)
{
	int i;

	i = -1;
	id->resolution = 0;
	id->ambient_light = 0;
	s->index_cam = 0;
	s->index_light = 0;
	s->current_camera = 0;
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
	ft_init_struct_id(&id, &scene);
	if (argc < 2)
		return (1);
	while (argv[1][i] && argv[1][i] != '.')
		i++;
	if (!argv[1][i] || argv[1][i + 1] != 'r' || argv[1][i + 2] != 't')
		return (2);
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		return (3);
	if (!ft_load_lines(fd, &list, &id, &scene))
	{
		scene.list = list;
		ft_init_window(&scene);
		ft_lstclear(&scene.list, free);
	}
	close(fd);
	return (0);
}
