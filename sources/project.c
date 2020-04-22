/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:32:02 by sgouifer          #+#    #+#             */
/*   Updated: 2019/03/09 22:32:05 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(ISO_ANGLE2);
	*y = (previous_x + previous_y) * sin(ISO_ANGLE2) - z;
}

t_point		get_project_point(t_fdf *fdf, t_point p)
{
	p.x *= fdf->zoom;
	p.y *= fdf->zoom;
	p.z *= fdf->zoom + fdf->adj_alt;
	p.x -= (fdf->map->w * fdf->zoom) / 2;
	p.y -= (fdf->map->h * fdf->zoom) / 2;
	rx(&p.y, &p.z, fdf->alpha);
	ry(&p.x, &p.z, fdf->beta);
	rz(&p.x, &p.y, fdf->gamma);
	if (fdf->projection == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += (fdf->screen_w) / 2 + fdf->offset_x;
	p.y += (fdf->screen_h + fdf->map->h * fdf->zoom) / 2 + fdf->offset_y;
	return (p);
}

/*
** p_l : project line
*/

void		p_l(t_fdf *fdf, t_point p1, t_point p2, int color)
{
	p1 = get_project_point(fdf, p1);
	p2 = get_project_point(fdf, p2);
	drawline(p1, p2, fdf, color);
}
