#include "rip.h"

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return (i);
}

int is_equal(char *str, int len)
{
    int balance = 0;
    int i = 0;
    while (i < len)
    {
        if (str[i] == '(')
            balance++;
        else if (str[i] == ')')
        {
            balance--;
            if (balance < 0)
                return (0);
        }
        i++;
    }
    return (balance == 0);
}

void find_min_removals(char *str, int *min_remove, int index, int current_remove)
{
    if (current_remove > *min_remove)
        return ;
    if (is_equal(str, ft_strlen(str)))
    {
        if (current_remove < *min_remove)
            *min_remove = current_remove;
        return ;
    }
    int i = index;
    while(str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            char saved = str[i];
            str[i] = ' ';
            find_min_removals(str, min_remove, i + 1, current_remove + 1);
            str[i] = saved;
        }
        i++;
    }
}

void solution(char *str, int min_remove, int index, int current_remove)
{
    if (current_remove > min_remove)
        return;
    if (is_equal(str, ft_strlen(str)) && current_remove == min_remove)
    {
        write(1, str, ft_strlen(str));
        write(1, "\n", 1);
        return ;
    }
    int i = index;
    while (str[i])
    {
        if (str[i] == '(' || str[i] == ')')
        {
            char saved = str[i];
            str[i] = ' ';
            solution(str, min_remove, i + 1, current_remove + 1);
            str[i] = saved;
        }
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2 || av[1][0] == '\0')
        return 1;
    int i = 0;
    while(av[1][i])
    {
        if(!(av[1][i] == '(' || av[1][i] == ')'))
            return 1;
        i++;
    }
    int min_remove = ft_strlen(av[1]);
    find_min_removals(av[1], &min_remove, 0, 0);
    solution(av[1], min_remove, 0, 0);
    return 0;
}
