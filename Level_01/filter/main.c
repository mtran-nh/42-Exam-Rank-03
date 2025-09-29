
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void    ft_filter(char *buffer, char *target)
{
    int i = 0;
    int target_len =  strlen(target);

    while(buffer[i])
    {
        int j = 0;
        while (target[j] && buffer[i + j] == target[j])
            j++;
        if (j == target_len)
        {
            int k = 0;
            while (k < target_len)
            {
                write(1, "*", 1);
                k++;
            }
            i += target_len;
        }
        else
        {
            write(1, &buffer[i], 1);
            i++;
        }
    }
}

int main (int ac, char **av)
{
    char *buffer;
    char *target;

    buffer = av[1];
    target = "abc";

    ft_filter(buffer, target);
}