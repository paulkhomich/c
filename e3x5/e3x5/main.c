//
//  main.c
//  e3x5
//
//  Created by Павел Хомич on 20/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 256

int itob(int n, char s[], int b);

int main(int argc, const char * argv[]) {
    char s[SIZE];
    
    itob(16, s, 16);
    printf("%s\n", s);
    
    return 0;
}

int itob(int n, char s[], int b) {
    int num, i;
    
    if (n < 0)
        n = -n;
    
    i = 0;
    do {
        s[i++] = (num = n % b) > 9 ? (num - 10) + 'a' : num + '0';
    } while ((n /= b) > 0);
    s[i] = '\0';
    
    reverse(s);

    return 0;
}
