#include "libmx.h"

int mx_read_line(char **lineptr, int temp_size, char delim, const int fd) {
	char *ptr = mx_strnew(0);
	char *temp = mx_strnew(temp_size);
	char *tmp;
	int r;

	if (fd > 0 && lineptr && temp_size > 0 && delim) {
		while ((r = read(fd, temp, temp_size)) > 0) {
			tmp = ptr;
			ptr = mx_strjoin(ptr, temp);
			free(tmp);
			if (mx_memchr(temp, delim, temp_size) != NULL)
				break ;
		}
		free(temp);
		if (r == 0) {
			free(ptr);
			return 0;
		}
		*lineptr = mx_strndup(ptr, mx_get_char_index(ptr, delim));
		free(ptr);
		return mx_strlen(*lineptr);
	}
	return -1;
}
