#include <stdio.h>
#include <stdlib.h>
#include <stdalign.h>
#include <complex.h>

struct newworld {
    char c;
    int a;
    short b;
};

int main(void) {
    alignas(sizeof(float[4])) float vec[4] = {
        [1] = 3.3,
        [3] = 2.2,
    };
    
    int arr[5];
    printf("%p\n", arr);
    printf("%p\n", arr+1);
    printf("%p\n", &arr);
    printf("%p\n", &arr+1);
    
    printf("%lu\t%lu\n", sizeof(struct newworld), _Alignof(struct newworld));
    
    return 0;
}
