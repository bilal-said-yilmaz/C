#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

struct node {
    int data;
    int colour;
    struct node *parent; 
    struct node *left;   
    struct node *right;  
};

struct node *root = NULL;

struct node *grand_parent(struct node *n) {
    if (n != NULL && n->parent != NULL)
        return n->parent->parent;
    return NULL;
}

struct node *uncle(struct node *n) {
    struct node *g = grand_parent(n);
    if (g == NULL)
        return NULL;
    if (n->parent == g->left)
        return g->right;
    else
        return g->left;
}

void rotate_left(struct node *n) {
    struct node *r = n->right; // Sağ çocuk
    n->right = r->left;
    if (r->left != NULL)
        r->left->parent = n;
    r->parent = n->parent;
    if (n->parent == NULL)
        root = r;
    else if (n == n->parent->left)
        n->parent->left = r;
    else
        n->parent->right = r;
    r->left = n;
    n->parent = r;
}

void rotate_right(struct node *n) {
    struct node *l = n->left; // Sol çocuk
    n->left = l->right;
    if (l->right != NULL)
        l->right->parent = n;
    l->parent = n->parent;
    if (n->parent == NULL)
        root = l;
    else if (n == n->parent->right)
        n->parent->right = l;
    else
        n->parent->left = l;
    l->right = n;
    n->parent = l;
}

void case1(struct node *n) {
    if (n->parent == NULL)
        n->colour = BLACK;
    else
        case2(n);
}

void case2(struct node *n) {
    if (n->parent->colour == BLACK)
        return;
    else
        case3(n);
}

void case3(struct node *n) {
    struct node *u = uncle(n);
    struct node *g = grand_parent(n);
    if (u != NULL && u->colour == RED) {
        n->parent->colour = BLACK;
        u->colour = BLACK;
        g->colour = RED;
        case1(g);
    } else {
        case4(n);
    }
}

void case4(struct node *n) {
    struct node *g = grand_parent(n);
    if (n == n->parent->right && n->parent == g->left) {
        rotate_left(n->parent);
        n = n->left;
    } else if (n == n->parent->left && n->parent == g->right) {
        rotate_right(n->parent);
        n = n->right;
    }
    case5(n);
}

void case5(struct node *n) {
    struct node *g = grand_parent(n);
    n->parent->colour = BLACK;
    g->colour = RED;
    if (n == n->parent->left && n->parent == g->left)
        rotate_right(g);
    else if (n == n->parent->right && n->parent == g->right)
        rotate_left(g);
}

void insert(struct node *root, struct node *n) {
    if (root != NULL) {
        if (n->data < root->data) {
            if (root->left == NULL) {
                root->left = n;
                n->parent = root;
            } else {
                insert(root->left, n);
            }
        } else {
            if (root->right == NULL) {
                root->right = n;
                n->parent = root;
            } else {
                insert(root->right, n);
            }
        }
    }
}

void insert_node(int data) {
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->colour = RED;
    n->left = n->right = n->parent = NULL;

    if (root == NULL) {
        root = n;
    } else {
        insert(root, n);
    }
    case1(n); 
}

void inorder_traversal(struct node *n) {
    if (n == NULL)
        return;
    inorder_traversal(n->left);
    printf("%d (%s) ", n->data, n->colour == RED ? "Red" : "Black");
    inorder_traversal(n->right);
}

int main() {
    int values[] = {10, 20, 30, 15, 25, 5, 1};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++) {
        insert_node(values[i]);
    }

    printf("Inorder Traversal of Red-Black Tree:\n");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
