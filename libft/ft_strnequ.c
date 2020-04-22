/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 23:36:22 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/12 23:36:26 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	res;

	if (s1 && s2)
	{
		res = 0;
		if (ft_strncmp(s1, s2, n) == 0)
		{
			res = 1;
		}
		else
		{
			res = 0;
		}
		return (res);
	}
	return (0);
}
