#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* left;
    struct Node* right;
};

struct Node* create(int value) {
    struct Node* n = (struct Node*) malloc(sizeof(struct Node));
    n->value = value;
    n->left = NULL;
    n->right = NULL;
    return n;
}


void insert (struct Node* toNode, struct Node* n){
    if(n->value <= toNode->value){
        if(toNode->left == NULL){
            toNode->left = n;
        } else {
            insert (toNode->left, n);
        }
    } else {
        if(toNode->right == NULL){
            toNode->right = n;
        } else{
            insert(toNode->right, n);
        }
    }
}

void printInorder (struct Node* node){
    if(node->left != NULL){
        printInorder(node->left);
    }
    printf("%d\n", node->value);
    if(node->right != NULL){
        printInorder(node->right);
    }
}

int main (int argc, char* argv[]){
    struct Node* root = 0;
    for(int i= 1; i<argc; ++i){
        int value = atoi (argv[i]);
        struct Node* node = create(value);
        if(i == 1){
            root = node;
        } else {
            insert (root, node);
        }
    }
    if(root){
        printInorder(root);
    }
}
