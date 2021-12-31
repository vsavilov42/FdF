/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:37:59 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/31 17:08:29 by Vsavilov         ###   ########.fr       */
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

void	init_xyz(t_xyz xyz)
{
	xyz.x = 0;
	xyz.y = 0;
	xyz.z = 0;
	xyz.color = WHITE;
}

void	init_bresenham(t_xyz *first, t_xyz *last, t_xyz *sign, t_xyz *delta)
{
	delta->x = sign_bres(last->x - first->x);
	sign->x = -1;
	if (first->x < last->x)
		sign->x = 1;
	delta->y = sign_bres(last->y - first->y);
	sign->y = -1;
	if (first->y < last->y)
		sign->y = 1;
}
