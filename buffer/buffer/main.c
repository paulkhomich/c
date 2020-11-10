#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

typedef struct Buffer Buffer;

struct Buffer {
    int size;
    int* data;
    int* p;
};

Buffer* init(int);
void push(Buffer*, int);
int pop(Buffer*);


int main() {
    Buffer* b = init(3);
    
    push(b, 22);
    push(b, 44);
    pop(b);
    push(b, 11);
    push(b, 333);
    pop(b);
    push(b, 10101);
    
    while (b->p != b->data) printf("%d\n", pop(b));
    
    return 0;
}


Buffer* init(int size) {
    Buffer* b = (Buffer*) malloc(sizeof(Buffer));
    
    b->size = size;
    b->p = b->data = (int*) malloc(size * sizeof(int));
    
    return b;
}

void push(Buffer* buf, int value) {
    if (buf->p == buf->data + buf->size) exit(1);
    
    *(buf->p++) = value;
}

int pop(Buffer* buf) {
    if (buf->p == buf->data) exit(1);

    return *(--buf->p);
}
