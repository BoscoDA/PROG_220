#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrom(int n) {
    int current = n;
    int r = 0;
    while(n > 0) {
        int tmp = n % 10;
        r = r * 10 + tmp;
        n = n / 10;
    }
    return current == r;
}

int main(){
    // Three ways to allocate memory in C
    int * int_array = (int *)malloc(1024 * sizeof(int));
    int z = (*int_array + 1);
    int y = int_array[1];

    //calloc will clear all the memory before returning
    //int *ptr = (int *)calloc(1024, sizeof(int));

    // realloc resizes a block that is passed in
    //realloc(ptr, 10240 * sizeof(int));

    // Print out the numbers for each character in the string array
    char *str = "hello world\0";

    for(size_t i = 0; i < 10; i++){
        printf("%d\n", str[i]);
    }
}