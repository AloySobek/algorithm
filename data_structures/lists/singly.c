#include <stdio.h>
#include <stdlib.h>

typedef struct node_s {
    struct node_s *next;

    int data;
} node_t;

node_t *create_singly_list_node(int data) {
    node_t *node = (void *)malloc(sizeof(node_t));

    node->next = (void *)0;
    node->data = data;

    return node;
}

void destroy_singly_list(node_t *head) {
    if (head == (void *)0) {
        return;
    }

    node_t *iter = head;

    while (iter) {
        iter = iter->next;

        free(iter);
    }
}

int main() {
    printf("This is singly connected list implementation");

    node_t *head = (void *)0;

    head = create_singly_list_node(0);

    destroy_singly_list(head);

    return (0);
}
