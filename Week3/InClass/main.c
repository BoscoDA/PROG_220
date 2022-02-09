#include <stdio.h>
#include<stdlib.h>

// Whenever you have a constant variable do this
#define MAXBUFFER 1024
#define LEN(array) (sizeof(array) / sizeof(*(array)))

typedef struct {
    void *arry;
    size_t len;
} Array;

void *init_array(size_t len)
{
    Array *a = (Array *)malloc(sizeof(Array));
    a->len = len;
    a->arry = malloc(len);
    return a;
}

void destroy_array(Array *array)
{
    if(array != NULL)
    {
        free(array->arry);
        free(array);
    }
}

void foo2(Array *a)
{
    int *localCopy = (int *)a->arry;
    for(size_t i = 0; i < a->len; i++)
    {
        printf("%d\n", localCopy[i]);
    }
}

int main(void)
{
    // Trick to get the size of an array
    //size_t x_len = sizeof(x) / sizeof(int);

    //int x[MAXBUFFER];

    // Allocating memory to the heap
    //Array *a = (Array *)malloc(sizeof(Array));
    //foo2(a);

    // Clean up allocated memory
    //free(a);
    //a = NULL;
    
    Array*a = init_array((MAXBUFFER * sizeof(int)));
    foo2(a);
    destroy_array(a);
    foo2(a);
}