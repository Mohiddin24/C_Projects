#include <stdio.h>

/*
A function pointer is a pointer that stores the address of a function instead of a data variable.

It allows you to:

Pass functions as arguments

Return functions from other functions

Implement callbacks
*/

int add(int a, int b) {
    return a + b;
}

int main() {
    int (*fp)(int, int);

    fp = add;

    printf("%d\n", fp(5, 3));

    return 0;
}
