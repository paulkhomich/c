//
//  main.c
//  e5x4
//
//  Created by Павел Хомич on 30/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

int _strend(char *, char *);

int main(int argc, const char * argv[]) {
    char s[] = "knight";
    char t[] = "t";
    
    printf("%d\n", _strend(s, t));
    
    
    return 0;
}

int _strend(char *s, char *t) {
    char *p = t;
    
    while (*s)
        if (*s++ == *t)
            t++;
        else
            t = p;
    
    return t > p;
}
