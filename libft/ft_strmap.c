/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:51:37 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/12 16:51:40 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*res;

	if (s)
	{
		i = ft_strlen(s);
		if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
			return (NULL);
		i = 0;
		while (s[i] != '\0')
		{
			res[i] = f(s[i]);
			i++;
		}
		res[i] = '\0';
		if (res)
			return (res);
	}
	return (NULL);
}
