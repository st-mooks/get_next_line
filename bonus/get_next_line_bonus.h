#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
//Uncomment for testing
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

//get_next_line.c
char	*get_next_line(int fd);
//get_next_line_utils.c
size_t	ft_strlen(char *str);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*add_char(char *line, char c);
ssize_t read_next_buffer(int fd, char *buf);
char	*read_next_line(char *buf, int fd);
#endif