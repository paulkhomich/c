//
//  main.c
//  e1x3
//
//  Created by Павел Хомич on 07/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

int main() {
    float c, f;
    int lower, max, step;
    
    lower = -40;
    max = 40;
    step = 2;
    
    c = lower;
    while (c < max) {
        f = (c * (9.0 / 5.0)) + 32.0;
        printf("%3.0f    %3.2f\n", c, f);
        c += step;
    }
    
    return 0;
}
