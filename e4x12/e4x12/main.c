//
//  main.c
//  e4x12
//
//  Created by Павел Хомич on 26/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 128

void itoa(int, char[]);

int main(int argc, const char * argv[]) {
    int n = 1812;
    char s[SIZE];
    
    itoa(n, s);
    printf("%s\n", s);
    
    return 0;
}

void itoa(int n, char s[]) {
    static int i;
    
    if (n / 10)
        itoa(n / 10, s);

    s[i++] = (n % 10) + '0';
    s[i] = '\0';
}
