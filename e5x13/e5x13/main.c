//
//  main.c
//  e5x13
//
//  Created by Павел Хомич on 05/10/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char c;
    printf("1");
    while ((c = getchar())) {
        printf("2");
        putchar(c);
    }
    
    return 0;
}
