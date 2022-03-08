#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    int a, b, c;
} PythagResult;

void print_success(void) { printf("%s\n", "Correct"); }

void print_failure(const PythagResult expected, const PythagResult actual) {
    printf("Failure: expected {%d,%d,%d} got {%d,%d,%d}\n", expected.a, expected.b, expected.c, actual.a, actual.b, actual.c);
}

void test_case(PythagResult *test, PythagResult *result, int size){
    for(size_t k = 0; k < size; k++)
    {
        if(result[k].a != test[k].a || result[k].b != test[k].b || result[k].c != test[k].c){
            print_failure(test[k], result[k]);
        }
        else{
            print_success();
        }
    }
    free(result);
    result = NULL;
}

PythagResult *PythagoreanTriples(const int n) {
    PythagResult r;
    PythagResult *pythag_array = (PythagResult *)malloc((sizeof(PythagResult)*0));
    int i = 0;
    for(int c = 5; c<=n; c++){
        for(int b = 4; b<c; b++){
            float a = sqrt(c*c-b*b);
            if(a==(int)a & a >0 & b>a){
                r.a = a;
                r.b = b;
                r.c = c;
                pythag_array = realloc(pythag_array, (i+1) * sizeof(PythagResult));
                pythag_array[i] = r;
                i++;
            }
        }
    }
    return pythag_array;
    }

int main(void){
    PythagResult *test1_result = PythagoreanTriples(30);
    PythagResult test1[11] = {{3,4,5},{6,8,10},{5,12,13},{9,12,15},{8,15,17},{12,16,20},{15,20,25},{7,24,25},{10,24,26},{20,21,29},{18,24,30}};
    printf("Test Case #1\n");
    test_case(test1, test1_result, (sizeof(test1)/sizeof(test1[0])));

    PythagResult *test2_result = PythagoreanTriples(5);
    PythagResult test2[1] = {{3,4,5}};
    printf("\n\nTest Case #2\n");
    test_case(test2, test2_result, (sizeof(test2)/sizeof(test2[0])));

    PythagResult *test3_result = PythagoreanTriples(25);
    PythagResult test3[8] = {{3,4,5},{6,8,10},{5,12,13},{9,12,15},{8,15,17},{12,16,20},{15,20,25},{7,24,25}};
    printf("\n\nTest Case #3\n");
    test_case(test3, test2_result, (sizeof(test3)/sizeof(test3[0])));
}
