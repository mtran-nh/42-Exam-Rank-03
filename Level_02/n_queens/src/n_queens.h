#ifndef N_QUEENS_H
# define N_QUEENS_H

#include <unistd.h>
#include <stdio.h>
void ft_putchar(char c);
int ft_isdigit(char c);
int ft_atoi(char *s);
void print_res(int *res, int n);
int ft_check(int *res, int step);
void ft_solve(int *res, int step, int n);
int main(int ac, char **av);
#endif