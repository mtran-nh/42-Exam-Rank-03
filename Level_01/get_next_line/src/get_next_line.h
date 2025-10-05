#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif
int ft_strlen(char *s);
char *ft_strdup(char *s);
int ft_strchr(char *s, char c);
char *ft_strjoin(char *s1, char *s2);

char *read_til_nl(char *remain, int fd);
char *extract_line(char *buffer);
void new_remain(char *remain, char *buffer);
char *get_next_line(int fd);

#endif
