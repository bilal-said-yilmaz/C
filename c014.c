#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data){
    struct node* new=(struct node *) malloc(sizeof(struct node));
    new->data=data;
    new->left=NULL;
    new->right=NULL;

    return new;
} 
int main(){
    struct node* root =newNode(1);

    root->left  = newNode(2);
    root->right = newNode(3);

    root->left->left  = newNode(4);
    root->left->right = newNode(5);

    root->right->left  = newNode(6);
    root->right->right = newNode(7);

    printf("root: %d\n",root->data);
    printf("root->left: %d\n",root->left->data);
    printf("root->right: %d\n",root->right->data);
    printf("root->left->right: %d\n",root->left->right->data);

    return 0;
}
