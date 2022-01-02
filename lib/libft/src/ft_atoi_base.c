/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Vsavilov <Vsavilov@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:33:07 by Vsavilov          #+#    #+#             */
/*   Updated: 2022/01/02 17:27:43 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	next_num(const char *base, char c)
{
	int	n;

	n = 0;
	while (*base && *base != c)
	{
		n++;
		base++;
	}
	return (n);
}

static int	char_to_int(const char *num, const char *base, long int pw, int n_b)
{
	int	n;

	n = 0;
	while (*num)
	{
		n += next_num(base, *num) * pw;
		pw /= n_b;
		num++;
	}
	return (n);
}

static int	num_base(const char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (ft_strchr(&base[i + 1], base[i]))
			return (0);
		i++;
	}
	return (i);
}

int	ft_atoi_base(const char *num, const char *base)
{
	char		*tmp;
	int			n_base;
	long int	pw;

	pw = 1;
	n_base = num_base(base);
	tmp = (char *)num;
	if (*num == '-' && num++)
		pw = -1;
	else if (*num == '+')
		num++;
	while (*num && ft_strchr(base, *num))
	{
		pw *= n_base;
		num++;
	}
	pw /= n_base;
	return (char_to_int(tmp, base, pw, n_base));
}
