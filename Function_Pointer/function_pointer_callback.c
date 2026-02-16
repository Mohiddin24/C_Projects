#include <stdio.h>

// A function pointer is a pointer that stores the address of a function instead of a data variable.
// callback is a function that is passed as an argument to another function and is executed after some event occurs or some condition is met.

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

void calculate(int (*operation)(int, int)) {
    printf("%d\n", operation(4, 5));
}

int main() {
    calculate(add);       // 9
    calculate(multiply);  // 20
}
