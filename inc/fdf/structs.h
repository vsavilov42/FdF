/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:54 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/31 17:36:43 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_ang
{
	float	base;
	float	zoom;
	float	ang_x;
	float	ang_y;
	float	ang_z;
	int		i_x;
	int		i_y;
	int		isom;
}	t_ang;

typedef struct s_img
{
	void	*img;
	char	*addrs;
	int		bpp;
	int		ln_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	int		width;
	int		height;
	int		max_z;
	int		min_z;
	char	**cmap;
}	t_map;

typedef struct s_xyz
{
	int		x;
	int		y;
	int		z;
	int		color;
}	t_xyz;

typedef struct s_fdf
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	int				**cord;
	int				**colors;
	int				is_color;
	struct s_img	img;
	struct s_map	map;
	struct s_xyz	xyz;
	struct s_ang	ang;
}	t_fdf;

#endif
