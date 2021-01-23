/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/23 20:15:53 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
			return (pos + i + j + 1);
		}
		if (buffer[i + j] == '\n')
		{
			//print_buffer(buffer, "READ_BUFFER(\\n) ", line, buff_len);
			ft_strcpy(buffer, &buffer[i + j + 1]);
			return (-(pos + i + j +1));
		}
		line[0][j + pos] = buffer[i + j];
		//printf("* line[%ld]:%c | buffer[%ld]:%c | line:%s\n", j+pos, line[0][j+pos], j+i, buffer[i+j],  *line);
		j++;
	}
	return (0);
}

void		clean_extra_buffer(char *buffer, int pos)
{
	while (pos < (int)ft_strlen(buffer))
	{
		buffer[pos] = '\0';
		pos++;
	}
}

int			get_next_line(int fd, char **line)
{
	int			pos;
	static char	buffer[(BUFFER_SIZE < 0 ? 1 : BUFFER_SIZE) > MAX ? MAX : (BUFFER_SIZE < 0 ? 1 : BUFFER_SIZE)];
	int			ret;
	int			buffer_size;

	buffer_size = BUFFER_SIZE > MAX ? MAX : BUFFER_SIZE;
	if (fd < 0 || line == NULL || buffer_size <= 0)
		return (-1);
	if (!(line[0] = malloc(sizeof(char) * 100)))
		return (-1);
	
	//print_buffer(buffer, "INI             ", line, ft_strlen(buffer));
	pos = ft_strlen(buffer) == 0 ? 0 : read_buffer(buffer, line, ft_strlen(buffer), 0);
	if (pos < 0)
	{
		return (1);
	}
	while ((ret = read(fd, buffer, buffer_size)))
	{
		if (ret < (int)ft_strlen(buffer))
		{
			//printf("**** buffer READ - ret:%d length:%ld | [%s]\n", ret, ft_strlen(buffer), buffer);
			clean_extra_buffer(buffer, ret);
		}
		//print_buffer(buffer, "main READ begin ", line, ret);
		if (ret < 0)
		{
			*line = NULL;
			return (-1);
		}
		pos = read_buffer(buffer, line, ret, pos);
		//print_buffer(buffer, "MAIN while end  ", line, ret);
		
		if (pos < 0)
			return (1);
	}
	//print_buffer(buffer, "MAIN END        ", line, ret);
	ft_bzero(buffer, buffer_size);
	return (0);
}
