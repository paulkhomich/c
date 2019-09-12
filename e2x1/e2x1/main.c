//
//  main.c
//  e2x1
//
//  Created by Павел Хомич on 12/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <limits.h>

int main(int argc, const char * argv[]) {
    printf("char:\t%d\t%d\n", CHAR_MIN, CHAR_MAX);
    printf("short:\t%d\t%d\n", SHRT_MIN, SHRT_MAX);
    printf("int:\t%d\t%d\n", INT_MIN, INT_MAX);
    printf("long:\t%ld\t%ld\n", LONG_MIN, LONG_MAX);
    
    unsigned int a = 0;
    unsigned int intsize = a + INT_MAX - INT_MIN;
    
    unsigned long b = 0;
    unsigned long longsize = b + LONG_MAX - LONG_MIN;
    
    printf("unsigned char:\t%d\n", CHAR_MAX - CHAR_MIN);
    printf("unsigned short:\t%d\n", SHRT_MAX - SHRT_MIN);
    printf("unsigned int:\t%ud\n", intsize);
    printf("unsigned long:\t%lud\n", longsize);
    
    return 0;
}
