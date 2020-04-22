/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*res;
	size_t			x;
	int				i;

	if (s1 && s2)
	{
		x = sizeof(char);
		res = (char *)malloc(x * (ft_strlen(s1) + ft_strlen(s2) + 1));
		if (res)
		{
			ft_strcpy(res, s1);
			if (ft_strlen(s1) == 0)
				i = 0;
			else
				i = ft_strlen(s1) - 1;
			ft_strcat(&res[i], s2);
			return (res);
		}
	}
	return (NULL);
}
