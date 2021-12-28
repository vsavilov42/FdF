/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:22:17 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/28 17:04:29 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham(t_fdf *fdf, t_xyz f_px, t_xyz l_px)
{
	t_xyz	sign;
	t_xyz	fdpx;
	t_xyz	delta;
	int	tmp;
	int	line;

	init_bresenham(&f_px, &l_px, &sign, &delta);
	line = (delta.x - delta.y);
	fdpx = f_px;
	while (fdpx.x != l_px.x || fdpx.y != l_px.y)
	{
		my_mlx_put_pixel(fdf->img, fdpx.x, fdpx.y, colorxy(fdpx, f_px, l_px, delta));
		tmp = line * 2;
		if (tmp > -delta.y)
		{
			line -= delta.y;
			fdpx.x += sign.x;
		}
		if (tmp < delta.x)
		{
			line += delta.x;
			fdpx.y += sign.y;
		}
	}
}

void	draw_bresenham(t_fdf *fdf)
{
	int	x;
	int	y;

	ft_bzero(fdf->img.addrs, WIN_H * WIN_W * (fdf->img.bpp / 8));
	if (fdf->ang.zoom)
	{
		y = -1;
		while (++y < fdf->height)
		{
			x = -1;
			while (++x < fdf->width)
			{
				if (x < fdf->width -1)
					bresenham(fdf,
							get_cords(&fdf->ang, new_pixel(fdf, x, y)),
							get_cords(&fdf->ang, new_pixel(fdf, x + 1, y)));
				if (y < fdf->height - 1)
					bresenham(fdf,
							get_cords(&fdf->ang, new_pixel(fdf, x, y)),
							get_cords(&fdf->ang, new_pixel(fdf, x, y + 1)));
			}
		}
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img.img, 0, 0);
}

t_xyz	get_cords(t_ang *ang, t_xyz xyz)
{
	xyz.x *= ang->zoom;
	xyz.y *= ang->zoom;
	xyz.z *= (ang->zoom / 10) * ang->base;
	rotatex(ang, &xyz.y, &xyz.z);
	rotatey(ang, &xyz.x, &xyz.z);
	rotatez(ang, &xyz.x, &xyz.y);
	pov_iso(ang, &xyz.x, &xyz.y, xyz.z);
	printf("X%d Y%d Z%d\n", xyz.x, xyz.y, xyz.z);
	return (xyz);
}

t_xyz	new_pixel(t_fdf *fdf, int x, int y)
{
	t_xyz n_pxl;

	n_pxl.x = x;
	n_pxl.y = y;
	n_pxl.z = fdf->cord[y][x];
	if (fdf->is_color == 1)
		n_pxl.color = fdf->colors[y][x];
	else
		n_pxl.color = colorz(fdf, n_pxl.z);
	return (n_pxl);
}
