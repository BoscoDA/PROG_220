#include <stdio.h>

void print_success(void) { printf("%s\n", "Correct"); }

void print_failure(const int expected, const int actual) {
  printf("Failure: expected %d, got %d\n", expected, actual);
}

int fibonacci(const int n) 
{ 
  int output = 0, numone = 0, numtwo = 1;
  if(n==0){
    output = numone;
  }
  else if(n==1){
    output = numtwo;
  }
  else{
    for(int i = 0; i < n; i++){
      numone = numtwo;
      numtwo = output;
      output = numone + numtwo;
    }
  }
  return output; 
  }

int main(void) {
  // test cases
  int fiveResult = fibonacci(5);

  if (fiveResult == 5) {
    print_success();
  } else {
    print_failure(5, fiveResult);
  }

  int nineResult = fibonacci(9);

  if (nineResult == 34) {
    print_success();
  } else {
    print_failure(34, nineResult);
  }

  int twentyResult = fibonacci(20);

  if(twentyResult == 6765){
    print_success();
  }else{
    print_failure(6765, twentyResult);
  }

  int fortyResult = fibonacci(40);

  if(fortyResult == 102334155){
    print_success();
  }else{
    print_failure(102334155, fortyResult);
  }

  int twoResult = fibonacci(2);

  if(twoResult == 1){
    print_success();
  }else{
    print_failure(1, twoResult);
  }

  int oneResult = fibonacci(1);

  if(oneResult == 1){
    print_success();
  }else{
    print_failure(1, oneResult);
  }

  int zeroResult = fibonacci(0);

  if(zeroResult == 0){
    print_success();
  }else{
    print_failure(0, zeroResult);
  }

  int threeResult = fibonacci(3);

  if(threeResult == 2){
    print_success();
  }else{
    print_failure(2, threeResult);
  }
}
