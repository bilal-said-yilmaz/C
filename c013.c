#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[50];
    char phone[20];
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(char* name, char* phone) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, char* name, char* phone) {
    if (root == NULL) {
        return createNode(name, phone);
    }
    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, name, phone);
    } else {
        root->right = insert(root->right, name, phone);
    }
    return root;
}

void searchAndPrint(struct Node* root, char* prefix, int* found) {
    if (root == NULL) {
        return;
    }

    searchAndPrint(root->left, prefix, found);

    if (strncmp(root->name, prefix, strlen(prefix)) == 0) {
        printf("%s\n", root->name);
        *found = 1;
    }

    searchAndPrint(root->right, prefix, found);
}

void freeTree(struct Node* root) {
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main() {
    struct Node* root = NULL;
    char name[50];
    char phone[20];

    while (1) {
        scanf("%s", name);
        if (strcmp(name, "-1") == 0)
            break;
        scanf("%s", phone);
        root = insert(root, name, phone);
    }

    char prefix[50] = "";
    char c;
    while (1) {
        scanf(" %c", &c);
        if (c == '-') {
            scanf("%c", &c);
            if (c == '1') break;
        }

        int len = strlen(prefix);
        prefix[len] = c;
        prefix[len + 1] = '\0';
        int found = 0;
        searchAndPrint(root, prefix, &found);

        if (!found) {
            printf("nobody\n");
            break;
        }
    }
    freeTree(root);
    return 0;
}