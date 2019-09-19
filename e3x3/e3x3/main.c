//
//  main.c
//  e3x3
//
//  Created by Павел Хомич on 19/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 256

int expand(char[], char[]);
int type(char);

int main(int argc, const char * argv[]) {
    char s1[SIZE] = "Jedi power: a-k\0";
    char s2[SIZE];
    
    expand(s1, s2);
    printf("%s\n%s\n", s1, s2);
    
    return 0;
}

int expand(char s1[], char s2[]) {
    int c, i, j;
    
    for (i = j = 0; (c = s1[i++]) != '\0';)
        if (s1[i] == '-' && s1[i+1] > c) {
            i++;
            while (c != s1[i])
                s2[j++] = c++;
        } else
            s2[j++] = c;
    
    return 0;
}
