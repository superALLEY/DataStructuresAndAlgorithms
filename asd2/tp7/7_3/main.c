#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* construire(int n, TreeNode* g, TreeNode* d) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = n;
    node->left = g;
    node->right = d;
    return node;
}

void ajouter(TreeNode** B, int m) {
    if (*B == NULL) {
        *B = construire(m, NULL, NULL);
    } else if (m < (*B)->data) {
        ajouter(&((*B)->left), m);
    } else {
        ajouter(&((*B)->right), m);
    }
}

int chercherVal(TreeNode* A, int n) {
    if (A == NULL) {
        return false;
    } else if (A->data == n) {
        return true;
    } else if (n > A->data) {
        return chercherVal(A->left, n);
    } else {
        return chercherVal(A->right, n);
    }
}

void printInOrder(TreeNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}
int main()
{

    TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

     TreeNode* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(5);
    root->left->left = createNode(17);
    root->left->left->left = createNode(18);
    root->left->left->right = createNode(16);
    root->left->right = createNode(14);
    root->right->left = createNode(8);
    root->right->right = createNode(4);
    printInOrder(root);
    if(chercherVal(root,9)){
        printf("existe\n");
    }else{
        printf("n existe pas");
    }
    return 0;
}
