//
//  main.c
//  e2x10
//
//  Created by Павел Хомич on 16/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

void lower(char[]);

int main(int argc, const char * argv[]) {
    char s[] = "HeLLo I LOve You\0";
    
    lower(s);
    printf("%s\n", s);
    
    return 0;
}

void lower(char s[]) {
    int i;

    for (i = 0; s[i] != '\0'; i++) {
        s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] - 'A' + 'a' : s[i];
    }
}
