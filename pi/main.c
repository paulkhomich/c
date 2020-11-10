#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <tgmath.h>

double p(unsigned int n);

int main(void) {
    for (int i = 0; i < 10; ++i) {
        printf("%-6d%20.12f\n", i, p(i));
    }
    
    return EXIT_SUCCESS;
}

double p(unsigned int n) {
    double p = 0.0;
    double eps = 1.0 / pow(10, n+1);
    double add = eps;
    for (int i = 0; add >= eps; ++i) {
        add = (1.0 / (i*2.0 + 1.0));
        p += (add * (1.0 - 2.0*(i % 2)));
    }
    
    return (p * 4.0);
};

