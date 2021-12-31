/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:31 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/31 17:16:39 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		exit(0);
	if (keycode == KEY_R)
		init_ang(fdf, &fdf->ang);
	if (keycode == KEY_A || keycode == KEY_S
		|| keycode == KEY_D || keycode == KEY_W)
		key_move(fdf, keycode);
	if (keycode == KEY_Q || keycode == KEY_E)
		key_zoom(fdf, keycode);
	if (keycode == KEY_Z || keycode == KEY_X
		|| keycode == KEY_C || keycode == KEY_V
		|| keycode == KEY_B || keycode == KEY_N)
		key_rotation(fdf, keycode);
	if (keycode == KEY_F || keycode == KEY_G)
		key_height(fdf, keycode);
	if (keycode == KEY_P)
	{
		if (fdf->ang.isom == 1)
			fdf->ang.isom = 0;
		else
			fdf->ang.isom = 1;
	}
	draw_bresenham(fdf);
	return (0);
}

void	key_height(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_F)
		if (fdf->ang.base < 10)
			fdf->ang.base += 0.1;
	if (keycode == KEY_G)
		if (fdf->ang.base > -10)
			fdf->ang.base -= 0.1;
}

void	key_move(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_A)
		fdf->ang.i_x -= 10;
	if (keycode == KEY_D)
		fdf->ang.i_x += 10;
	if (keycode == KEY_S)
		fdf->ang.i_y += 10;
	if (keycode == KEY_W)
		fdf->ang.i_y -= 10;
}

void	key_zoom(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_Q)
		if (fdf->ang.zoom < 2147483647)
			fdf->ang.zoom += 0.5;
	if (keycode == KEY_E)
		if (fdf->ang.zoom > 0)
			fdf->ang.zoom -= 0.5;
}

void	key_rotation(t_fdf *fdf, int keycode)
{
	if (keycode == KEY_Z)
		fdf->ang.ang_x += 0.05;
	if (keycode == KEY_X)
		fdf->ang.ang_x -= 0.05;
	if (keycode == KEY_C)
		fdf->ang.ang_y += 0.05;
	if (keycode == KEY_V)
		fdf->ang.ang_y -= 0.05;
	if (keycode == KEY_B)
		fdf->ang.ang_z += 0.05;
	if (keycode == KEY_N)
		fdf->ang.ang_z -= 0.05;
}
