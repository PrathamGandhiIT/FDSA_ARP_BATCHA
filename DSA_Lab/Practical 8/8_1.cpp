#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

void in(Node *root) {
    if (root == NULL)
        return;

    in(root->left);
    cout << root->data << " ";
    in(root->right);
}

void pre(Node *root) {
    if (root == NULL)
        return;

    cout << root->data << " ";
    pre(root->left);
    pre(root->right);
}

void post(Node *root) {
    if (root == NULL)
        return;

    post(root->left);
    post(root->right);
    cout << root->data << " ";
}

void level(Node *root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << "Inorder: ";
    in(root);

    cout << "\nPreorder: ";
    pre(root);

    cout << "\nPostorder: ";
    post(root);

    cout << "\nLevel Order: ";
    level(root);

    return 0;
}
