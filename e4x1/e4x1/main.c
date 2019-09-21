//
//  main.c
//  e4x1
//
//  Created by Павел Хомич on 21/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define SIZE 512
#define EOL '\0'

int strrindex(char[], char[]);

int main(int argc, const char * argv[]) {
    char s[] = "People are strange, when you are stranger\0";
    char t[] = "ge\0";
    
    printf("%d\n", strrindex(s, t));
    
    return 0;
}

int strrindex(char s[], char t[]) {
    int index, i, j;
    
    index = -1;
    for (i = 0; s[i] != EOL; i++) {
        for (j = 0; s[i+j] == t[j] && s[i+j] != EOL; j++)
            ;
        if (j > 0 && t[j] == EOL)
            index = i;
    }
    
    return index;
}
