#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int NbrFeuilles(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    else {
        return NbrFeuilles(root->left) + NbrFeuilles(root->right);
    }
}

int nbr_AyantDeuxFils(TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int count = 0;
        if (root->left != NULL && root->right != NULL) {
            count = 1;
        }
        count += nbr_AyantDeuxFils(root->left) + nbr_AyantDeuxFils(root->right);
        return count;
    }
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

void printTree(TreeNode* root, int space) {

    if (root == NULL) {
        return;
    }
    space += 5;
    printTree(root->right, space);
    printf("\n");
    for (int i = 5; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    printTree(root->left, space);
}

int main() {

    TreeNode* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(5);
    root->left->left = createNode(17);
    root->left->left->left = createNode(18);
    root->left->left->right = createNode(16);
    root->left->right = createNode(14);
    root->right->left = createNode(8);
    root->right->right = createNode(4);


    int nb_feuilles = NbrFeuilles(root);
    printf("Le nombre de feuilles de l'arbre est : %d\n", nb_feuilles);


    int nb_noeuds_deux_fils = nbr_AyantDeuxFils(root);
    printf("Le nombre de noeuds ayant deux fils de l'arbre est : %d\n", nb_noeuds_deux_fils);
    printf("\n\n\n");
    printTree(root,2);

    return 0;
}
