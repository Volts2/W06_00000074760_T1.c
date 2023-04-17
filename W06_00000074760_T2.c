#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct node {
    char data;
    struct node *left;
    struct node *right;
};
 struct node *createNode(char data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
 struct node *createTree(char *exp)
{
    int len = strlen(exp);
    struct node *root = createNode(exp[0]);
    struct node *curr = root;
     for (int i = 1; i < len; i++) {
        if (curr->data == '+' || curr->data == '-' || curr->data == '*' || curr->data == '/') {
            if (curr->right == NULL) {
                curr->right = createNode(exp[i]);
                curr = curr->right;
            } else if (curr->left == NULL) {
                curr->left = createNode(exp[i]);
                curr = curr->left;
            }
        } else {
            curr->data = exp[i];
        }
    }
     return root;
}
 void inorder(struct node *root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}
 int main()
{
    char exp1[] = "-*+abcd";
    char exp2[] = "*+ab+cd";
    char exp3[] = "+/ab/cd";
    
    struct node *root1 = createTree(exp1);
    struct node *root2 = createTree(exp2);
    struct node *root3 = createTree(exp3);
    
     printf("Inorder traversal of expression 1: ");
        inorder(root1);
        printf("\n");
     printf("Inorder traversal of expression 2: ");
        inorder(root2);
        printf("\n");
     printf("Inorder traversal of expression 3: ");
        inorder(root3);
        printf("\n");
     return 0;
}