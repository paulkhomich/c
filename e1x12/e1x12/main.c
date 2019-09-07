//
//  main.c
//  e1x12
//
//  Created by Павел Хомич on 07/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, const char * argv[]) {
    int c, pos;
    
    pos = OUT;
    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (pos)
                putchar('\n');
            pos = OUT;
        } else {
            putchar(c);
            pos = IN;
        }
    }

    return 0;
}
