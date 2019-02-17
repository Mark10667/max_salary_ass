CC = gcc
CFLAGS = -Wall -std=c99
LIBS += -lm

all:test

max_salary_naive.o: max_salary_naive.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_naive.c

max_salary_greedy.o: max_salary_greedy.c max_salary.h
	$(CC) $(CFLAGS) -c max_salary_greedy.c

test_performance.o: test_performance.c max_salary.h
	$(CC) $(CFLAGS) -c test_performance.c

test: max_salary_naive.o max_salary_greedy.o test_performance.o
	$(CC) $(CFLAGS) -o test max_salary_naive.o max_salary_greedy.o test_performance.o $(LIBS)

clean:
	rm max_salary_naive.o max_salary_greedy.o test_performance.o test
