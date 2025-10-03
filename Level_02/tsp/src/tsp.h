#ifndef TSP_H
# define TSP_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct{
    float x;
    float y;
}   city;

float distance(city a, city b);
void ft_swap(int *a, int *b);
void find_shortest_path(city *cities, int *path, int n, int pos, float current_dist, float *min_dist);
int main(void);

#endif