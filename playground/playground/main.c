//
//  main.c
//  playground
//
//  Created by Павел Хомич on 22/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

extern int MAXSIZE;
extern int go(void);

char c[] = "abc";

int main(int argc, const char * argv[]) {
    for (int i = 0; c[i] != '\0'; i++) {
        printf("%c\n", c[i]);
    }
    
    return 0;
}
