#include <stdio.h>

/*Structure padding is a technique used by C compilers to insert unused bytes (padding) between structure members or at the end of a structure to ensure proper data alignment in memory. 
This optimization improves memory access performance on most processor architectures. 

Why is Structure Padding Necessary?
Performance Optimization: CPUs access memory in fixed-size chunks (e.g., 4 or 8 bytes). 
Data that is aligned to these boundaries can be fetched in a single CPU cycle. 
Unaligned access might require multiple cycles and bit shifting, which is slower.

Array Alignment: Padding at the end of a structure ensures that when an array of these structures is created, 
each element in the array is properly aligned. 

*/


struct A {
    char c;
    int i;
};

int main() {
    printf("%zu\n", sizeof(struct A));
}

struct B {
    char a;
    int b;
    char c;
};


// Structure size must be multiple of largest alignment (4 here).

// Expectation:
// 1 (char) + 4 (int) = 5 bytes

// Actual Output:
// 8 bytes (1 byte for char + 3 bytes of padding + 4 bytes for int)

// How to Reduce Padding

struct Better {
    int b;
    char a;
    char c;
};

// 4 (int) + 1 + 1 + 2 padding = 8 bytes which is better than 12

/* Rule of Thumb
* Arrange members from largest to smallest
* Avoid unnecessary memory waste
* Important in embedded systems
*/

// How to Remove Padding

#pragma pack(1)
struct A {
    char c;
    int i;
};

// OR

struct __attribute__((packed)) A {
    char c;
    int i;
};

// Now size = 5 bytes.