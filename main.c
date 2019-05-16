#include "get_next_line.h"
#include "../libft/libft.h"
#include <fcntl.h>
#include <stdio.h> 

int main(void)
{
	char *s1 = "12345\n54321\n1234567890\n0987654321";
	char *s2 = "asdfghjkl\nlkjhgfdsa\nabcdef\nFINAL";
	int fd1 = open("test3.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	int fd2 = open("test4.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	if (fd1 == -1)
		ft_putstr_fd("open() error\n", 2);
	if (fd2 == -1)
		ft_putstr_fd("open() error\n", 2);
	size_t n_bites1 = write(fd1, s1, strlen(s1));
	size_t n_bites2 = write(fd2, s2, strlen(s2));
	fd1 = close(fd1);
	fd2 = close(fd2);
	if (fd1 == -1)
		ft_putstr_fd("close() error\n", 2);	
	if (fd2 == -1)
		ft_putstr_fd("close() error\n", 2);	
	char** line1 = (char**)malloc(n_bites1);
	char** line2 = (char**)malloc(n_bites2);
	int temp1;
	fd1 = open("test3.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	fd2 = open("test4.txt", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
	printf("%i\n", (temp1 = get_next_line(fd1, line1)));
	printf("%s\n", *line1);
	printf("%i\n", get_next_line(fd2, line2));
	printf("%s\n", *line2);
	printf("%i\n", get_next_line(fd1, line1));
	printf("%s\n", *line1);
	printf("%i\n", get_next_line(fd2, line2));
	printf("%s\n", *line2);
	printf("%i\n", get_next_line(fd1, line1));
	printf("%s\n", *line1);
	printf("%i\n", get_next_line(fd2, line2));
	printf("%s\n", *line2);
	printf("%i\n", get_next_line(fd1, line1));
	printf("%s\n", *line1);
	printf("%i\n", get_next_line(fd2, line2));
	printf("%s\n", *line2);
	fd1 = close(fd1);
	if (fd1 == -1)
		ft_putstr_fd("close() error\n", 2);	
	fd2 = close(fd2);
	if (fd2 == -1)
		ft_putstr_fd("close() error\n", 2);
	return (0);
}
