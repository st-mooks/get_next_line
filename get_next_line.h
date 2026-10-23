/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line.h									:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/23 12:16:22 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/10/23 12:22:12 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
//Uncomment for testing
//# include <stdio.h>
//# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//get_next_line.c
char	*get_next_line(int fd);
//get_next_line_utils.c
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*add_char(char *line, char c);
int		read_first_buffer(char **buf, ssize_t *len, int fd);
char	*read_next_line(char **buf, ssize_t *len, ssize_t *i, int fd);
#endif
