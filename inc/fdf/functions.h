/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:35 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/11/23 13:55:27 by Vsavilov         ###   ########.fr       */
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

/* keys_close.c */

void	mlx_control_keys(t_fdf *fdf);
int	key_hook(int keycode);
int	x_close(int keycode, t_fdf *fdf);

#endif
