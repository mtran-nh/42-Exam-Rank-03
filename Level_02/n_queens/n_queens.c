#include "n_queens.h"

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_isdigit(char c)
{
    return (c >= '0' && c <='9');
}

int ft_atoi(char *s)
{
    int value = 0;
    while(*s && ft_isdigit(*s))
    {
        value = value * 10 + *s - '0';
        s++;
    }
    return (value);
}

void print_res(int *res, int n)
{
    int i = 0;
    while (i < n)
    {
        ft_putchar(res[i] + '0');
        if (i < n - 1)
            ft_putchar(' ');
        i++;
    }
    ft_putchar('\n');
}

int ft_check(int *res, int step)
{
    int i = 0;
    while (i < step)
    {
        if (res[i] == res[step] || ((res[i] - res[step]) == (i - step)) || ((res[i] - res[step]) == (step - i)))
            return 0;
        i++;
    }
    return 1;
}

void ft_solve(int *res, int step, int n)
{
    if (step == n)
    {
        print_res(res, n);
        return;
    }
    int col = 0;
    while(col < n)
    {
        res[step] = col;
        if (ft_check(res, step))
            ft_solve(res, step + 1, n);
        col++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;
    int i = 0;
    while (av[1][i])
    {
        if (!ft_isdigit(av[1][i]))
            return 1;
        i++;
    }
    int n = ft_atoi(av[1]);
    if (n <= 0)
        return 0;
    int res[n];
    ft_solve(res, 0, n);
    return 0;
}