/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:15:31 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/21 00:37:28 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int			get_next_line(int fd, char **line)
{
	int		i;
	char	*buffer;
	int		buffer_size;
	int		result;
	char	*aux;

	buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
	if(!(buffer = malloc(sizeof(char) * buffer_size)))
		return (-1);
	// if(!(aux = malloc(sizeof(char) * 1)))
	// 	return (-1);
	result = -1;
	while (read(fd, buffer, buffer_size) && result == -1)
	{
		i = 0;
		while (buffer[i] != '\0' || buffer[i] != '\n')
		{
			//*line = ft_strdup();
			i++;
		}
		if (buffer[i] == '\0')
			result = 0;
		if (buffer[i] == '\n')
			result = 1;
		free(buffer);
	}
	return (result);
}

// int main()
// {
// 	int	buffer_size;

// 	buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
// 	printf("%d", buffer_size);
// }