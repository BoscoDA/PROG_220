#include <stdio.h>

// no overloading

// in main module

/*
void foo(void);
void bar(int);
int baz(int);
*/

//void *get(void * id) {}

void by_value(int n)
{
    n++;
}

void by_reference(int *n){(*n)++;}



int main(void){
    //print hello world
    //printf("%s", "Hello World\n");

/*
    if(1 == 1)
    {
        printf("%s", "The World Makes sense");
    } else if (1 == 2){
        printf("%s", "Please Stop");
    } else {
        printf("%s", "What on earth have you done");
    }

    for (int i = 0; i < 10; i++)
    {
        printf("%s", "Ping");
    }
    
    while(1==1)
    {
        printf("%s", "runs forever");
    }

    do
    {
        printf("%s", "runs once");
    } while ( 1== 2);
    */

   //int n =100;
   
   //printf("%u\n", &n);
/*
   by_value(n);
   printf("%d\n", n);
   by_reference(&n);
   printf("%d\n", n);
*/
   for (int i; i < 100; i++)
   {
       if (i%15 == 0)
       {
           printf("%s\n", "fizz buzz");
       } 

       else if (i%3 == 0){
           printf("%s\n", "fizz");
       } 

       else if(i%5 == 0){
           printf("%s\n", "buzz");
       } 

       else {
           printf("%d\n", i);
       }
   }
   
}