#include <stdlib.h>

struct node {
    int data;

    struct node *left;
    struct node *right;
};

struct node *binary_tree_create_node(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;

    node->left = (void *)0;
    node->right = (void *)0;

    return node;
}

struct node *binary_tree_insert(struct node *node, int data) {
    if (node == (void *)0) {
        return binary_tree_create_node(data);
    }

    if (node->data < data) {
        return binary_tree_insert(node->left, data);
    } else {
        return binary_tree_insert(node->right, data);
    }
}

struct node *binary_tree_get(struct node *node, int data) {
    if (node == (void *)0) {
        return (void *)0;
    }

    if (node->data == data) {
        return node;
    } else if (node->data > data) {
        return binary_tree_get(node->left, data);
    } else {
        return binary_tree_get(node->right, data);
    }
}
