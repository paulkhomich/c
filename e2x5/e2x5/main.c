//
//  main.c
//  e2x5
//
//  Created by Павел Хомич on 14/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

int any(char[], char[]);

int main(int argc, const char * argv[]) {
    char s1[] = "riders on the storm\0";
    char s2[] = "example\0";
    
    printf("%d\n", any(s1, s2));
    
    return 0;
}

int any(char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; i++) {
        for (j = 0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    
    return -1;
}
