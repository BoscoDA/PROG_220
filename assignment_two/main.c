#include <stdio.h>

void print_success(void) { printf("%s\n", "Correct"); }

void print_failure(const int expected, const int actual) Z{
    printf("Failure: expected %d, got %d\n", expected, actual);
}

typedef struct {
    int a, b, c;
} PythagResult;

PythagResult *PythagoreanTriples(const int n) {return NULL;}

int main(void){}
