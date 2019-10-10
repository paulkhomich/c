//
//  main.c
//  e6x5
//
//  Created by Павел Хомич on 10/10/2019.
//  Copyright © 2019 Павел Хомич. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAXWORD 256

int getword(char *);
struct node *addnode(char *, struct node *);
struct node *nodealloc(void);
void showtree(struct node *);

struct node {
    char *word;
    int n;
    struct node *left;
    struct node *right;
};

int main(int argc, const char * argv[]) {
    char word[MAXWORD];
    struct node *root = NULL;
    
    while (getword(word) != EOF) {
        root = addnode(word, root);
    }
    showtree(root);

    return 0;
}

struct node *addnode(char *word, struct node *root) {
    int b;

    if (root == NULL) {
        root = nodealloc();
        root->word = strdup(word);
        root->n = 1;
        root->left = root->right = NULL;
    } else if ((b = strcmp(word, root->word)) == 0){
        root->n++;
    } else if (b < 0) {
        root->left = addnode(word, root->left);
    } else {
        root->right = addnode(word, root->right);
    }
    
    return root;
}

void showtree(struct node *root) {
    if (root != NULL) {
        printf("%4d\t%s\n", root->n, root->word);
        showtree(root->left);
        showtree(root->right);
    }
}

struct node *nodealloc(void) {
    return (struct node *) malloc(sizeof(struct node));
}

int getword(char *word) {
    static int iseof = 0;
    int c;
    char *w = word;
    
    if (iseof)
        return EOF;
    
    while (isspace(c = getchar()))
        ;
    
    if (isalnum(c))
        *w++ = c;
    else if (c == EOF) {
        *w = '\0';
        
        return EOF;
    }
    
    while (isalnum((c = getchar())))
        *w++ = c;
    *w = '\0';
    
    if (c == EOF)
        iseof = 1;
    
    return word[0];
}
