#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1] = "";
    ssize_t     len;
    char        *line;
    static char *ptr;

    if (!*ptr)
    {
        ptr = buf;
        len = read(fd, ptr, BUFFER_SIZE);
        ptr[len] = '\0';
    }
    if (len <= 0)
        return (NULL);
    line = read_next_line(&ptr, fd);
    return (line);
}
