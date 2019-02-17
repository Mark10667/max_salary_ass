#ifndef MAX_SALARY_H
#define MAX_SALARY_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

#define SWAP(a,b) {int temp; temp=a; a=b; b=temp;}

void print_array(int *arr, int size);
int calculate_digit(int a[], int size);
void max_salary_naive(int a[], int size, int n) ;

int is_better(const void * best_so_far, const void * current);
int max_salary_greedy(int b[], int n);

extern int * digit_arr;
extern int * a;
extern int naive_max;

#endif
