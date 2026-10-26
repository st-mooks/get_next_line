/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 get_next_line_bonus.h								:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: mbadarin <mbadarin@student.42amman.com>	+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2026/10/25 14:39:18 by mbadarin		   #+#	  #+#			  */
/*	 Updated: 2026/10/25 14:41:32 by mbadarin		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef MAX_FILES
#  define MAX_FILES 1024
# endif

//get_next_line.c
char	*get_next_line(int fd);
//get_next_line_utils.c
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*add_char(char *line, char c);
void	parse_buffer(char **line, char *buf, int fd);
#endif