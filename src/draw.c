/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:22:17 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/17 18:22:18 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	draw_bresenham(t_fdf *fdf, t_ang *ang)
{
	(void)ang;
	mlx_string_put(fdf->mlx, fdf->win, fdf->xyz.x, fdf->xyz.y, WHITE, "hello");
}
