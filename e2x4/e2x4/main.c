//
//  main.c
//  e2x4
//
//  Created by Павел Хомич on 14/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

void squeeze(char[], char[]);

int main(int argc, const char * argv[]) {
    char s1[] = "riders on the storm\0";
    char s2[] = "trigger\0";
    
    squeeze(s1, s2);
    
    return 0;
}

void squeeze(char s1[], char s2[]) {
    int k, i, j;
    
    for (k = 0; s2[k] != '\0'; k++) {
        for (i = j = 0; s1[i] != '\0'; i++) {
            if (s1[i] != s2[k])
                s1[j++] = s1[i];
        }
        
        s1[j] = '\0';
    }
    
    printf("%s\n", s1);
}
