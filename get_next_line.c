/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:15:53 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/23 12:21:06 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buf;
	static ssize_t	len;
	static ssize_t	i = 0;

	if (!read_first_buffer(&buf, &len, fd))
		return (NULL);
	line = read_next_line(&buf, &len, &i, fd);
	return (line);
}
