/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:35 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/28 15:46:39 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H


/* init_struct.c */

void	init_structs(t_fdf *fdf);
void	init_fdf(t_fdf	*fdf);
void	init_xyz(t_xyz xyz);
void	init_img(t_img	img);
void	init_bresenham(t_xyz *first, t_xyz *last, t_xyz *sign, t_xyz *delta);

/* read_file.c */

void	parse_map(t_fdf *fdf, char *map);
void	open_map(t_fdf *fdf, char *map);
void	memory_map(t_fdf *fdf);
void	cord_colors(t_fdf *fdf, char *cmap);
int	get_color(t_fdf *fdf, char *clr);

/* keys_close.c */

int	key_hook(int keycode, t_fdf *fdf);
int	x_close(int keycode, t_fdf *fdf);

/* error_msg.c */

int	tmarg(void);
int	invmap(void);
int	emap(void);
int	eang(void);

/* utils.c */

void	free_split(char **split);
int	count_nums(char *map);
int	hex_color(char	*clr);
void	min_max_z(t_fdf *fdf);

/* mlx_functions.c */

void	my_mlx_put_pixel(t_img img, int x, int y, int color);
void	mlx_control_keys(t_fdf *fdf);
void	mlx_start_img(t_fdf *fdf);
void	mlx_managment(t_fdf *fdf);

/* mlx_utils.c */

void	init_ang(t_fdf *fdf, t_ang *ang);

/* draw.c */

void	draw_bresenham(t_fdf *fdf);
void	bresenham(t_fdf *fdf, t_xyz f_px, t_xyz l_px);
t_xyz	new_pixel(t_fdf *fdf, int x, int y);
t_xyz	get_cords(t_ang *ang, t_xyz xyz);

/* draw_utils.c */

int	sign_bres(int delta);
void	rotatex(t_ang *ang, int *y, int *z);
void	rotatey(t_ang *ang, int *x, int *z);
void	rotatez(t_ang *ang, int *x, int *y);
void	pov_iso(t_ang *ang, int *x, int *y, int z);

/* colors.c */

int	colorxy(t_xyz now, t_xyz first, t_xyz last, t_xyz tmp);
int	colorz(t_fdf *fdf, int z);

#endif
