#include <stdio.h>
#include <stdlib.h>


typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;


TreeNode* newNode(int data) {
    TreeNode* node = (TreeNode*) malloc(sizeof(TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
TreeNode* createNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


TreeNode* insertsearchtree(TreeNode* root, int data) {
    if (root == NULL) {
        return newNode(data);
    } else if (data <= root->data) {
        root->left = insertsearchtree(root->left, data);
    } else {
        root->right = insertsearchtree(root->right, data);
    }
    return root;
}

TreeNode* trouverFeuilleDroite(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL && root->right == NULL) {
        return root;
    } else if (root->right != NULL) {
        return trouverFeuilleDroite(root->right);
    } else {
        return trouverFeuilleDroite(root->left);
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


int minVal(TreeNode* root) {
    if (root == NULL) {
        return -1;
    } else if (root->left == NULL) {
        return root->data;
    } else {
        return minVal(root->left);
    }
}

int maxVal(TreeNode* root) {
    if (root == NULL) {
        return -1;
    } else {
        int max = root->data;
        int leftMax = maxVal(root->left);
        int rightMax = maxVal(root->right);
        if (leftMax > max) {
            max = leftMax;
        }
        if (rightMax > max) {
            max = rightMax;
        }
        return max;
    }
}

int estArbreRecherche(TreeNode* root) {
    if (root == NULL) {
        return 1;
    } else if (root->left != NULL && root->left->data < root->data) {
        return 0;
    } else if (root->right != NULL && root->right->data > root->data) {
        return 0;
    } else if (!estArbreRecherche(root->left) || !estArbreRecherche(root->right)) {
        return 0;
    } else {
        return 1;
    }
}
void permuterDroiteRacine(TreeNode* arbre) {
    if (arbre == NULL) {
        return;
    }

    if (arbre->right == NULL) {
        return;
    }


    TreeNode* feuilleDroite = arbre->right;
    while (feuilleDroite->right != NULL) {
        feuilleDroite = feuilleDroite->right;
    }


    int temp = arbre->data;
    arbre->data = feuilleDroite->data;
    feuilleDroite->data = temp;
}
TreeNode* sousArbre(TreeNode* root, int n) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == n) {
        return root;
    }
    TreeNode* leftSubtree = sousArbre(root->left, n);
    TreeNode* rightSubtree = sousArbre(root->right, n);
    if (leftSubtree != NULL) {
        return leftSubtree;
    }
    if (rightSubtree != NULL) {
        return rightSubtree;
    }
    return NULL;
}


TreeNode* trouverFeuilleGauche(TreeNode* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL && root->right == NULL) {
        return root;
    } else if (root->left != NULL) {
        return trouverFeuilleGauche(root->left);
    } else {
        return trouverFeuilleGauche(root->right);
    }
}


int main() {


//    root = insertsearchtree(root, 10);
//    root = insertsearchtree(root, 9);
//    root = insertsearchtree(root, 5);
//    root = insertsearchtree(root, 8);
//    root = insertsearchtree(root, 4);
//    root = insertsearchtree(root, 17);
//    root = insertsearchtree(root, 14);
//    root = insertsearchtree(root, 18);
//    root = insertsearchtree(root, 16);
    TreeNode* root = createNode(10);
    root->left = createNode(15);
    root->right = createNode(5);
    root->left->left = createNode(17);
    root->left->left->left = createNode(18);
    root->left->left->right = createNode(16);
    root->left->right = createNode(14);
    root->right->left = createNode(8);
    root->right->right = createNode(4);


printf("Arbre binaire :\n");
printInOrder(root);



printf("\nLa plus petite valeur dans l'arbre est : %d\n", minVal(root));


int estAR = estArbreRecherche(root);
if (estAR) {
    printf("\nL'arbre est un arbre de recherche.\n");
} else {
    printf("\nL'arbre n'est pas un arbre de recherche.\n");
}



printf("\nLa feuille qui se trouve a lextreme gauche est : %d\n", trouverFeuilleGauche(root)->data);
printf("\nLa feuille qui se trouve a lextreme droite est : %d\n", trouverFeuilleDroite(root)->data);
 TreeNode* subTree = sousArbre(root, 15);
    if (subTree != NULL) {
        printf("Sous-arbre de racine %d : %d, %d\n", subTree->data, subTree->left->data, subTree->right->data);
    } else {
        printf("La valeur n'a pas été trouvée dans l'arbre\n");
    }
    printInOrder(root);
    permuterDroiteRacine(root);
    printInOrder(root);
return 0;}
