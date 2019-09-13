//
//  main.c
//  e2x3
//
//  Created by Павел Хомич on 13/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

#define IS 1
#define ISNT 0

int htoi(char s[]);

int main(int argc, const char * argv[]) {
    printf("%d\n", htoi("Ox11"));
    
    return 0;
}

int htoi(char s[]) {
    int i, c, n, ishex;

    if (s[0] != 'O' || (s[1] != 'x' && s[1] != 'X'))
        return -1;
    
    ishex = IS;
    n = 0;
    for (i = 2; ishex; i++) {
        c = tolower(s[i]);
        if (c >= 'a' && c <= 'f')
            n = n * 16 + (c - 'a');
        else if (isdigit(c))
            n = n * 16 + (c - '0');
        else
            ishex = ISNT;
    }
    
    return n;
}


