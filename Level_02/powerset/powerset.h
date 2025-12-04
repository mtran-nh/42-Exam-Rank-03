#ifndef POWERSET_H
# define POWERSET_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_isdigit(char c);
void print_subset(int *subset, int size);
void backtrack(int *set, int set_size, int *subset, int sub_size, 
                int index, int sum, int target, int *found);
int valid_args(int ac, char **av);
int main (int ac, char **av);

#endif