#include "max_salary.h"
#include <math.h>

int * digit_arr = NULL;
int * a = NULL;
double naive_max = 0;

void stress_test(int N, int M){
  //int N; // how many elements in the array
  //int M; // what's the maximum digit for one elemen
  srand(time(NULL));   // Initialization, should only be called once.
  int* test_arr = malloc(sizeof(int) * (N+1));
  test_arr[N] = '\0';
  digit_arr = malloc(sizeof(int)*(N+1));
  a = malloc(sizeof(int)*(N+1));
  double greedy_max;
  while(1){
    for(int i = 0; i < N; i++){
          test_arr[i] = rand() % M + 1;
    }
    max_salary_naive(test_arr, N, N);
    //printf("max naive is %f", naive_max);
    greedy_max = max_salary_greedy(test_arr, N);
    //printf("greedy max is %f", greedy_max);
    if(naive_max == greedy_max){
      puts("OK");
    }else{
      puts("not equal!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!");
    }

    naive_max = 0;
  }
  free(test_arr);
  free(a);
  free(digit_arr);
}
int main(int argc, char **argv) {

    // int b[] = {19, 20, 17, 15, 1, };
    // int n = sizeof b/sizeof b[0];
    // digit_arr = malloc(sizeof(int)*(n+1));
    // a = malloc(sizeof(int)*(n+1));
    // max_salary_naive(b, n, n);
    // printf("Naive shows max salary is %d\n", naive_max);
    //
    // int greedy_max = max_salary_greedy(b, n);
    // printf("greedy_max shows max salary is %d\n", greedy_max);
    //
    // if(naive_max == greedy_max){
    //   puts("Wow! they are equal!!");
    // }
    // free(a);
    // free(digit_arr);

    if(argc == 1){
      puts("To run: ./test 1 <N> <M>  (N is the number of elements in the array, M is the max possible number for every element. \n or ./test 2 <type the array of integers one by one with a blank space between the numbers>\n");
      return 0;
    }
    int mode = atoi(argv[1]);
    if(mode != 1 && mode != 2){
      puts("To run: ./test 1 <N> <M>  (N is the number of elements in the array, M is the max possible number for every element. \n or ./test 2 <type the array of integers one by one with a blank space between the numbers>\n");
      return 0;
    }

    if(mode == 1){
      int N = atoi(argv[2]);
      int M = atoi(argv[3]);

      if(argc > 4){
        puts("To run: ./test 1 <N> <M>  (N is the number of elements in the array, M is the max possible number for every element. \n");
        return 0;
      }

      if(N < 0 || M < 0){
        puts("N and M are positive, no one wants a negative salary :)\n");
        return 0;
      }

      int b = M;
      int digit = 0;

      while(b > 0){
        b = b / 10;
        digit++;
      }

      if(N*digit > 12 || digit > 9){
        puts("This number is too big, please choose a smaller N and M next time :)\n Please notice that every element of the array should not exceed 9 digits\n");
        return 0;
      }

      stress_test(N, M);
    }

    if(mode == 2){
      int b;
      //double testnum;
      int total_digit = 0;
      int count = argc;
      digit_arr = malloc(sizeof(int)*(count+1));
      a = malloc(sizeof(int)*(count+1));
      int* test = malloc(sizeof(int)*(count-1));
      test[count-1] = '\0';
      for(int i = 0 ; i < count-2; i++){
        if(atof(argv[i+2]) > 999999999){
          puts("This number is too big, please choose a smaller int next time :)\n Please notice that every element of the array should not exceed 9 digits\n");
          return 0;
        }
        test[i] = atoi(argv[i+2]);
        b = test[i];
        printf("b is %d", b);
        while(b != 0){
          b = b / 10;
          total_digit++;
        }
      }
      if(total_digit > 12 ){
        puts("This number is too big, please choose a smaller int next time :)\n Please notice that every element of the array should not exceed 9 digits");
        free(a);
        free(digit_arr);
        free(test);
        return 0;
      }
      print_array(test, count - 2);
      max_salary_naive(test, count - 2, count - 2);
      printf("Naive shows max salary is %f\n", naive_max);

      double greedy_max = max_salary_greedy(test, count - 2);
      printf("greedy_max shows max salary is %f\n", greedy_max);

      if(naive_max == greedy_max){
        puts("Wow! they are equal!!");
      }
      free(a);
      free(digit_arr);
      free(test);
      return 0;
    }

    return 0;
}
