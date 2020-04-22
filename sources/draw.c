/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img_ptr, 0, 0);
	y = 0;
	mlx = fdf->mlx;
	win = fdf->win;
	mlx_string_put(mlx, win, 15, y += 20, WHITE, "Controls:");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Move: Arrows");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Rotation:");
	mlx_string_put(mlx, win, 65, y += 30, WHITE, "- On sides: 2/4/6/8");
	mlx_string_put(mlx, win, 65, y += 30, WHITE, "- Around: 1/3");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Altitude: 7/9");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Zoom: + or -");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Projection: I or P");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Colors:");
	mlx_string_put(mlx, win, 65, y += 30, WHITE, "Z, X, C, V, B, N, M");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Reset: SPACE");
	mlx_string_put(mlx, win, 45, y += 30, WHITE, "Exit: ESCAPE");
}

void	add_px(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < fdf->screen_w && y > 0 && y < fdf->screen_h)
	{
		i = (x * fdf->bpp / 8) + (y * fdf->size_line);
		fdf->img_data[i] = color;
		fdf->img_data[++i] = color >> 8;
		fdf->img_data[++i] = color >> 16;
	}
}

void	drawline(t_point p1, t_point p2, t_fdf *fdf, int color)
{
	int dx;
	int dy;
	int s[2];
	int err[2];

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	s[0] = (p1.x < p2.x ? 1 : -1);
	s[1] = (p1.y < p2.y ? 1 : -1);
	err[0] = (dx > dy ? dx : -dy) / 2;
	while (p1.x != p2.x || p1.y != p2.y)
	{
		add_px(fdf, p1.x, p1.y, color);
		err[1] = err[0];
		if (err[1] > -dx)
		{
			err[0] -= dy;
			p1.x += s[0];
		}
		if (err[1] < dy)
		{
			err[0] += dx;
			p1.y += s[1];
		}
	}
}

void	init_draw(int *i, int *points_count, t_fdf *fdf)
{
	int j;
	int	*img;

	*i = 0;
	*points_count = points_arr_size(fdf->map->points);
	ft_bzero(fdf->img_data, fdf->screen_w * fdf->screen_h * (fdf->bpp / 8));
	img = (int *)(fdf->img_data);
	j = 0;
	while (j < fdf->screen_h * fdf->screen_w)
	{
		img[j] = 0x000000;
		j++;
	}
}

void	draw(t_fdf *fdf)
{
	int i;
	int points_count;

	init_draw(&i, &points_count, fdf);
	while (i < points_count)
	{
		if (fdf->map->points[i].x % fdf->map->w != 0 &&
			(fdf->map->points[i].z == 0 || fdf->map->points[i + 1].z == 0))
			p_l(fdf, fdf->map->points[i], fdf->map->points[i + 1], fdf->g_c);
		if (i < fdf->map->h * fdf->map->w - fdf->map->w &&
			(fdf->map->points[i].z == 0 || (fdf->map->points[i].z != 0 &&
				fdf->map->points[i + fdf->map->w].z == 0)))
			p_l(fdf, fdf->map->points[i], fdf->map->points[i + fdf->map->w],
				fdf->g_c);
		if (fdf->map->points[i].x % fdf->map->w != 0 &&
			(fdf->map->points[i + 1].z != 0) && (fdf->map->points[i].z != 0))
			p_l(fdf, fdf->map->points[i], fdf->map->points[i + 1], fdf->s_c);
		if (i < fdf->map->h * fdf->map->w - fdf->map->w &&
			fdf->map->points[i].z != 0 &&
				fdf->map->points[i + fdf->map->w].z != 0)
			p_l(fdf, fdf->map->points[i], fdf->map->points[i + fdf->map->w]
				, fdf->s_c);
		i++;
	}
	draw_menu(fdf);
}
