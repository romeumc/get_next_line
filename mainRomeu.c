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

int main()
{
	printf("teste\n");
	test(0);
	// int	buffer_size;

	// buffer_size = (BUFFER_SIZE > 2147479552) ? 2147479552 : BUFFER_SIZE;
	// printf("%d", buffer_size);
}