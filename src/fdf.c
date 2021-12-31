/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:23:22 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/31 17:23:13 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc != 2)
		return (tmarg());
	fdf = (t_fdf *)ft_calloc(1, (sizeof(t_fdf)));
	init_structs(fdf);
	parse_map(fdf, argv[1]);
	mlx_start_img(fdf);
	return (0);
}
