#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char*               string;             // BOOL-VECTOR
typedef struct bdd_node*    BDD;                // BDD ROOT
typedef struct bdd_node*    BDD_NODE;           // BDD NODES
struct bdd_node {                               // SPECIAL NODES -> O and 1 terminals
    BDD_NODE    pred;                           // IF t = NULL => it's 1 NODE ELSE it's 0 NODE
    BDD_NODE    t;
    BDD_NODE    f;
};

// Create BDD node from Pred (true/false arc)
BDD_NODE create_bdd_node(BDD_NODE pred, bool tf) {
    BDD_NODE node = malloc(sizeof(struct bdd_node));
    
    if (!pred)
        return node;
    
    node->pred = pred;
    if (tf)
        pred->t = node;
    else
        pred->f = node;
    
    return node;
}

// Create full BDD from vector-string => {0001} = a AND b
BDD create_bdd(unsigned int n, string vec) {
    BDD root = create_bdd_node(NULL, true);
    
    if (!n) {
        root->f = (*vec == '0') ? NULL : root;
        root->t = (*vec == '0') ? root : NULL;
        
        return root;
    }
    
    // Create two subvectors -> first half (for %x% = 0) and second half (for %x% = 1)
    size_t half = strlen(vec) / 2;
    char vec_f[half];
    char vec_t[half];
    strcpy(vec_t, (vec + half));
    strncpy(vec_f, vec, half);
    
    --n;
    BDD bdd_f = create_bdd(n, vec_f);
    BDD bdd_t = create_bdd(n, vec_t);
    root->t = bdd_t;
    root->f = bdd_f;

    bdd_t->pred = root;
    bdd_f->pred = root;

    return root;
}

int bdd_check(BDD bdd, string vec) {
    char c;
    while ((c = *vec++)) {
        if (c == '0')
            bdd = bdd->f;
        else if (c == '1')
            bdd = bdd->t;
        else
            return -1;
    }
    
    if (!bdd->t)
        return 1;
    else if (!bdd->f)
        return 0;
    else
        return -1;
}

int main(void) {
    BDD andb = create_bdd(3, "00010110");
    int ans = bdd_check(andb, "011");
    
    printf("Ans:\t%d\n", ans);
    
    return 0;
}
