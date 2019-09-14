//
//  main.c
//  e2x6
//
//  Created by Павел Хомич on 14/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, unsigned int y);

int main(int argc, const char * argv[]) {
    printf("%d\n", setbits(12, 5, 2, 2)); // 001100 -> 101100 
    
    return 0;
}

unsigned int setbits(unsigned int x, int p, int n, unsigned int y) {
    return (x & ~(~(~0 << n) << (p+1-n))) | ((~(~0 << n) & y) << (p+1-n));
}
