/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/02/15 11:36:45 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_buff(char *buffer, char **line, int buff_len, int pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pos > 0)
		pos -= 1;
	while (j + i < buff_len + 1)
	{
		if (buffer[i + j] == '\0')
		{
			ft_strcpy(buffer, &buffer[i + j + 1]);
			return (pos + i + j + 1);
		}
		if (buffer[i + j] == '\n')
		{
			ft_strcpy(buffer, &buffer[i + j + 1]);
			return ((pos + i + j + 1) * -1);
		}
		line[0] = ft_strdup_join(line[0], buffer[i + j]);
		j++;
	}
	return (0);
}

void	clean_extra_buffer(char *buffer, int pos, int buffer_size)
{
	while (pos < buffer_size)
	{
		buffer[pos] = '\0';
		pos++;
	}
}

int		get_next_line(int fd, char **line)
{
	int			pos;
	static char	buff[MAXFD][BUFFER_SIZE + 1];
	int			ret;
	int			buffer_size;

	buffer_size = BUFFER_SIZE > MAX ? MAX : BUFFER_SIZE;
	if (buffer_size <= 0 || line == NULL || fd > MAXFD || fd < 0
		|| !(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	pos = len(buff[fd]) == 0 ? 0 : read_buff(buff[fd], line, len(buff[fd]), 0);
	if (pos < 0)
		return (1);
	ft_bzero(buff[fd], buffer_size);
	while ((ret = read(fd, buff[fd], buffer_size)))
	{
		if (ret < 0)
			return (-1);
		clean_extra_buffer(buff[fd], ret, buffer_size);
		pos = read_buff(buff[fd], line, ret, pos);
		if (pos < 0)
			return (1);
	}
	ft_bzero(buff[fd], buffer_size);
	return (0);
}
