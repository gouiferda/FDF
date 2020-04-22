/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		d_count(int n)
{
	int count;

	count = 0;
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void		fill_arr(char *arr, int nb, int size)
{
	while (nb)
	{
		arr[size - 2] = (nb % 10) + '0';
		nb /= 10;
		size--;
	}
}

char			*ft_itoa(int n)
{
	char	*result;
	int		size_alc;
	int		fill_i;
	int		nb;

	nb = n;
	size_alc = 1;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0 && n > -2147483647)
	{
		n *= -1;
		size_alc = 2;
	}
	if (n == 0)
		return (ft_strdup("0"));
	if (!(result = (char *)malloc(sizeof(char) * (d_count(n) + size_alc))))
		return (NULL);
	fill_i = d_count(n) + size_alc;
	fill_arr(result, n, fill_i);
	result[d_count(nb) + size_alc - 1] = '\0';
	if (nb < 0)
		result[0] = '-';
	return (result);
}
