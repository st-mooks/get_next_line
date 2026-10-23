/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line_utils.c								:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/23 12:22:29 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/10/23 12:22:48 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "get_next_line.h"

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
	}
	free(line);
	return (new);
}

int	read_first_buffer(char **buf, ssize_t *len, int fd)
{
	static int	is_first_buffer = 1;

	if (is_first_buffer)
	{
		*buf = malloc(BUFFER_SIZE);
		if (!*buf)
			return (0);
		*len = read(fd, *buf, BUFFER_SIZE);
		is_first_buffer = 0;
	}
	return (1);
}

char	*read_next_line(char **buf, ssize_t *len, ssize_t *i, int fd)
{
	char	*line;

	line = malloc(1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (*len > 0)
	{
		while ((*buf)[*i] != '\n' && *i < *len)
			line = add_char(line, (*buf)[(*i)++]);
		if (*i >= *len)
		{
			*len = read(fd, *buf, BUFFER_SIZE);
			if (*len == 0)
				return (line);
			*i = 0;
		}
		if ((*buf)[*i] == '\n')
		{
			line = add_char(line, (*buf)[(*i)++]);
			return (line);
		}
	}
	return (NULL);
}
