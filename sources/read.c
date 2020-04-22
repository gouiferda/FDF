/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		error("error reading map");
	map->w = 0;
	map->h = 0;
	map->points = NULL;
	return (map);
}

void	fill_pts(char *str, int *i, t_point tv, t_point *points)
{
	char		**parts;
	char		**points_str_arr;
	int			j;

	points_str_arr = ft_strsplit(str, ' ');
	j = 0;
	while (j < tv.x)
	{
		parts = ft_strsplit(points_str_arr[j], ',');
		points[*i].x = j + 1;
		points[*i].y = tv.y;
		points[*i].z = ft_atoi(parts[0]);
		if (parts[1])
			points[*i].color = ft_atoi_base(parts[1], 16);
		else
			points[*i].color = WHITE;
		*i = *i + 1;
		j = j + 1;
		free_strsplit_arr(parts);
	}
	free_strsplit_arr(points_str_arr);
}

void	lines_to_map(t_list *head, t_map *map)
{
	t_point		*points;
	int			i;
	t_list		*current;
	t_point		two_vars;

	two_vars.y = 0;
	i = 0;
	current = head;
	current = current->next;
	two_vars.x = words_count(current->val);
	points = (t_point*)malloc(sizeof(t_point) * list_size(head) * two_vars.x);
	while (current)
	{
		init_point1(&two_vars);
		fill_pts(current->val, &i, two_vars, points);
		current = current->next;
		two_vars.y++;
	}
	map->points = points;
	map->w = two_vars.x;
	map->h = two_vars.y;
}

void	ss(char *b, char *c)
{
	ft_putendl("FdF map info:");
	ft_putendl(ft_strjoin(" - Lines count: ", b));
	ft_putendl(ft_strjoin(" - Lines width: ", c));
	ft_putendl("\nFDF: Running...");
}

int		read_map(int fd, t_map *map)
{
	char	*line;
	int		nb_c_max;
	int		lines_count;
	int		result;
	t_list	*head;

	head = init_list();
	lines_count = 0;
	nb_c_max = 0;
	while ((result = get_next_line(fd, &line)))
	{
		if (words_count(line) > nb_c_max)
			nb_c_max = words_count(line);
		if (nb_c_max == 0 || nb_c_max != words_count(line))
			error("bad line length");
		if (!valid_line(line))
			error("bad line characters");
		push_to_list(head, line);
		ft_strdel(&line);
		lines_count++;
	}
	check_lines_count(lines_count);
	lines_to_map(head, map);
	ss(ft_itoa(lines_count), ft_itoa(nb_c_max));
	return (result);
}
