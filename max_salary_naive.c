#include "max_salary.h"

int * best_arr;

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

int calculate_digit(int a[], int n){
  int count = 0;
  int element = 0;
  int total_count = 0; // the total digits
  digit_arr = malloc(sizeof(int)*(n+1));
  for(int i = 0; i < n; i++){
    element = a[i];
    while(element > 0){
      element = element / 10;
      count++;
      total_count++;
    }
    digit_arr[i] = count;
    count = 0;
  }
  digit_arr[n] = '\0';
  return total_count;
}

// Generating permutation using Heap Algorithm
void max_salary_naive(int b[], int size, int n){

    int amount = 0;
    // if size becomes 1 then do something with the obtained permutation
    a = malloc(sizeof(int)*(n+1));
    for(int i = 0; i < n; i++){
      a[i] = b[i];
    }
    a[n] = '\0';
    int total_count = calculate_digit(a, n);
    if (size == 1){
        //TO DO - instead of printing, insert your code for evaluating the next candidate array
        for(int i = 0; i < n; i++){
          total_count = total_count - digit_arr[i];
          amount = amount + a[i] * pow(10, total_count);
        }
        if(amount > naive_max){
          naive_max = amount;
        }
        return;
    }

    for (int i=0; i<size; i++){
        max_salary_naive(a,size-1,n);

        // if size is odd, swap first and last element
        if (size%2==1){
            SWAP(a[0], a[size-1]);
		    }
        // If size is even, swap ith and last element
        else{
            SWAP(a[i], a[size-1]);
		    }
    }
}
// Code to test permutations
// int main(){
//   int b[] = {19, 20, 1, 15, 7, };
//   int n = sizeof b/sizeof b[0];
//   max_salary_naive(b, n, n);
//   printf("Naive shows max salary is %d\n", naive_max);
//   return 0;
// }
