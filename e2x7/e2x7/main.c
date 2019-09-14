//
//  main.c
//  e2x7
//
//  Created by Павел Хомич on 15/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

int main(int argc, const char * argv[]) {
    printf("%d\n", invert(12, 2, 2));
    
    return 0;
}

unsigned int invert(unsigned int x, int p, int n) {
    return (~(~0 << n) << (p+1-n)) ^ x;
}
