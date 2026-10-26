/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line_utils_bonus.c						:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/25 11:07:50 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/10/25 13:58:25 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

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

char	*add_char(char *str, char c)
{
	char	*new;
	size_t	len;

	if (!str)
	{
		new = malloc(2);
		if (!new)
			return (NULL);
		new[0] = c;
		new[1] = '\0';
	}
	else
	{
		len = ft_strlen(str);
		new = malloc(len + 2);
		if (!new)
			return (NULL);
		ft_memmove(new, str, len);
		new[len] = c;
		new[len + 1] = '\0';
	}
	free(str);
	return (new);
}

void	parse_buffer(char **line, char *buf, int fd)
{
	int		i;
	ssize_t	len;

	i = 0;
	len = (ssize_t)ft_strlen(buf);
	while (buf[i] && buf[i] != '\n')
		*line = add_char(*line, buf[i++]);
	if (buf[i] == '\n')
	{
		*line = add_char(*line, buf[i++]);
		ft_memmove(buf, buf + i, len - i + 1);
		return ;
	}
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
	{
		*buf = '\0';
		return ;
	}
	buf[len] = '\0';
	parse_buffer(line, buf, fd);
}
