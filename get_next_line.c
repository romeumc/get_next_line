/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/23 00:35:04 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		print_buffer(char *buffer, char *callfunction, char **line)
{
	size_t i;

	i = 0;
	printf("CALL:%s | buffer_size:%ld ==> ", callfunction, ft_strlen(buffer));
	while (i < ft_strlen(buffer))
	{
		printf("%c", isprint(buffer[i]) ? buffer[i] : '?');
		i++;
	}
	printf(" | line:%s", *line);
	printf("\n");
}


int			read_buffer(char *buffer, char **line)
{
	size_t i;
	size_t j;

	i = 0;
	//print_buffer(buffer, "READ_BUFFER START", line);
	//printf("/////// size:%ld max_buffer:%d\n", ft_strlen(buffer), BUFFER_SIZE > MAX_BUFF ? MAX_BUFF : BUFFER_SIZE);
	if (ft_strlen(buffer) == (BUFFER_SIZE > MAX_BUFF ? MAX_BUFF : BUFFER_SIZE))
	{
		while (i < ft_strlen(buffer)) //&& buffer[i] !='\n'
		{
			//printf("i:%d | buffer[%d]:%c\n", i, i, buffer[i]);
			if (buffer[i] == '\n')
			{
				//printf("************* RETURN -1 ****************\n");
				i++;
				break;
			}
			i++;
		}
	}	
	j = 0;
	while (j + i < ft_strlen(buffer))
	{
		if (buffer[i + j] == '\n')
		{
			// buffer[0] = buffer[i + j + 1];
			// print_buffer(buffer, "*********** READ_BUFFER *******", line);
			return (-(i + j +1));
		}
		line[0][j] = buffer[i + j];
		//printf("* j:%d | buffer[%d]:%c | line:%s\n", j, j+i, buffer[i+j], *line);
		j++;
	}
	//print_buffer(buffer, "READ_BUFFER END", line);
	return (j);
}

int			get_next_line(int fd, char **line)
{
	int			i;
	int			j;
	static char	buffer[(BUFFER_SIZE > MAX_BUFF ? MAX_BUFF : BUFFER_SIZE)];
	int			ret;
	//char		*temp;
	
	if (fd < 0)
		return (-1);
	
	if (!(line[0] = malloc(sizeof(char) * 1000)))
		return (-1);
	
	
	if (buffer[0] == '\0')
	{
		//printf("AQUI 1\n");
		j = 0;
	}
	else
	{
		//printf("AQUI 2\n");
		j = read_buffer(buffer, line);
	}
	if (j < 0)
	{
		//temp = ft_strdup(&buffer[-j]);
		ft_strcpy(buffer, &buffer[-j]);
		//printf("BUFFER AQUUIIIII: %d => %s | %ld\n", j, buffer, ft_strlen(buffer));
		//print_buffer(buffer, "*********** READ_BUFFER *******", line);
		return (1);
	}
	//print_buffer(buffer, "MAIN START", sizeof(buffer), line);
	while ((ret = read(fd, buffer, sizeof(buffer))))
	{
		//print_buffer(buffer, "MAIN WHILE", sizeof(buffer), line);
		//printf("********** ret:%d\n", ret);
		i = 0;
		//printf("i:%d, buffer:%s | buffer_size:%d\n", i, buffer, buffer_size);
		while (i < ret)
		{
			if (buffer[i] == '\n')
			{
				//print_buffer(buffer, "MAIN RETURN 1", sizeof(buffer), line);
				line[0][i + j] = '\0';
				if (ret >= (int)sizeof(buffer))
				{
					//printf("********************** RETURN 1\n");
					return (1);
				}
				// else
				// {
				// 	printf("********************** RETURN 0\n");
				// 	return (0);
				// }
			}
			line[0][i + j] = buffer[i];
			i++;
			//print_buffer(buffer, "MAIN MIDDLE", sizeof(buffer), line);
		}
		j += i;
		//printf("RESULT ==> %d | i:%d | j:%d | line:%s\n", result, i, j, line[0]);
	}
	//print_buffer(buffer, "MAIN END", sizeof(buffer), line);

	return (0);
}
