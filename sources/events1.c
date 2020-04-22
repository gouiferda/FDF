/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

void	position(int keycode, t_fdf *fdf)
{
	int step;

	step = 20;
	if (keycode == ARROW_LEFT)
		affect_int2(&fdf->offset_x, step);
	else if (keycode == ARROW_RIGHT)
		affect_int2(&fdf->offset_x, -step);
	else if (keycode == ARROW_UP)
		affect_int2(&fdf->offset_y, step);
	else if (keycode == ARROW_DOWN)
		affect_int2(&fdf->offset_y, -step);
	draw(fdf);
}

void	altitude(int keycode, t_fdf *fdf)
{
	int step;

	step = 1;
	if (keycode == N_9 || keycode == MOUSE_LEFT_BUTTON)
		affect_int2(&fdf->adj_alt, step);
	else if (keycode == N_7 || keycode == MOUSE_RIGHT_BUTTON)
		affect_int2(&fdf->adj_alt, -step);
	draw(fdf);
}

void	rotate(int keycode, t_fdf *fdf)
{
	if (keycode == N_2)
		fdf->alpha += 0.05;
	else if (keycode == N_8)
		fdf->alpha -= 0.05;
	else if (keycode == N_4)
		fdf->beta -= 0.05;
	else if (keycode == N_6)
		fdf->beta += 0.05;
	else if (keycode == N_1)
		fdf->gamma += 0.05;
	else if (keycode == N_3)
		fdf->gamma -= 0.05;
	draw(fdf);
}

void	project(int keycode, t_fdf *fdf)
{
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	if (keycode == KEY_I)
		fdf->projection = ISO;
	else if (keycode == KEY_P)
		fdf->projection = PARALLEL;
	draw(fdf);
}

void	zoom(int keycode, t_fdf *fdf)
{
	int step;

	step = 2;
	fdf->adj_alt = 0;
	if (keycode == N_PLUS || keycode == MOUSE_SCROLL_UP)
		affect_int(&fdf->zoom, step);
	else if (keycode == N_MINUS || keycode == MOUSE_SCROLL_DOWN)
		affect_int(&fdf->zoom, -step);
	draw(fdf);
}
