/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:23:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/12 16:23:58 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *res;

	res = NULL;
	if (size <= 0)
		return (NULL);
	res = (void *)malloc(size);
	if (res)
	{
		ft_bzero(res, size);
	}
	return (res);
}
