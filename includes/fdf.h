/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 19:03:09 by sgouifer          #+#    #+#             */
/*   Updated: 2019/06/14 19:03:09 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "colors.h"

# define PARALLEL 1
# define ISO 2
# define ISO_ANGLE1 0.523599
# define ISO_ANGLE2 0.46373398
# define OFFSET_Y_DEFAULT 50
# define ZOOM_DEFAULT 20

# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line.h"

typedef struct		s_list
{
	char			*val;
	struct s_list	*next;
}					t_list;

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef	struct		s_map
{
	t_point			*points;
	int				w;
	int				h;
}					t_map;

typedef struct		s_fdf
{
	void			*mlx;
	void			*win;
	int				zoom;
	int				offset_x;
	int				offset_y;
	int				adj_alt;
	int				projection;
	t_map			*map;
	int				s_c;
	int				g_c;
	int				screen_w;
	int				screen_h;
	double			alpha;
	double			beta;
	double			gamma;
	void			*img_ptr;
	char			*img_data;
	int				size_line;
	int				bpp;
	int				endian;
}					t_fdf;

/*
** main.c
*/

void				adapt_to_map(int map_width, int *zoom, int *offset_y);
void				adapt_screen_size(int map_w, int map_h, int *s_w, int *s_h);
t_fdf				*init_fdf(t_map *map);

/*
** store.c
*/

int					points_arr_size(t_point *points);
t_list				*init_list(void);
int					list_size(t_list *head);
void				show_list(t_list *head);
void				push_to_list(t_list *head, char *val);

/*
** validate1.c
*/

void				check_lines_count(int lines_count);
int					valid_hex_number(char *str);
int					valid_number(char *str_number);
int					valid_line(char *line);
int					ft_atoi_base(const char *str, int base);

/*
** validate2.c
*/

int					words_count(char const *s);
int					ft_is_c_b(char c, int base);
int					ft_h_start(const char *str, int base);
int					ft_isspace(int c);
void				init_point1(t_point *p);

/*
** read.c
*/

t_map				*init_map(void);
void				fill_pts(char *str, int *i, t_point tv, t_point *points);
void				lines_to_map(t_list *head, t_map *map);
void				ss(char *b, char *c);
int					read_map(int fd, t_map *map);

/*
** rotate.c
*/

void				rx(int *y, int *z, double alpha);
void				ry(int *x, int *z, double beta);
void				rz(int *x, int *y, double gamma);

/*
** project.c
*/

void				iso(int *x, int *y, int z);
t_point				get_project_point(t_fdf *fdf, t_point p);
void				p_l(t_fdf *fdf, t_point p1, t_point p2, int color);

/*
** draw.c
*/

void				add_px(t_fdf *fdf, int x, int y, int color);
void				drawline(t_point p1, t_point p2, t_fdf *fdf, int color);
void				init_draw(int *i, int *points_count, t_fdf *fdf);
void				draw(t_fdf *fdf);
void				draw_menu(t_fdf *fdf);

/*
** keys_handler.c
*/

int					keys_handler(int keycode, void *param);

/*
** mouse_handler.c
*/

int					mouse_handler(int button, int x, int y, void *param);

/*
** events1.c
*/

void				position(int keycode, t_fdf *fdf);
void				altitude(int keycode, t_fdf *fdf);
void				rotate(int keycode, t_fdf *fdf);
void				project(int keycode, t_fdf *fdf);
void				zoom(int keycode, t_fdf *fdf);

/*
** events2.c
*/

void				color(int keycode, t_fdf *fdf);
void				reset(int keycode, t_fdf *fdf);
int					closer(void *param);
void				error(char *msg);
void				end(char *msg);

/*
** functions.c
*/

void				free_fdf(t_fdf	*fdf);
void				free_strsplit_arr(char **arr);
void				affect_2_vals(int *x1, int val1, int *x2, int val2);
void				affect_int(int *x, int val);
void				affect_int2(int *x, int val);

#endif
