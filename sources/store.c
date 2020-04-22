/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		points_arr_size(t_point *points)
{
	int i;

	i = 0;
	while (points[i].x >= 1)
	{
		i++;
	}
	return (i);
}

t_list	*init_list(void)
{
	t_list *first;

	first = (t_list*)malloc(sizeof(t_list));
	first->val = ft_strdup("");
	first->next = NULL;
	return (first);
}

int		list_size(t_list *head)
{
	int		size;
	t_list	*current;

	size = 0;
	current = head;
	while (current)
	{
		current = current->next;
		size++;
	}
	return (size - 1);
}

void	show_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current)
	{
		ft_putendl(current->val);
		current = current->next;
	}
}

void	push_to_list(t_list *head, char *val)
{
	t_list *current;

	current = head;
	while (current->next != NULL)
	{
		current = current->next;
	}
	current->next = malloc(sizeof(t_list));
	current->next->val = ft_strdup(val);
	current->next->next = NULL;
}
