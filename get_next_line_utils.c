/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 23:32:01 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/22 23:30:12 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_strdup(const char *s)
{
	int		i;
	char	*temp;

	i = 0;
	temp = (char *)malloc(ft_strlen(s) + 1);
	if (temp != NULL)
	{
		while (s[i] != '\0')
		{
			temp[i] = s[i];
			i++;
		}
		temp[i] = '\0';
		return (temp);
	}
	return (NULL);
}