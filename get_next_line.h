/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:05:38 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/31 12:39:35 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>
#include <ctype.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif
# define MAX 2147479552
# define MAXFD 1024
# define ABS(x) x > 0 ? x : -x

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *s);
void	ft_bzero(void *s, size_t n);

void	clear_buffer(char *buffer);
char	*shift_buffer(char *buffer, int pos);

char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup_join(char *s, char c);

#endif
