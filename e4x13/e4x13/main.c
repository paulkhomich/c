//
//  main.c
//  e4x13
//
//  Created by Павел Хомич on 26/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 128

void reverse(char*);

int main(int argc, const char * argv[]) {
    char s[SIZE] = "it's amazing, so amazing";
    
    printf("%s\n", s);
    reverse(s);
    printf("%s\n", s);

    return 0;
}

void reverse(char s[]) {
    static int i, j;
    char c = s[j];
    
    if (s[j++ + 1] != '\0')
        reverse(s);
    
    s[i++] = c;
    s[i] = '\0';
}
