//
//  main.c
//  e4x2
//
//  Created by Павел Хомич on 21/09/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>

#define EOL '\0'
#define YES 1
#define NO 0

double atofd(char s[]);
int isnumber(int);

int main(int argc, const char * argv[]) {
    char s[] = "123.45e1";
    printf("%.9lf\n", atofd(s));
    
    return 0;
}

double atofd(char s[]) {
    double value, power, exp;
    int i, j;
    
    value = 0.0;
    for (i = 0; isnumber(s[i]); i++) {
        value = 10.0 * value + (s[i] - '0');
    }
    if (s[i] == '.')
        i++;
    
    power = 0.1;
    for (; isnumber(s[i]); i++) {
        value = value + (s[i] - '0') * power;
        power *= power;
    }
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    
    exp = s[i] == '-' ? 0.1 : 10;
    if (s[i] == '-' || s[i] == '+')
        i++;

    for (j = (s[i] - '0'); j > 0; j--)
        value *= exp;

    return value;
}
