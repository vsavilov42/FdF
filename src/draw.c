/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:22:17 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/24 17:07:30 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	bresenham(t_fdf *fdf, t_xyz f_px, t_xyz l_px)
{
	(void)fdf;
	(void)f_px;
	(void)l_px;
}

void	draw_bresenham(t_fdf *fdf)
{
	int x;
	int y;

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
	mlx_string_put(fdf->mlx, fdf->win, fdf->xyz.x, fdf->xyz.y, WHITE, "FdF map");
}

t_xyz	get_cords(t_ang *ang, t_xyz xyz)
{
	xyz.x *= ang->zoom;
	xyz.y *= ang->zoom;
	xyz.z *= (ang->zoom / 10) * ang->base;
	rotatex(ang, &xyz.y, &xyz.z);
	rotatey(ang, &xyz.x, &xyz.z);
	rotatez(ang, &xyz.x, &xyz.y);
	pov_iso(ang, &xyz.x, &xyz.y, &xyz.z);
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
