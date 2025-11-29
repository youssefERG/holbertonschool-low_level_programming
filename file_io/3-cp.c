#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

/**
 * error_exit - print message to stderr and exit with code
 */
void error_exit(const char *msg, const char *file, int code)
{
	if (file)
		dprintf(STDERR_FILENO, msg, file);
	else
		dprintf(STDERR_FILENO, "%s", msg);
	exit(code);
}

/**
 * main - copies the contents of a file to another file.
 * Usage: cp file_from file_to
 * Exit codes:
 *  97 - incorrect arg count
 *  98 - can't read from file_from
 *  99 - can't write to file_to
 * 100 - can't close fd
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t r, w;
	char buf[1024];

	if (argc != 3)
		error_exit("Usage: cp file_from file_to\n", NULL, 97);

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
		error_exit("Error: Can't read from file %s\n", argv[1], 98);

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		close(fd_from);
		error_exit("Error: Can't write to %s\n", argv[2], 99);
	}

	while ((r = read(fd_from, buf, sizeof(buf))) > 0)
	{
		w = write(fd_to, buf, r);
		if (w == -1 || w != r)
		{
			close(fd_from);
			close(fd_to);
			error_exit("Error: Can't write to %s\n", argv[2], 99);
		}
	}

	if (r == -1)
	{
		close(fd_from);
		close(fd_to);
		error_exit("Error: Can't read from file %s\n", argv[1], 98);
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
