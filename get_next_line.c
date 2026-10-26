/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 12:15:53 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/26 14:47:45 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[BUFFER_SIZE + 1] = "";

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	parse_buffer(&line, buf, fd);
	return (line);
}
