//
//  main.c
//  playground
//
//  Created by Павел Хомич on 22/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <string.h>


int main(int argc, const char * argv[]) {
    int s[] = {1,2,3};
    int x = 5;
    
    int *p = &x;
    p = s;
    printf("%d\t%d\n", *p, *(p+1));

    
    
    return 0;
}
