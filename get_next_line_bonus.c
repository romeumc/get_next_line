/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/31 16:52:43 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void		print_buffer(char *buffer, char *callfunction, char **line, int ret)
{
	size_t i;

	printf("    call:%s      | ret:%d [", callfunction, ret);
	i = 0;
	while (i < (size_t)ret)
	{
		printf("%c", isprint(buffer[i]) ? buffer[i] : '?');
		i++;
	}
	printf("]      | strlen:%ld [", ft_strlen(buffer));
	i = 0;
	while (i < ft_strlen(buffer))
	{
		printf("%c", isprint(buffer[i]) ? buffer[i] : '*');
		i++;
	}
	printf("] '\\0'[");
	i = 0;
	while (buffer[i] != '\0')
	{
		printf("%c", isprint(buffer[i]) ? buffer[i] : '*');
		i++;
	}
	printf("] | line:%s", *line);
	printf("\n");
}

int			read_buffer(char *buffer, char **line, int buff_len, int pos)
{
	int i;
	int j;

	i = 0;
	j = 0;
	pos = (pos <= 0) ? 0 : pos - 1;
	//print_buffer(buffer, "READ_BUFFER()   ", line, buff_len);
	while (j + i < buff_len + 1)
	{
		if (buffer[i + j] == '\0')
		{
			ft_strcpy(buffer, &buffer[i + j + 1]);
			//buffer = shift_buffer(buffer, i + j + 1);
			return (pos + i + j + 1);
		}
		if (buffer[i + j] == '\n')
		{
			//print_buffer(buffer, "READ_BUFFER(\\n) ", line, buff_len);
			ft_strcpy(buffer, &buffer[i + j + 1]);
			//buffer = shift_buffer(buffer, i + j + 1);
			return (-(pos + i + j + 1));
		}
		//line[0][j + pos] = buffer[i + j];
		line[0] = ft_strdup_join(line[0], buffer[i + j]);
		//printf("line:%s\n", *line);
		//printf("* line[%ld]:%c | buffer[%ld]:%c | line:%s\n", j+pos, line[0][j+pos], j+i, buffer[i+j],  *line);
		j++;
	}
	return (0);
}

void		clean_extra_buffer(char *buffer, int pos, int buffer_size)
{
	while (pos < buffer_size)
	{
		buffer[pos] = '\0';
		pos++;
	}
}

int			get_next_line(int fd, char **line)
{
	int			pos;
	//static char	buffer[MAXFD][(BUFFER_SIZE < 0 ? 1 : BUFFER_SIZE) > MAX ? MAX : (BUFFER_SIZE < 0 ? 1 : BUFFER_SIZE + 1)];
	static char	buffer[MAXFD][BUFFER_SIZE + 1];
	int			ret;
	int			buffer_size;

	buffer_size = BUFFER_SIZE > MAX ? MAX : BUFFER_SIZE;
	if (buffer_size <= 0 || line == NULL || fd > MAXFD || fd < 0 || read(fd, 0, 0) < 0)
		return (-1);
	if (!(*line = malloc(sizeof(char))))
		return (-1);
	*line[0] = '\0';
	//print_buffer(buffer[fd], "INI             ", line, ft_strlen(buffer[fd]));
	pos = ft_strlen(buffer[fd]) == 0 ? 0 : read_buffer(buffer[fd], line, ft_strlen(buffer[fd]), 0);
	if (pos < 0)
		return (1);
	ft_bzero(buffer[fd], buffer_size);
	while ((ret = read(fd, buffer[fd], buffer_size)))
	{
		//printf("**** buffer READ - ret:%d length:%ld | [%s]\n", ret, ft_strlen(buffer[fd]), buffer[fd]);
		clean_extra_buffer(buffer[fd], ret, buffer_size);
		//print_buffer(buffer[fd], "main READ begin ", line, ret);
		pos = read_buffer(buffer[fd], line, ret, pos);
		//print_buffer(buffer[fd], "MAIN while end  ", line, ret);
		
		if (pos < 0)
			return (1);
	}
	//print_buffer(buffer[fd], "MAIN END        ", line, ret);
	ft_bzero(buffer[fd], buffer_size);
	return (0);
}
