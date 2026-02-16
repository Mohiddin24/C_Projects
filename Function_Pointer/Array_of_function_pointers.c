#include <stdio.h>
/*
An array of function pointers is an array that stores the addresses of multiple functions. It allows you to call different functions using the same array index.
Very common in:
Menu-driven programs
State machines
Drivers
Embedded systems

*/

int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    int (*operations[2])(int, int) = {add, sub};

    printf("%d\n", operations[0](10, 5)); // add
    printf("%d\n", operations[1](10, 5)); // sub
}
