/*
 * c struct
 *
 
$gcc ex251-struct.c

$./a.out 
expected offset of a: 0
real offsetof a: 0
expected offset of b: 1
offsetof b: 4
expected offset of c: 5
offsetof c: 8
expected offset of d: 13
offsetof d: 16

Expected struct size: 23
Real struct size: 32

$clang -Wpadded ex251-struct.c
$clang -Wpadded ex251-struct.c
ex251-struct.c:29:9: warning: padding struct 'struct s' with 3 bytes to align 'b' [-Wpadded]
    int b;
        ^
ex251-struct.c:27:8: warning: padding size of 'struct s' with 6 bytes to alignment boundary [-Wpadded]
struct s {
       ^
2 warnings generated 

 *
 * use __attribute__((packed));
 *
 * but packed structures are a non-standard feature
 * and it makes your code run slower.
 *
 
$gcc ex251-struct.c 
$./a.out 
expected offset of a: 0
real offsetof a: 0
expected offset of b: 1
offsetof b: 1
expected offset of c: 5
offsetof c: 5
expected offset of d: 13
offsetof d: 13

Expected struct size: 23
Real struct size: 23

 */

#include <stdio.h>
#include <stddef.h>
 
struct s {
    char a;
    int b;
    double c;
    char d[10];
} __attribute__((packed));
 
int main(void) {
    // add the size of each member of struct s
    size_t expected_size = sizeof(char) + sizeof(int) +
                           sizeof(double) + sizeof(char[10]);
 
    printf("expected offset of a: 0\n");
    printf("real offsetof a: %ld\n", offsetof(struct s, a));
 
    printf("expected offset of b: %ld\n", sizeof(char));
    printf("offsetof b: %ld\n", offsetof(struct s, b));
 
    printf("expected offset of c: %ld\n", sizeof(char) + sizeof(int));
    printf("offsetof c: %ld\n", offsetof(struct s, c));
 
    printf("expected offset of d: %ld\n", sizeof(char) + sizeof(int) + sizeof(double));
    printf("offsetof d: %ld\n", offsetof(struct s, d));
 
    printf("\n");
 
    printf("Expected struct size: %ld\n", expected_size);
    printf("Real struct size: %ld\n", sizeof(struct s));
}

