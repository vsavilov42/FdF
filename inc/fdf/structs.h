/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:54 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/11/23 13:58:09 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_fdf
{
	void	*mlx;
	void	*win;
	struct	s_img	*img;
	struct	s_map	*map;
	struct	s_xyz	*xyz;
}	t_fdf;

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
	int	*colors;
	char	**cmap;
}	t_map;

typedef struct s_xyz
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_xyz;

#endif
