//
//  main.c
//  e2x8
//
//  Created by Павел Хомич on 15/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);
int sizeofint(void);

int main(int argc, const char * argv[]) {
    printf("%u\n", rightrot(1,  1));
    return 0;
}

unsigned int rightrot(unsigned int x, int n) {
    int size = sizeofint();
    
    return ((~(~0 << n) & x) << (size-n)) | (x >> n);
}

int sizeofint(void) {
    int i;
    
    unsigned int n = 1;
    for (i = 1; (n = n << 1) != 0; i++)
        ;
    
    return i;
}
