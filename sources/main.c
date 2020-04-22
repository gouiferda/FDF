/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/06/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	adapt_to_map(int map_width, int *zoom, int *offset_y)
{
	if (map_width > 30)
	{
		*zoom = 8;
		if (map_width >= 100)
			*zoom = 4;
		if (map_width >= 300)
			*zoom = 2;
		if (map_width >= 500)
			*zoom = 2;
		*offset_y = (map_width - 50) * -1;
	}
	else
	{
		*zoom = ZOOM_DEFAULT;
		*offset_y = OFFSET_Y_DEFAULT;
		if (map_width > 20)
			*offset_y = (map_width - 200);
	}
}

void	adapt_screen_size(int map_w, int map_h, int *s_w, int *s_h)
{
	if (map_w * 50 < 1290)
		*s_w = map_w * 60;
	else
		*s_w = 1290;
	if (map_h * 55 < 900)
		*s_h = map_h * 65;
	else
		*s_h = 900;
	if (map_w < 20 || map_h < 20)
	{
		*s_w = 700;
		*s_h = 600;
	}
}

t_fdf	*init_fdf(t_map *map)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf *)ft_memalloc(sizeof(t_fdf))))
		error("");
	if (!(fdf->mlx = mlx_init()))
		error("");
	adapt_screen_size(map->w, map->h, &(fdf->screen_w), &(fdf->screen_h));
	if (!(fdf->win = mlx_new_window(fdf->mlx, fdf->screen_w, fdf->screen_h,
		"FdF v2 - @sgouifer")))
		error("Initializing new window");
	if (!(fdf->img_ptr = mlx_new_image(fdf->mlx, fdf->screen_w, fdf->screen_h)))
		error("Initializing new image");
	fdf->img_data = mlx_get_data_addr(fdf->img_ptr, &(fdf->bpp),
		&(fdf->size_line), &(fdf->endian));
	adapt_to_map(map->w, &fdf->zoom, &fdf->offset_y);
	fdf->offset_x = 0;
	fdf->adj_alt = 0;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->projection = ISO;
	fdf->s_c = GREEN;
	fdf->g_c = WHITE;
	return (fdf);
}

int		main(int ac, char **av)
{
	int		fd;
	t_map	*map;
	t_fdf	*fdf;

	if (ac != 2)
		end("Usage: ./fdf mapname.fdf");
	fd = open(av[1], O_RDONLY);
	if (fd == 0 || fd == -1)
		error("File is invalid or does not exists");
	map = init_map();
	read_map(fd, map);
	fdf = init_fdf(map);
	fdf->map = map;
	draw(fdf);
	mlx_hook(fdf->win, 2, 0, keys_handler, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_handler, fdf);
	mlx_hook(fdf->win, 17, 0, closer, fdf);
	mlx_loop(fdf->mlx);
	return (0);
}
