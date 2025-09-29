#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int ft_isalpha(int c)
{
    return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int ft_strchr(char *str, char c)
{
    int i = 0;
    while (str[i])
    {
        if (c == str[i])
            return (1);
        i++;
    }
    return (0);
}

void permutation(char *result, char *source, int step)
{
    int source_len = ft_strlen(source);

    if (step == source_len)
    {
        write(1, result, source_len);
        write(1, "\n", 1);
        return ;
    }
    int i = 0;
    while(i < source_len)
    {
        if(!ft_strchr(result, source[i]))
        {
            result[step] = source[i];
            permutation(result, source, step + 1);
            result[step] = 0;
        }
        i++;
    }
}

void ft_swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char *order_string(char *s)
{
    int i = 0;
    while(s[i])
    {
        int j = i + 1;
        while (s[j])
        {
            if (s[i] > s[j])
                ft_swap(&s[i], &s[j]);
            j++;
        }
        i++;
    }
    return (s);
}

int main (int ac, char **av)
{
    if (ac != 2)
        return (1);
    if (ft_strlen(av[1]) == 0 || (av[1][0] == ' ' && !av[1][1]))
        return 0;
    int i = 0;
    while (av[1][i])
    {
        if (!ft_isalpha(av[1][i]))
            return 0;
        i++;
    }
    int len = ft_strlen(av[1]);
    char *result = calloc(len + 1, 1);
    if (!result)
        return (1);
    char *source = order_string(av[1]);
    permutation(result, source, 0);
    free(result);
    return (0);
}