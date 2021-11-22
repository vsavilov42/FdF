/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsavilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 09:58:36 by vsavilov          #+#    #+#             */
/*   Updated: 2021/11/22 18:39:49 by Vsavilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

char	*get_current_line(char **str)
{
	size_t	i;
	char	*tmp;
	char	*tmpout;

	tmpout = NULL;
	i = 0;
	while ((*str)[i] != '\n' && (*str)[i])
		i++;
	if ((*str)[i] == '\n')
	{
		tmpout = ft_substr(*str, 0, i + 1);
		tmp = ft_strdup(*str + i + 1);
		free(*str);
		*str = tmp;
		if (!**str)
		{
			free(*str);
			*str = NULL;
		}
		return (tmpout);
	}
	tmpout = ft_strdup(*str);
	free(*str);
	*str = NULL;
	return (tmpout);
}

static void	re_read(int fd, char *text, char **stext, ssize_t buff)
{
	char	*tmptext;

	tmptext = NULL;
	while (buff > 0)
	{
		text[buff] = '\0';
		if (stext[fd] == NULL)
			stext[fd] = ft_strdup("");
		tmptext = ft_strjoin(stext[fd], text);
		free(stext[fd]);
		stext[fd] = tmptext;
		if (ft_strchr(text, '\n'))
			break ;
		buff = read(fd, text, BUFFER_SIZE);
	}
	free(text);
}

char	*get_next_line(int fd)
{
	char		*text;
	static char	*stext[FDM];
	ssize_t		buff;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	text = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (text == NULL)
		return (NULL);
	buff = read(fd, text, BUFFER_SIZE);
	re_read(fd, text, stext, buff);
	if (buff < 0)
		return (NULL);
	if (!buff && (!stext[fd] || !*stext[fd]))
		return (NULL);
	return (get_current_line(&stext[fd]));
}
