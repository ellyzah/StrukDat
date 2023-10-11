#include <iostream>
using namespace std;

// Struktur simpul pohon biner
struct Node {
    string nama;
    Node* left;
    Node* right;
};

// Fungsi untuk membuat simpul baru
Node* buatSimpul(string nama) {
    Node* node = new Node();
    node->nama = nama;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Fungsi untuk melakukan traversal inorder
void inorderTraversal(Node* root) {
    if (root == NULL)
        return;

    inorderTraversal(root->left);
    cout << root->nama << " ";
    inorderTraversal(root->right);
}

int main() {
    // Membangun pohon biner
    Node* root = buatSimpul("Atin");
    root->left = buatSimpul("Bintang");
    root->right = buatSimpul("Zaki");
    root->left->left = buatSimpul("Dave");
    root->left->right = buatSimpul("Epul");
    root->right->left = buatSimpul("Franky");
    root->right->right = buatSimpul("Gaby");

    // Melakukan traversal inorder dan mencetak nama mahasiswa
    inorderTraversal(root);

    return 0;
}