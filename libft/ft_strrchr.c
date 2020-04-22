/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*res;

	count = 0;
	res = NULL;
	if ((char)c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[count] != '\0' || (char)c == '\0')
	{
		if (s[count] == (char)c)
			res = ((char *)&s[count]);
		count++;
	}
	return (res);
}
