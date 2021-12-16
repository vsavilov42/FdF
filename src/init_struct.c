/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:37:59 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/15 17:34:51 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	init_structs(t_fdf *fdf)
{
	init_xyz(fdf->xyz);
	init_img(fdf->img);
	init_fdf(fdf);
}

void	init_fdf(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIN_W, WIN_H, "FdF");
	fdf->img.img = mlx_new_image(fdf->mlx, WIN_W, WIN_H);
}

void	init_img(t_img img)
{
	img.addrs = NULL;
	img.bpp = 0;
	img.ln_len = 0;
}

/*void	init_map(t_map map)
{
	map.max_z = 0;
	map.min_z = 0;
}*/

void	init_xyz(t_xyz xyz)
{
	xyz.x = 0;
	xyz.y = 0;
	xyz.z = 0;
	xyz.color = WHITE;
}
