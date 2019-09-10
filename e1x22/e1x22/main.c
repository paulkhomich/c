//
//  main.c
//  e1x22
//
//  Created by Павел Хомич on 10/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define LINESIZE 16

char line[LINESIZE];

int srchempt(int pos);
int formline(int pos);
void printl(int pos);

int main(int argc, const char * argv[]) {
    int pos, emptpos, c;
    
    pos = 0;
    while ((c = getchar()) != EOF) {
        line[pos] = c;
        
        if (c == '\n') {
            printl(pos);
            pos = 0;
        } else if (++pos >= LINESIZE) {
            emptpos = srchempt(pos);
            printl(emptpos);
            pos = formline(emptpos);
        }
    }
    
    if (pos > 0)
        printl(pos);
    
    return 0;
}

int srchempt(int pos) {
    while (line[pos] != ' ')
        pos--;
    
    if (pos > 0)
        return pos + 1;
    else
        return LINESIZE;
}

void printl(int pos) {
    int i;

    for (i = 0; i < pos; i++)
        putchar(line[i]);
    if (pos > 0)
        putchar('\n');
}

int formline(int pos) {
    int i, j;
    
    j = 0;
    for (i = pos; i < LINESIZE; i++) {
        line[j] = line[i];
        j++;
    }
    
    return j;
}
