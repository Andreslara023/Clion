#include <stdlib.h>
#include <stdio.h>

typedef struct Node{

    int element;
    struct Node* left;
    struct Node* right;

}Node;

Node* CreateTree(){

    Node* newTree = malloc(sizeof(Node));
    newTree-> left = NULL;
    newTree-> right = NULL;
}

Node* push(Node* tree, int element){

    if (tree == NULL){
        tree->element = element;
    }
    if (element == tree->element){
        return tree;
    }
    if (element < tree->element){
        return push(tree->left, element);
    }
    if (element > tree->element){
        return push(tree->right, element);
    }
}

void minor(Node* tree){

    if (tree == NULL){
        printf("El arbol no tiene elementos");
        return;
    }

    Node* newTree = CreateTree();
    newTree = tree;

    while (newTree->left != NULL){
        newTree->left = newTree->left->left;
    }
    printf("%d", newTree->element);
}
void higher(Node* tree){

    if (tree == NULL){
        printf("El arbol no tiene elementos");
        return;
    }
    Node* newTree = CreateTree();
    newTree = tree;

    while (newTree->right != NULL){
        newTree->right = newTree->right->right;
    }
    printf("%d", newTree->element);

}

int NroNode(Node* tree){

    if (tree == NULL){
        return 0;
    }
    return NroNode(tree->right) + NroNode(tree->left) + 1;
}

void DeleteTree(Node* tree){
    if(tree == NULL){
        return;
    }
    DeleteTree(tree->right);
    DeleteTree(tree->left);
    free(tree);
}
Node* DeleteElement(Node* tree, int element){

    if(tree == NULL){
        return NULL;
    }
    if(tree->element == element){
        if(tree->right == tree->left){
            free(tree);
            return NULL;
        }
        Node* newTree = CreateTree();
        newTree = tree;

        if(tree->right == NULL){
            newTree = newTree->left;
            free(tree);
            return newTree;
        }
        if(tree->left == NULL){
            newTree = newTree->right;
            free(tree);
            return newTree;
        }
        newTree = newTree->left;
        while(newTree->right != NULL){
            newTree = newTree->right;
        }
        tree->element = newTree->element;
        tree->left = DeleteElement(tree->left, newTree->element);
        return tree;
    }

    if(element < tree->element){
        tree->left = DeleteElement(tree->left, element);
    }
    else{
        tree->right = DeleteElement(tree->right, element);
    }
    return tree;
}

int high(Node* tree){
    int R = 0, L = 0;
    if(tree == NULL){
        return 0;
    }
    if(tree->left != NULL){
        L = 1 + high(tree->right);
    }
    if(tree->right != NULL){
        R = 1 + high(tree->left);
    }
    if(R > L){
        return R;
    }
    return L;
}

int main(){

    Node* tree = CreateTree();
    return 0;

}
