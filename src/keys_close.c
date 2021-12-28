/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:31 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/28 15:43:28 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_hook(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_P)
	{
		printf("%d\n", fdf->ang.isom);
		if (fdf->ang.isom == 1)
			fdf->ang.isom = 0;
		else
			fdf->ang.isom = 1;
	}
	return (0);
}

int	x_close(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	exit(0);
	return (0);
}
