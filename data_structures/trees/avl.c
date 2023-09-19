#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

struct node {
    int data;
    int height;

    struct node *right;
    struct node *left;
};

int max(int a, int b) { return a > b ? a : b; }

int get_height(struct node *node) {
    if (node == NULL) {
        return 0;
    }

    return node->height;
}

int get_balance_factor(struct node *node) {
    return get_height(node->left) - get_height(node->right);
}

struct node *create_node(int data) {
    struct node *node = (struct node *)malloc(sizeof(struct node));

    node->data = data;
    node->height = 1;
    node->left = NULL;
    node->right = NULL;

    return node;
}

struct node *left_rotation(struct node *node) {
    struct node *right = node->right;
    struct node *left = right->left;

    right->left = node;
    node->right = left;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    right->height = max(get_height(right->left), get_height(right->right)) + 1;

    return right;
}

struct node *right_rotation(struct node *node) {
    struct node *left = node->left;
    struct node *right = left->right;

    left->right = node;
    node->left = right;

    node->height = max(get_height(node->left), get_height(node->right)) + 1;
    left->height = max(get_height(left->left), get_height(left->right)) + 1;

    return left;
}

struct node *insert_into_avl_tree(struct node *node, int data) {
    if (node == NULL) {
        return create_node(data);
    } else if (node->data > data) {
        node->left = insert_into_avl_tree(node->left, data);
    } else {
        node->right = insert_into_avl_tree(node->right, data);
    }

    node->height = max(get_height(node->left), get_height(node->right)) + 1;

    int balance_factor = get_balance_factor(node);

    if (balance_factor > 1) {
        if (node->left->left) {
            return right_rotation(node);
        } else {
            node->left = left_rotation(node->left);

            return right_rotation(node);
        }
    } else if (balance_factor < -1) {
        if (node->right->right) {
            return left_rotation(node);
        } else {
            node->right = right_rotation(node->right);

            return left_rotation(node);
        }
    }

    return node;
}

struct node *get_from_avl_tree(struct node *node, int data) {
    if (node == NULL) {
        return NULL;
    }

    if (node->data == data) {
        return node;
    } else if (node->data > data) {
        return get_from_avl_tree(node->left, data);
    } else {
        return get_from_avl_tree(node->right, data);
    }
}
