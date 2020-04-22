/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_fdf(t_fdf *fdf)
{
	free(fdf);
}

void	free_strsplit_arr(char **arr)
{
	size_t i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

void	affect_2_vals(int *x1, int val1, int *x2, int val2)
{
	*x1 = val1;
	*x2 = val2;
}

void	affect_int(int *x, int val)
{
	if (*x + val > 0)
		*x = *x + val;
}

void	affect_int2(int *x, int val)
{
	*x = *x + val;
}
