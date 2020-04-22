/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		is_whitespace(char c)
{
	return ((c == ' ') || (c == '\n') || (c == '\t'));
}

static int		check_has_only_blanks(char const *s)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i] != '\0')
	{
		if (!is_whitespace(s[i]))
		{
			res = 1;
		}
		i++;
	}
	return (res);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	size_t	start;
	size_t	end;

	start = 0;
	if (s)
	{
		if (!check_has_only_blanks(s))
			return (ft_strdup(""));
		end = ft_strlen(s);
		if ((str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		{
			while ((s[start] != '\0') && is_whitespace(s[start]))
			{
				start++;
			}
			while (is_whitespace(s[end - 1]))
			{
				end--;
			}
			str = ft_strsub(s, start, end - start);
			return (str);
		}
	}
	return (NULL);
}
