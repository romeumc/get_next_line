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


int		testfile()
{
	int             fd;
	int             i;
	int             j;
	char    		*line = 0;
	//char			*lineadress[66];
	
	j = 1;
	printf("\n==========================================\n");
	printf("========== TEST 1 : The Alphabet =========\n");
	printf("==========================================\n\n");

	if (!(fd = open("tester.mazoise/files/alphabet", O_RDONLY)))
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

int main()
{
	//test(0);
	testfile();
	// int	buffer_size;

	// buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
	// printf("%d", buffer_size);
}