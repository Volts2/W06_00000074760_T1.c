#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

// Deklarasi Struct untuk Linked List dalam Tree
typedef struct Node{
    int key;
    struct Node *left, *right;
}Node;

// Function yang digunakan untuk membuat node baru
Node *newNode(int item){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Function yang digunakan untuk memasukkan node baru ke
Node *insert(Node *node, int key){
    // Jika Tree kosong
    // Atau ketika berada pada node kosong (left / right)
    if (node == NULL)
        return newNode(key);

    // Jika key kurang dari key pada node sementara
    if (key < node->key)
    // Turun ke left dari node sementara
        node->left = insert(node->left, key);

    // Jika key lebih dari key pada node sementara
    else if (key > node->key)
    // Turun ke right dari node sementara
        node->right = insert(node->right, key);

    // return node jika sudah berhasil insert
    return node;
}

// Fungsi Pre-order Traversal
void preOrder(Node *root){
    if (root != NULL){
        printf("%d ", root->key);
        preOrder(root->left);
        preOrder(root->right);
    }
}

// Fungsi In-order Traversal
void inOrder(Node *root){
    if (root != NULL){
        inOrder(root->left);
        printf("%d ", root->key);
        inOrder(root->right);
    }
}

// Fungsi Post-order Traversal
void postOrder(Node *root){
    if (root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->key);
    }
}

int main(){
    // Buat root sebagai NULL agar tree dianggap kosong
    Node *root = NULL;

    // Implementasi sederhana untuk tree
    // Masukkan terlebih dahulu data ke dalam root
    root = insert(root, 50);
    // Data sisanya tinggal dimasukkan ke dalam root
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Output Pre-order Traversal
    printf("Pre-order Traversal: ");
    preOrder(root);
    printf("\n");

    // Output In-order Traversal
    printf("In-order Traversal: ");
    inOrder(root);
    printf("\n");

    // Output Post-order Traversal
    printf("Post-order Traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}
