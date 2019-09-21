//
//  main.c
//  e4x4
//
//  Created by Павел Хомич on 22/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 128

int push(double);
double pop(void);
double show(void);
void repeat(void);
void cross(void);
void sclear(void);

int si = 0;
double stack[SIZE];

int main(int argc, const char * argv[]) {

    return 0;
}

int push(double el) {
    if (si < SIZE) {
        stack[si] = el;
        return si++;
    }
    
    printf("Stack overflow, cannot add element %g\n", el);

    return -1;
}

double pop(void) {
    if (si > 0)
        return stack[--si];
    
    printf("Stack is empty\n");
    
    return 0.0;
}

double show(void) {
    if (si > 0)
        return stack[si - 1];
    
    printf("Stack is empty\n");
    
    return 0.0;
}

void repeat(void) {
    if (si > 0)
        push(show());
    else
        printf("Stack is empty\n");
}

void cross(void) {
    double c1, c2;

    if (si > 1) {
        c1 = pop();
        c2 = pop();
        push(c1);
        push(c2);
    } else
        printf("Stack isn't too large\n");
}

void sclear(void) {
    while (si > 0) {
        pop();
    }
}
