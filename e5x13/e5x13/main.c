//
//  main.c
//  e5x13
//
//  Created by Павел Хомич on 05/10/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULTN 10
#define MAXN 16
#define MAXLINE 128

int _getline(char *, int);

int main(int argc, const char * argv[]) {
    int n, i, nlines;
    char *buffer;
    char line[MAXLINE];

    n = DEFAULTN;
    if (argc > 2) {
        printf("use: tail [-n]\n");

        return 1;
    } else if (argc == 2 && *(++argv)[0] == '-') {
        n = atoi(++(*argv));
    }
    
    if (n < 1)
        n = DEFAULTN;
    if (n > MAXN)
        n = MAXN;
    
    // Creating the buffer for lines
    buffer = (char *) malloc(n * MAXLINE);
    if (buffer == NULL)
        return 1;
    
    // Creating array of pointers to strings
    char *list[n];
    
    for (i = 0; i < n; i++)
        list[i] = buffer + i * MAXLINE;
    
    // Reading input
    nlines = 0;
    while (_getline(line, MAXLINE)) {
        strcpy(list[nlines++ % n], line);
    }
    
    // Writing n lines
    if (n > nlines) {
        n = nlines;
        nlines = 0;
    }

    for (i = 0; i < n; i++) {
        printf("%s\n", list[nlines++ % n]);
    }
        
    
    return 0;
}

int _getline(char *s, int max) {
    int i, c;
    
    i = 0;
    while ((c = getchar()) != '\n' && c != EOF && i < max - 1) {
        s[i++] = c;
    }
    if (i)
        s[i++] = '\0';
    
    return i;
}
