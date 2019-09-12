//
//  main.c
//  e1x24
//
//  Created by Павел Хомич on 12/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define IN 1
#define OUT 0

int main(int argc, const char * argv[]) {
    int c, counter, state;
    
    counter = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        if (c == '"')
            state = !state;
        else if (c == '(' && !state)
            counter++;
        else if (c == ')' && !state)
            counter--;
    }
    
    if (counter > 0)
        printf("ERR: Uncompensed %d bracket(s)\n", counter);
    
    return 0;
}
