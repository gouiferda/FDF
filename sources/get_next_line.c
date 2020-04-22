/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 23:06:46 by sgouifer          #+#    #+#             */
/*   Updated: 2018/11/05 23:06:46 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_line(char **tab, char **line, int fd)
{
	int	len;

	len = 0;
	while (tab[fd][len] != '\0' && tab[fd][len] != '\n')
		len++;
	if (tab[fd][len] == '\n')
	{
		*line = ft_strsub(tab[fd], 0, len);
		tab[fd] = ft_strdup(tab[fd] + len + 1);
	}
	else if (tab[fd][len] == '\0')
	{
		*line = ft_strdup(tab[fd]);
		ft_strdel(&tab[fd]);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE + 1];
	int			ret;
	static char	*tab[1024];

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (tab[fd] == NULL)
			tab[fd] = ft_strnew(1);
		tab[fd] = ft_strjoin(tab[fd], buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	if (ret == 0 && (tab[fd] == NULL || tab[fd][0] == '\0'))
		return (0);
	return (get_line(tab, line, fd));
}
