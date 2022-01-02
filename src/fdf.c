/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:23:22 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/02 14:25:34 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (tmarg());
	fdf = (t_fdf *)ft_calloc(1, (sizeof(t_fdf)));
	init_fdf(fdf);
	parse_map(fdf, argv[1]);
	mlx_start_img(fdf);
	return (0);
}
