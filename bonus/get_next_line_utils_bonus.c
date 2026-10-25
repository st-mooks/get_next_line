#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	offset;

	if (!dest || !src)
		return (NULL);
	i = 0;
	if ((uintptr_t)dest > (uintptr_t)src)
	{
		while (i < n)
		{
			offset = n - i - 1;
			*((char *)dest + offset) = *((char *)src + offset);
			i++;
		}
	}
	else
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	return (dest);
}

char	*add_char(char *line, char c)
{
	char	*new;
	size_t	line_len;

	if (!line)
	{
		new = malloc(2);
		if (!new)
			return (NULL);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		line_len = ft_strlen(line);
		new = malloc(line_len + 2);
		ft_memmove(new, line, line_len);
		new[line_len] = c;
		new[line_len + 1] = '\0';
		free(line);
	}
	return (new);
}

char    *read_next_line(char **buf, int fd)
{
    char    *line;
    ssize_t len;

    line = NULL;
    while (**buf)
    {
        while (**buf != '\n' && **buf)
        {
            line = add_char(line, **buf);
            *buf += 1;
        }
        if (!**buf)
        {
            len = read(fd, *buf, BUFFER_SIZE);
            if (len == 0)
                return (line);
            *buf[len] = '\0';
        }
        if (**buf == '\n')
        {
            line = add_char(line, **buf);
            *buf += 1;
            return (line);
        }
    }
    return (NULL);
}