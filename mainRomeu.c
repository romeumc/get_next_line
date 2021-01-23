#include <fcntl.h>

#include "get_next_line.h"

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
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	//char			*lineadress[66];
	
	j = 1;
	printf("\n\n========== TESTE - %s - BUFFER_SIZE:%d =========\n\n", filename, BUFFER_SIZE);

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

int		testfd()
{
	char    		*line = 0;
	printf("\n==========================================\n");
	printf("========= TEST 8 : Wrong Input ===========\n");
	printf("==========================================\n\n");

	if (get_next_line(180, &line) == -1)
		printf("Well Done, you return -1 if no FD\n\n");
	else
		printf("Not Good, you don't return -1 if no FD\n\n");
	return (0);
}

int main()
{
	//test(0);
	//testfile("tester.mrjvs/tests/normal/5.txt");
	testfile("tester.mrjvs/tests/normal/1.txt");
	//testfile("tester.mrjvs/tests/normal/4.txt");
	//testfile("tester.mazoise/files/alphabet");
	//testfile("tester.mazoise/files/huge_alphabet");
	//testfd();
	
	// int	buffer_size;

	// buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
	// printf("%d", buffer_size);
}