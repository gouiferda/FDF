/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 06:47:37 by sgouifer          #+#    #+#             */
/*   Updated: 2019/02/15 06:47:41 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "keys.h"

int		keys_handler(int keycode, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf *)param;
	if (keycode == MAIN_PAD_ESC)
		closer(fdf);
	if (keycode == KEY_P || keycode == KEY_I)
		project(keycode, fdf);
	if (keycode == KEY_Z || keycode == KEY_X || keycode == KEY_C ||
		keycode == KEY_V || keycode == KEY_B || keycode == KEY_N
		|| keycode == KEY_M)
		color(keycode, fdf);
	if (keycode == N_PLUS || keycode == N_MINUS)
		zoom(keycode, fdf);
	if (keycode == ARROW_UP || keycode == ARROW_DOWN || keycode == ARROW_LEFT
		|| keycode == ARROW_RIGHT)
		position(keycode, fdf);
	if (keycode == MAIN_PAD_SPACE)
		reset(keycode, fdf);
	if (keycode == N_7 || keycode == N_9)
		altitude(keycode, fdf);
	if (keycode == N_1 || keycode == N_2 ||
		keycode == N_3 || keycode == N_4 ||
		keycode == N_5 || keycode == N_6 || keycode == N_8)
		rotate(keycode, fdf);
	return (0);
}
