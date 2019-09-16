//
//  main.c
//  e3x2
//
//  Created by Павел Хомич on 17/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

void escape(char[], char[]);

#define SIZE 100

int main(int argc, const char * argv[]) {
    char f[SIZE] = "Hello!\nMy name is Slim Shady!\0";
    char t[SIZE];
    
    escape(t, f);
    printf("%s\n%s\n", f, t);
    
    return 0;
}

void escape(char to[], char from[]) {
    int i, j;
    
    for (i = j = 0; from[i] != '\0'; i++) {
        switch (from[i]) {
            case '\n':
                to[j++] = '\\';
                to[j++] = 'n';
                break;
            case '\t':
                to[j++] = '\\';
                to[j++] = 't';
                break;
            default:
                to[j++] = from[i];
                break;
        }
    }
    from[j] = '\0';
}
