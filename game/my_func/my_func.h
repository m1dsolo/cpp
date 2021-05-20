#include <stdio.h>      // perror
#include <stdlib.h>     // rand, exit
#include <time.h>
#include <stdbool.h>
#include <string.h>     // memset


void my_error(char *str);
int my_random(int min, int max);
void my_array_print(int a[], int size, int num);
bool is_in_range(int a, int min, int max);
int my_getn(int min, int max);