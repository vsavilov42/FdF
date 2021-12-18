/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:31 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/17 18:21:47 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	key_hook(int keycode)
{
	if (keycode == ESC)
		exit(0);
	return (0);
}

int	x_close(int keycode, t_fdf *fdf)
{
	(void)keycode;
	(void)fdf;
	exit(0);
	return (0);
}
