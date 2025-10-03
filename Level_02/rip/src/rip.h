#ifndef RIP_H
# define RIP_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str);
int is_equal(char *str, int len);
void find_min_removals(char *str, int *min_remove, int index, int current_remove);
void solution(char *str, int min_remove, int index, int current_remove);
int main(int ac, char **av);

#endif