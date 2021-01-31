/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:05:38 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/31 22:46:37 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif
# define MAX 2147479552
# define MAXFD 1024

int		get_next_line(int fd, char **line);
size_t	len(const char *s);
void	ft_bzero(void *s, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strdup_join(char *s, char c);

#endif
