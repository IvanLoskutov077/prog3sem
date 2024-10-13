#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* ptr;
};
typedef struct node Node;

int main() {
    Node node1;
    Node node2;

    node1.value = 1;
    node2.value = 2;

    node1.ptr = &node2;
    node2.ptr = &node1;

    printf("node1.value = %d, node1.ptr = %p\n", node1.value, (void*)node1.ptr);
    printf("node2.value = %d, node2.ptr = %p\n", node2.value, (void*)node2.ptr);

    printf("node1.ptr->value = %d\n", node1.ptr->value);
    printf("node2.ptr->value = %d\n", node2.ptr->value);

    return 0;
}
