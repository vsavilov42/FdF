/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 11:10:35 by Vsavilov          #+#    #+#             */
/*   Updated: 2021/11/22 18:20:33 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void	init_structs();
void	init_fdf(t_fdf	*fdf);
void	init_map(t_map	*map);
void	init_xyz(t_xyz	*xyz);
void	init_img(t_img	*img);
void	parse_map();


#endif
