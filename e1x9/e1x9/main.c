//
//  main.c
//  e1x9
//
//  Created by Павел Хомич on 07/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define ANTISPACE 0

int main(int argc, const char * argv[]) {
    int c, pc;
    
    pc = ANTISPACE;
    while ((c = getchar()) != EOF) {
        if (c != ' ')
            putchar(c);
        if (c == ' ' && pc != ' ') {
            putchar(c);
        }
        pc = c;
    }
    
    return 0;
}
