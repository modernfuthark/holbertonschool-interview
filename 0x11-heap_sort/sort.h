#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/* Prototypes*/
void heap_sort(int *array, size_t size);
void heapify(int *arr, size_t size, int idx, size_t truesize);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
