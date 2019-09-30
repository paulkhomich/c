//
//  main.c
//  e5x7
//
//  Created by Павел Хомич on 30/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <string.h>

#define STORESIZE 2048
#define LOGSIZE 128
#define LINESIZE 128

int readlines(char *, char *[], char *);
int _getline(char *, int);

int main(int argc, const char * argv[]) {
    char store[STORESIZE];
    char *log[128];
    char line[LINESIZE];
    
    readlines(store, log, line);
    
    printf("%s\n", log[2]);
    
    return 0;
}

int readlines(char *store, char *log[], char *line) {
    int len, nlens;
    char *p = store;
    
    nlens = 0;
    while ((len = _getline(line, LINESIZE)) > 0) {
        if (p + len < store + STORESIZE && nlens < LOGSIZE) {
            strcpy(p, line);
            log[nlens++] = p;
            p += len;
        } else {
            return -1;
        }
    }
    
    return nlens;
}

int _getline(char *line, int maxlen) {
    int c = 0, i;
    
    for (i = 0; i < maxlen - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    
    if (i > 0)
        line[i++] = '\0';
    
    return i;
}
