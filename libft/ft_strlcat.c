/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dest_start;
	size_t		dst_len;
	size_t		src_len;
	size_t		i;

	dest_start = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size <= dst_len)
		return (src_len + size);
	while ((dst[dest_start] != '\0') && dest_start < (size - 1))
		dest_start++;
	i = 0;
	while (src[i] && dest_start < (size - 1))
	{
		dst[dest_start] = src[i];
		dest_start++;
		i++;
	}
	dst[dest_start] = '\0';
	return (dst_len + src_len);
}
