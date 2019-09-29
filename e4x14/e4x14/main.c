//
//  main.c
//  e4x14
//
//  Created by Павел Хомич on 29/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define swap(t,x,y) { t _temp = x; x = y; y = _temp; }

int main(int argc, const char * argv[]) {
    int a = 11;
    int b = 22;

    swap(int, a, b);
    
    printf("%d\t%d\n", a, b);
    
    return 0;
}
