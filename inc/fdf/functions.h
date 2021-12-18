/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:35 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/17 17:34:35 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H


/* init_struct.c */

void	init_structs(t_fdf *fdf);
void	init_fdf(t_fdf	*fdf);
void	init_xyz(t_xyz xyz);
void	init_img(t_img	img);

/* read_file.c */

void	parse_map(t_fdf *fdf, char *map);
void	open_map(t_fdf *fdf, char *map);
void	memory_map(t_fdf *fdf);
void	cord_colors(t_fdf *fdf, char *cmap);
int	get_color(char *clr);

/* keys_close.c */

int	key_hook(int keycode);
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

void	my_mlx_put_pixel(t_img img, t_xyz xyz);
void	mlx_control_keys(t_fdf *fdf);
void	mlx_start_img(t_fdf *fdf);
void	mlx_managment(t_fdf *fdf);

/* mlx_utils.c */

void	init_ang(t_fdf *fdf, t_ang *ang);

/* draw.c */

void	draw_bresenham(t_fdf *fdf , t_ang *ang);

#endif
