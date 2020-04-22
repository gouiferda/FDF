/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:55:54 by sgouifer          #+#    #+#             */
/*   Updated: 2018/10/07 23:16:59 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int		has_spacing(char c)
{
	return (c == '+' || c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f');
}

static	int		verify_double_sign(const char *str, int index)
{
	int found;

	found = 0;
	while (str[index] != '\0')
	{
		if (str[index] == '-' || str[index] == '+')
		{
			if (str[index + 1] == '-' || str[index + 1] == '+')
				return (1);
		}
		index++;
	}
	return (found);
}

static	void	verify_minus(char c, int *sign, int *index)
{
	if (c == '-')
	{
		*sign = -1;
		*index += 1;
	}
}

int				ft_atoi(const char *str)
{
	int						index;
	int						sign;
	unsigned long long int	output;

	index = 0;
	sign = 1;
	output = 0;
	if (verify_double_sign(str, index))
		return (0);
	while (has_spacing(str[index]))
		index++;
	verify_minus(str[index], &sign, &index);
	while (str[index] >= '0' && str[index] <= '9')
	{
		output = output * 10 + (str[index] - '0');
		index++;
	}
	if (output > 9223372036854775807 && sign == -1)
		return (0);
	if (output > 9223372036854775807)
		return (-1);
	return (output * sign);
}
