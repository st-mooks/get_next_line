/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbadarin <mbadarin@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 14:41:50 by mbadarin          #+#    #+#             */
/*   Updated: 2026/10/26 14:47:25 by mbadarin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	char			*line;
	static char		buf[MAX_FILES][BUFFER_SIZE + 1] = {""};

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	line = NULL;
	parse_buffer(&line, buf[fd], fd);
	return (line);
}
