/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/21 01:17:09 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	int		i;
	char	*buffer;
	int		buffer_size;
	int		result;
	//char	*aux;

	buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
	if(!(buffer = malloc(sizeof(char) * buffer_size)))
		return (-1);
	if(!(*line = malloc(sizeof(char) * 100)))
		return (-1);
	result = -1;
	printf("\nROMEU\n");
	while (read(fd, buffer, buffer_size) && result == -1)
	{
		i = 0;
		printf("%d, %s | %d", i, buffer, buffer_size);
		while (buffer[i] != '\0' || buffer[i] != '\n')
		{
			printf("%d, %s | %d", i, buffer, buffer_size);
			*line[i] = buffer[i];
			i++;
		}
		*line[i] = '\0';
		if (buffer[i] == '\0')
			result = 0;
		if (buffer[i] == '\n')
			result = 1;
		free(buffer);
	}
	return (result);
}
