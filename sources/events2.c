/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	color(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		affect_2_vals(&fdf->s_c, YELLOW, &fdf->g_c, GRAY);
	else if (keycode == KEY_X)
		affect_2_vals(&fdf->s_c, AQUA, &fdf->g_c, RED);
	else if (keycode == KEY_C)
		affect_2_vals(&fdf->s_c, WHITE, &fdf->g_c, AQUA);
	else if (keycode == KEY_V)
		affect_2_vals(&fdf->s_c, AQUA, &fdf->g_c, ROSE);
	else if (keycode == KEY_B)
		affect_2_vals(&fdf->s_c, RED, &fdf->g_c, BLUE);
	else if (keycode == KEY_N)
		affect_2_vals(&fdf->s_c, BLUE, &fdf->g_c, GRAY);
	else if (keycode == KEY_M)
		affect_2_vals(&fdf->s_c, GREEN, &fdf->g_c, WHITE);
	draw(fdf);
}

void	reset(int keycode, t_fdf *fdf)
{
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	adapt_to_map(fdf->map->w, &fdf->zoom, &fdf->offset_y);
	fdf->offset_x = 0;
	fdf->adj_alt = 0;
	fdf->projection = ISO;
	fdf->s_c = GREEN;
	fdf->g_c = WHITE;
	draw(fdf);
}

int		closer(void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	free_fdf(fdf);
	ft_putendl("FDF: Ended");
	exit(0);
	return (0);
}

void	error(char *msg)
{
	ft_putstr("FDF Error: ");
	ft_putendl(msg);
	exit(0);
}

void	end(char *msg)
{
	ft_putendl(msg);
	exit(0);
}
