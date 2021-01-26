/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_romeu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmartins <rmartins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 21:08:42 by rmartins          #+#    #+#             */
/*   Updated: 2021/01/23 22:53:50 by rmartins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../get_next_line.h"

void	doprint(int out, char **str, int line)
{
	printf("(LINE %i) [OUT %i] |%s|\n", line, out, *str);
	free(*str);
	*str = NULL;
}

void	test(int fd)
{
	char	*st;
	int		out;
	int		i;

	st = NULL;
	i = 1;
	out = 1;
	while (out == 1)
	{
		out = get_next_line(fd, &st);
		doprint(out, &st, i++);
	}
	close(fd);
}

int		testfile(char *filename)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	line = 0;
	j = 1;
	printf("\n\n=== TESTE - %s - BUFF_SIZE:%d ===\n\n", filename, BUFFER_SIZE);
	if (!(fd = open(filename, O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("[OUT %d] |%s|\n", i, line);
		j++;
	}
	printf("[OUT %d] |%s|\n", i, line);
	free(line);
	close(fd);
	return (0);
}

int		testfd(void)
{
	char	*line;

	line = 0;
	printf("\n==========================================\n");
	printf("========= TEST 8 : Wrong Input ===========\n");
	printf("==========================================\n\n");
	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if no FD\n\n");
	else
		printf("Not Good, you don't return -1 if no FD\n\n");
	return (0);
}

int		main(void)
{
	// testfd();
	testfile("../tester.mrjvs/tests/normal/5.txt");
	testfile("../tester.mrjvs/tests/normal/1.txt");
	testfile("../tester.mrjvs/tests/normal/4.txt");
	testfile("romeu.tester/teste1.txt");
	//testfile("tester.mazoise/files/alphabet");
	//testfile("tester.mazoise/files/huge_alphabet");
	//test(0);
}
