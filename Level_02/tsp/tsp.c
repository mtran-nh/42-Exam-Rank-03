#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct{
    float x;
    float y;
}   city;

float distance(city a, city b)
{
    float dx = a.x - b.x;
    float dy = a.y - b.y;
    return (sqrt(dx * dx + dy * dy));
}

void ft_swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void find_shortest_path(city *cities, int *path, int n, int pos, float current_dist, float *min_dist)
{
    if (current_dist >= *min_dist)
        return ;
    if (pos == n)
    {
        float total = current_dist + distance(cities[path[n - 1]], cities[path[0]]);
        if (total < *min_dist)
            *min_dist = total;
        return;
    }

    int i = 0;
    while (i < n)
    {
        ft_swap(&path[pos], &path[i]);
        float next_dist = current_dist;
        if (pos > 0)
            next_dist += distance(cities[path[pos - 1]], cities[path[pos]]);
        find_shortest_path(cities, path, n, pos + 1, next_dist, min_dist);
        ft_swap(&path[pos], &path[i]);
        i++;
    }
}

int main(void)
{
    city cities[12];
    int n = 0;
    while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
        n++;
    if (n < 2)
    {
        printf("0.00\n");
        return 0;
    }

    int path[12];
    for (int i = 0; i < n; i++)
        path[i] = i;

    float min_distance = FLT_MAX;

    find_shortest_path(cities, path, n, 1, 0.0f, &min_distance);

    printf("%.2f\n", min_distance);
    return 0;
}

