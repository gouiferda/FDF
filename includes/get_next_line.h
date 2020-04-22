/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 11:22:31 by sgouifer          #+#    #+#             */
/*   Updated: 2018/11/02 11:22:31 by sgouifer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "sys/types.h"
# include "sys/uio.h"
# include "libft.h"

# define BUFF_SIZE 32

int		get_line(char **tmp, char **line, int fd);
int		get_next_line(const int fd, char **line);

#endif
