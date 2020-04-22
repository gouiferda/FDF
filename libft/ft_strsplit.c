/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:23:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/12 16:23:58 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		words_count(char const *s, char c)
{
	int i;
	int counter;

	counter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c) && ((s[i + 1] == c) || (s[i + 1] == '\0')))
			counter++;
		i++;
	}
	return (counter);
}

static char		*next_word(char const *s, char c, size_t *start)
{
	size_t	begin;
	size_t	end;

	while (s[*start] == c)
		*start += 1;
	begin = *start;
	end = begin;
	while (s[end])
	{
		if (s[end] == c)
			break ;
		end++;
	}
	*start = end;
	return (ft_strsub(s, begin, end - begin));
}

char			**ft_strsplit(char const *s, char c)
{
	int		nb_words;
	char	**result;
	size_t	i;
	size_t	start;

	if (s)
	{
		nb_words = words_count(s, c);
		result = (char**)malloc(sizeof(char*) * (nb_words + 1));
		if (result == NULL)
			return (NULL);
		i = 0;
		start = 0;
		while (nb_words--)
		{
			result[i] = next_word(s, c, &start);
			i++;
		}
		result[i] = NULL;
		return (result);
	}
	return (NULL);
}
