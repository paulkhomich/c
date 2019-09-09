//
//  main.c
//  e1x15
//
//  Created by Павел Хомич on 10/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define MIN -40
#define MAX 40
#define STEP 2

float convert(int c);

int main(int argc, const char * argv[]) {
    int c;
    
    c = MIN;
    while (c < MAX) {
        printf("%3dºC    %6.1fºF\n", c, convert(c));
        c += STEP;
    }
    
    return 0;
}

float convert(int c) {
    return ((9.0/5.0)*c + 32.0);
}
