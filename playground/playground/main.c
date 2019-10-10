//
//  main.c
//  playground
//
//  Created by Павел Хомич on 22/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <string.h>

int sum(int, int, void (*)(void));
void hi(void);
void bye(void);

int main(int argc, const char * argv[]) {
    sum(1,4, hi);
    sum(2,8, bye);
    
    return 0;
}

int sum(int a, int b, void(*callback)(void)) {
    callback();

    return a + b;
}

void hi(void) {
    printf("hi\n");
}

void bye(void) {
    printf("bye\n");
}
