// INFIX'te önce en sol node yazlır parent a çıkılır ve sağ yazılır yani LNR şeklindedir ya da
// tam tersi RNL de geçerlidir. LNR küçükten büyüğe dolaşmadır RNL ise büyükten küçüğe
// PREFIX'te ise önce parent yazılır yani NRL ya da NLR
// POSTFIX'te ise en son parent yazılır LRN ya da RLN
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node * addNode (node *tree,int data) {
    if (tree == NULL) {
        node* root = ( node *) malloc(sizeof( node));
        if (root == NULL) {
            printf("Memory allocation failed!\n");
            return NULL;
        }
        root->data = data;
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    if (data < tree->data) {
        tree->left = addNode(tree->left, data);
    }else if (data > tree->data) {
        tree->right = addNode(tree->right, data);
    }
    return tree;
}

void traverse (node *tree){
    if (tree==NULL)
        return;
    traverse(tree->left);
    printf("%d\n", tree->data);
    traverse(tree->right);
}

int main(){
    node *tree =NULL;
    tree=addNode(tree,14);
    tree= addNode(tree,77);
    tree =addNode(tree,123);
    tree=addNode(tree,12);
    tree=addNode(tree,63);
    traverse(tree);
    return 0;
}
