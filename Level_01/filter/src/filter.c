
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
    if (ac != 2 || av[1][0] == 0)
        return (1);

    char temp[BUFFER_SIZE + 1];
    char *result = NULL;
    char *buffer;
    int total_read = 0;
    ssize_t bytes;

    while((bytes = read(0, temp, BUFFER_SIZE)) > 0)
    {
        buffer = realloc(result, total_read + bytes + 1);
        if (!buffer)
        {
            free(result);
            perror("realloc");
            return (1);
        }
        result = buffer;
        memmove(result + total_read, temp, bytes);
        total_read += bytes;
        result[total_read] = 0;
    }
    if (bytes < 0)
    {
        free(result);
        perror("read");
        return (1);
    }
    if (!result)
        return (0);
    ft_filter(result, av[1]);
    free(result);
    return (0);
}
