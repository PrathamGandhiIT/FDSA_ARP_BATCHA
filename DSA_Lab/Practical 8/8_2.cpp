
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

Node* ins(Node* root, int x) {
    if (root == NULL)
        return new Node(x);

    if (x < root->data)
        root->left = ins(root->left, x);
    else if (x > root->data)
        root->right = ins(root->right, x);

    return root;
}

void in(Node* root) {
    if (root == NULL)
        return;

    in(root->left);
    cout << root->data << " ";
    in(root->right);
}

int main() {
    int n, x;
    Node* root = NULL;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        root = ins(root, x);
    }

    cout << "Inorder sequence: ";
    in(root);

    return 0;
}
