#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_isdigit(char c)
{
    return (c >= '0' && c <= '9');
}

void print_subset(int *subset, int size)
{
    if (0 == size)
    {
        printf("\n");
        return ;
    }
    int i = -1;
    while (++i < size)
    {
        // if (i == size - 1)
        //     printf("%d", subset[i]);
        // else
            printf("%d", subset[i]);
    }
    printf("\n");
}

void backtrack(int *set, int set_size, int *subset, int sub_size, 
                int index, int sum, int target, int *found)
{
    if (index == set_size)
    {
        if (sum == target)
        {
            print_subset(subset, sub_size);
            *found = 1;
        }
        return ;
    }
    backtrack(set, set_size, subset, sub_size, index + 1, sum, target, found);
    subset[sub_size] = set[index];
    backtrack(set, set_size, subset, sub_size + 1, index + 1, sum + set[index], target, found);
}

int valid_args(int ac, char **av)
{
    int i = 1;
    while (i < ac)
    {
        int j = 0;
        if (av[i][j] == '+' || av[i][j] == '-')
            j++;
        while (av[i][j])
        {
            if (!ft_isdigit(av[i][j]))
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int main (int ac, char **av)
{
    if (ac == 1 || (ac >= 2 && av[1][0] == '0' && av[1][1] == '\0'))
    {
        printf("\n");
        return 0;
    }
    if (!valid_args(ac, av))
        return (1);
    int target = atoi(av[1]);
    int set_size = ac - 2;
    if (set_size <= 0)
        return (1);

    int *set = malloc(set_size * sizeof(int));
    if (!set)
        return (1);
    int *subset = malloc(set_size * sizeof(int));
    if (!subset)
    {
        free(set);
        return 1;
    }
    int i = 0;
    int j = 2;
    while (j < ac)
    {
        set[i++] = atoi(av[j++]);
    }
    int found = 0;
    backtrack(set, set_size, subset, 0, 0, 0, target, &found);
    if (!found)
        printf("\n");
    free(subset);
    free(set);
    return 0;
}
