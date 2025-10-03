#ifndef PERMUTATION_H
# define PERMUTATION_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str);
int ft_isalpha(int c);
int ft_strchr(char *str, char c);
void permutation(char *result, char *source, int step);
void ft_swap(char *a, char *b);
char *order_string(char *s);
int main (int ac, char **av);

#endif