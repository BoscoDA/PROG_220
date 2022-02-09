#include <stdio.h>

void print_success(void) { printf("%s\n", "Correct"); }

void print_failure(void) {
  printf("%s\n", "Failure");
}

int isPalindrome(int x)
{
    if(x<0){
        return x;
    }
    int number = x;
    int reverse = 0;
    while(number > 0)
    {
        int remain = number % 10;
        reverse = (reverse * 10) + remain;
        number = number / 10;
    }
    return reverse;
}

int main(void)
{
    int testOne = isPalindrome(121);

    if(testOne == 121){
        print_success();
    }else{
        print_failure();
    }

    int testTwo = isPalindrome(-121);

    if(testTwo == -121){
        print_success();
    }else{
        print_failure();
    }
}