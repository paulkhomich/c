//
//  main.c
//  intro
//
//  Created by Павел Хомич on 06/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define MAX 40
#define LOW -40
#define STEP 2

int main() {
    float c, f;
    
    c = LOW;
    while (c < MAX) {
        f = (c * (9.0 / 5.0)) + 32.0;
        printf("%3.0f    %3.2f\n", c, f);
        c += STEP;
    }
    
    return 0;
}
