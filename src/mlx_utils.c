/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:20:19 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/02 17:23:10 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int	base_zoom(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

void	init_ang(t_fdf *fdf, t_ang *ang)
{
	ang->zoom = base_zoom((WIN_W / fdf->width / 2), (WIN_H / fdf->height / 2));
	ang->base = 1;
	ang->i_x = WIN_W / 2;
	ang->i_y = (WIN_H - fdf->height * ang->zoom) / 2;
	ang->isom = 1;
	ang->ang_x = 0;
	ang->ang_y = 0;
	ang->ang_z = 0;
}

int	x_close(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	exit(0);
	return (0);
}
