/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 17:21:33 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/12/31 17:21:55 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	tmarg(void)
{
	write(STDOUT_FILENO, "usage ./fdf map.fdf\n", 21);
	return (1);
}

int	invmap(void)
{
	perror("Invalid map");
	return (1);
}

int	emap(void)
{
	perror("Empty map");
	return (1);
}
