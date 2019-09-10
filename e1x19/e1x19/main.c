//
//  main.c
//  e1x19
//
//  Created by Павел Хомич on 10/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define MAXSIZE 800

int getlines(char line[], int max);
void reverse(char line[]);

int main(int argc, const char * argv[]) {
    char line[MAXSIZE];
    
    while (getlines(line, MAXSIZE) > 0) {
        reverse(line);
        printf("%s", line);
    }

    return 0;
}

int getlines(char buf[], int max) {
    int i, c;

    for (i = 0; (c = getchar()) != '\n' && c != EOF && i < max - 1; i++) {
        buf[i] = c;
    }
    if (c == '\n') {
        buf[i] = '\n';
        i++;
    }
    buf[i] = '\0';
    
    return i;
}

void reverse(char line[]) {
    int i, j, temp;
    
    i = 0;
    while (line[i] != '\0') {
        i++;
    }
    i--;
    
    if (line[i] == '\n') {
        i--;
    }
    
    j = 0;
    while (j < i) {
        temp = line[i];
        line[i] = line[j];
        line[j] = temp;
        j++;
        i--;
    }
}
