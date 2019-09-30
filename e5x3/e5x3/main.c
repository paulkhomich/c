//
//  main.c
//  e5x3
//
//  Created by Павел Хомич on 30/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

void _strcat(char *, char *);

int main(int argc, const char * argv[]) {
    char s[] = "yester";
    char t[] = "day";
    
    printf("%s\t%s\n", s, t);
    _strcat(s, t);
    printf("%s\n", s);
    
    return 0;
}

void _strcat(char *s,  char *t) {
    for (; *s; s++)
        ;

    for (; (*s++ = *t++);)
        ;
}
