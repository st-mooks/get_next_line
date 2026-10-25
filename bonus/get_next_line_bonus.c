#include "get_next_line_bonus.h"

char    *get_next_line(int fd)
{
    static char buf[BUFFER_SIZE + 1] = "";
    ssize_t     len;
    char        *line;

    if (!buf[0])
    {
        len = read_next_buffer(fd, buf);
        if (len <= 0)
            return (NULL);
    }
    line = read_next_line(buf, fd);
    return (line);
}
