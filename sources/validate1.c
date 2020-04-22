/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	check_lines_count(int lines_count)
{
	if (lines_count == 0)
		error("bad lines count");
}

int		valid_hex_number(char *str)
{
	int		i;
	char	**parts;
	char	**parts2;
	int		ret;

	ret = 1;
	i = 0;
	parts = ft_strsplit(str, ',');
	if (!(parts[0]) || !(parts[1]))
		return (0);
	parts2 = ft_strsplit(parts[1], 'x');
	if (!(parts2[0]) || !(parts2[1]))
		return (0);
	(ft_strcmp(parts2[0], "0") || !valid_number(parts[0])) && (ret = 0);
	while (i < ft_strlen(parts2[1]))
	{
		if (ft_is_c_b(parts2[1][i], 16) == -1)
			ret = 0;
		i++;
	}
	if (i == 0)
		ret = 0;
	free_strsplit_arr(parts);
	free_strsplit_arr(parts2);
	return (ret);
}

int		valid_number(char *str_number)
{
	int i;

	i = 0;
	while (str_number[i] != '\0')
	{
		if (!ft_isdigit(str_number[i]) && str_number[i] != '-')
			return (0);
		i++;
	}
	return (1);
}

int		valid_line(char *line)
{
	int		len;
	int		i;
	char	**parts;

	len = words_count(line);
	i = 0;
	parts = ft_strsplit(line, ' ');
	while (i < len)
	{
		if (!valid_number(parts[i]) && !valid_hex_number(parts[i]))
		{
			free_strsplit_arr(parts);
			return (0);
		}
		i++;
	}
	free_strsplit_arr(parts);
	return (1);
}

int		ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (base != 10 && !ft_h_start(&str[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_is_c_b(str[i], base) >= 0)
		result = result * base + ft_is_c_b(str[i++], base);
	return ((int)(result * sign));
}
