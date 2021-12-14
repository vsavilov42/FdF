/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:54 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/13 23:41:59 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef	struct s_img
{
	void	*img;
	char	*addrs;
	int	bpp;
	int	ln_len;
	int	endian;
}	t_img;

typedef struct s_map
{
	int	width;
	int	height;
	int	max_z;
	int	min_z;
	char	**cmap;
}	t_map;

typedef struct s_xyz
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_xyz;

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	int	width;
	int	height;
	int	**cord;
	int	**colors;
	struct	s_img	img;
	struct	s_map	map;
	struct	s_xyz	xyz;
}	t_fdf;

#endif
