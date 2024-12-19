#include <stdio.h>
#include <stdlib.h>

typedef enum { 
    RED, 
    BLACK 
} Color;

typedef struct Node {
    int data;
    Color color;
    struct Node *left, *right, *parent;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->color = RED;  
    newNode->left = newNode->right = newNode->parent = NULL;
    return newNode;
}

void leftRotate(Node** root, Node* a) {
    Node* b = a->right;
    a->right = b->left;
    if (b->left != NULL)
        b->left->parent = a;
    b->parent = a->parent;
    if (a->parent == NULL)
        *root = b;
    else if (a == a->parent->left)
        a->parent->left = b;
    else
        a->parent->right = b;
    b->left = a;
    a->parent = b;
}

void rightRotate(Node** root, Node* a) {
    Node* b = a->left;
    a->left = b->right;
    if (b->right != NULL)
        b->right->parent = a;
    b->parent = a->parent;
    if (a->parent == NULL)
        *root = b;
    else if (a == a->parent->right)
        a->parent->right = b;
    else
        a->parent->left = b;
    b->right = a;
    a->parent = b;
}

void fixInsert(Node** root, Node* c) {
    while (c->parent != NULL && c->parent->color == RED) {
        if (c->parent == c->parent->parent->left) {
            Node* b = c->parent->parent->right;  
            if (b != NULL && b->color == RED) { 
                c->parent->color = BLACK;
                b->color = BLACK;
                c->parent->parent->color = RED;
                c = c->parent->parent;
            } else {
                if (c == c->parent->right) {  
                    c = c->parent;
                    leftRotate(root, c);
                }
                c->parent->color = BLACK;  
                c->parent->parent->color = RED;
                rightRotate(root, c->parent->parent);
            }
        } else {
            Node* b = c->parent->parent->left; 
            if (b != NULL && b->color == RED) {
                c->parent->color = BLACK;
                b->color = BLACK;
                c->parent->parent->color = RED;
                c = c->parent->parent;
            } else {
                if (c == c->parent->left) {
                    c = c->parent;
                    rightRotate(root, c);
                }
                c->parent->color = BLACK;
                c->parent->parent->color = RED;
                leftRotate(root, c->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}


void insert(Node** root, int data) {
    Node* newNode = createNode(data);
    Node* b = NULL;
    Node* a = *root;

    while (a != NULL) {
        b = a;
        if (newNode->data < a->data)
            a = a->left;
        else
            a = a->right;
    }
    newNode->parent = b;
    if (b == NULL)
        *root = newNode;
    else if (newNode->data < b->data)
        b->left = newNode;
    else
        b->right = newNode;

    fixInsert(root, newNode);
}


void inOrder(Node* root) {
    if (root == NULL)
        return;

    inOrder(root->left);
    printf("%d", root->data);
    printf("\n");
    inOrder(root->right);
}

void LevelOrder(Node* root) {
    if (root == NULL)
        return;

    Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    while (front < rear) {
        int level = rear - front;
        for (int i = 0; i < level; i++){
            Node* nav = queue[front++];
            printf("%d %s", nav->data, nav->color == RED ? "R" : "B");
            if (nav->parent != NULL) {
                printf(" (%d %c)", nav->parent->data,
                       nav == nav->parent->left ? 'L' : 'R');
            }
            printf(" ");

            if (nav->left != NULL)
                queue[rear++] = nav->left;
            if (nav->right != NULL)
                queue[rear++] = nav->right;
        }
        printf("\n");
    }
}


int main() {
    Node* root = NULL;
    int data;

    while (1) {

        scanf("%d", &data);

        if (data == -1)
            break;

        insert(&root, data);
    }

    inOrder(root);

    printf("\n");

    LevelOrder(root);

    return 0;
}
