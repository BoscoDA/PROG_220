#include <stdio.h>
#include <stdlib.h>
int main()
{
    int * int_array = (int *)malloc(sizeof(int) * 10);

    for(int i = 0; i < 1024; i+=4)
    {
        printf("%d\n", int_array[i]);
    }

    //void * ptr = calloc91, sizeof((int));
    //void * ptr2 = realloc(ptr, sizeof(int) * 2);
}