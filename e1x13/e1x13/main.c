//
//  main.c
//  e1x13
//
//  Created by Павел Хомич on 07/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define IN 1
#define OUT 0
#define SIZE 20

int main(int argc, const char * argv[]) {
    int i, j, c, wl, state;
    int hist[SIZE];
    
    for (i = 0; i < SIZE; i++) {
        hist[i] = 0;
    }
    
    wl = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state && wl < SIZE)
                hist[wl]++;
            state = OUT;
            wl = 0;
        } else if (!state) {
            state = IN;
            wl = 1;
        } else {
            wl++;
        }
    }
    
    for (i = 0; i < SIZE; i++) {
        printf("%2d: ", i);
        for (j = 0; j < hist[i]; j++)
            printf("-");
        printf("\n");
    }
    
    return 0;
}
