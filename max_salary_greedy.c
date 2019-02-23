#include "max_salary.h"
#include <math.h>

int is_better(const void * best_so_far, const void * current){

  int b = *((int*)best_so_far);
  int c = *((int*)current);

  int best_count = 0;
  int current_count = 0;

  double b_c = 0;
  double c_b = 0;

  while(b > 0){
    b = b / 10;
    best_count++;
  }
  while(c > 0){
    c = c / 10;
    current_count++;
  }

  b_c = (*(int*)best_so_far) * (int)pow(10, current_count) + *(int*)current;
  c_b = (*(int*)current) * (int)pow(10, best_count) + *(int*)best_so_far;

  if(b_c > c_b){
    return -1;
  }else if(b_c < c_b){
    return 1;
  }else{
    return 0;
  }
}

double max_salary_greedy(int b[], int n){
  double sum = 0;
  int * greedy = malloc(sizeof(int)*(n+1));
  for(int i = 0; i < n; i++){
    greedy[i] = b[i];
  }
  greedy[n] = '\0';
  qsort(greedy, n, sizeof(int), is_better);
  int total_count = calculate_digit(greedy, n);
  print_array(greedy,n);

  for(int i = 0; i < n; i++){
    total_count = total_count - digit_arr[i];
    sum = sum + greedy[i] * (double)pow(10, total_count);
    // printf("total_count is %d\n", total_count);
    // printf("pow(10, total_count is %f", (double)pow(10, total_count));
    // printf("greedy[i] is %d\n", greedy[i]);
    // printf("sum is %f\n", sum);
  }
  free(greedy);
  return sum;
}
