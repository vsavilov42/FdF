/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:35 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/11/24 14:15:40 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

/* init_struct.c */

void	init_structs();
void	init_fdf(t_fdf	*fdf);
void	init_map(t_map	*map);
void	init_xyz(t_xyz	*xyz);
void	init_img(t_img	*img);

/* read_file.c */

void	parse_map(t_fdf *fdf, char *map);
char	**save_map(char *map);
int	count_lines(char *map);

/* keys_close.c */

int	key_hook(int keycode);
int	x_close(int keycode, t_fdf *fdf);

/* error_msg.c */

int	tmarg(void);
int	invmap(void);

/* mlx_functions.c */

void	my_mlx_put_pixel(t_img *img, t_xyz *xyz);
void	mlx_control_keys(t_fdf *fdf);
void	mlx_start_img(t_fdf *fdf);

#endif
