#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <tgmath.h>

double F(double);
double f(double F(double), double);

int main(void) {
    for (size_t i = 0; i < 10; i++) {
        printf("F(%1$zx rad) = %2$+6.4f    F'(%1$zx rad) = %3$+6.4f\n", i, sin(i), f(sin, i));
    }
    
    return EXIT_SUCCESS;
}

double F(double x) {
    return x * x;
}

double f(double F(double), double x) {
    double static dx = 0.000001;
    
    return (F(x + dx) - F(x)) / dx;
}

