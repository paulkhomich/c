//
//  main.c
//  e3x1
//
//  Created by Павел Хомич on 16/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(int argc, const char * argv[]) {
    int v[] = {11, 12, 13, 14, 15, 16, 17, 18};

    printf("%d\n", binsearch(10, v, 8));
    
    return 0;
}

int binsearch(int x, int v[], int n) {
    int low, mid, high;
    
    low = 0;
    high = n - 1;
    mid = (high + low) / 2;
    while (high - low > 0) {
        if (x <= v[mid])
            high = mid;
        else
            low = mid + 1;
        
        mid = (high + low) / 2;
    }
    
    if (x == v[mid])
        return mid;
    else
        return -1;
}
