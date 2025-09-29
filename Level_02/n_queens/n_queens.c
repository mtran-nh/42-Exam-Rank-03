#include <unistd.h>

#define N 10

void ft_putchar(char c)
{
    write (1, &c, 1);
}

void    ft_print(int *res)
{
    int i = 0;
    while (i < N)
    {
        ft_putchar(res[i] + '0');
        i++;
    }
    ft_putchar('\n');
}

int     ft_check(int *res, int n)
{
    int i = 0;
    while(i < n)
    {
        if (res[i] == res[n] || (res[i] - res[n]) == (i - n) || (res[i] - res[n]) == (n - i))
            return (0);
        i++;
    }
    return (1);
}

void ft_solve(int *res, int n, int *n_res)
{
    if (n == N) 
    {
        (*n_res)++;
        ft_print(res);
        return ;
    }
    int col = 0;
    while (col < N)
    {
        res[n] = col;
        if (ft_check(res, n))
            ft_solve(res, n + 1, n_res);
        col++;
    }
}

int n_queens(void)
{
    int res[N];
    int count = 0;
    ft_solve(res, 0, &count);
    return (count);
}

#include <stdio.h>
int main ()
{
    int total = n_queens();
    printf("Total solutions: %d\n", total);
    return 0;
}