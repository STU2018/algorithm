#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};

class BinarySearchTree {
private:
    Node *root;

public:
    BinarySearchTree() {
        root = NULL;
    }

    void insert(int data) {
        Node *node = new Node;
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        if (root == NULL) {
            root = node;
        } else {
            Node *current = root;
            Node *parent;
            while (true) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                    if (current == NULL) {
                        parent->left = node;
                        break;
                    }
                } else {
                    current = current->right;
                    if (current == NULL) {
                        parent->right = node;
                        break;
                    }
                }
            }
        }
    }

    void preOrder(Node *node) {
        if (node != NULL) {
            cout << node->data << " ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node *node) {
        if (node != NULL) {
            inOrder(node->left);
            cout << node->data << " ";
            inOrder(node->right);
        }
    }

    void postOrder(Node *node) {
        if (node != NULL) {
            postOrder(node->left);
            postOrder(node->right);
            cout << node->data << " ";
        }
    }

    void displayPreOrder() {
        preOrder(root);
    }

    void displayInOrder() {
        inOrder(root);
    }

    void displayPostOrder() {
        postOrder(root);
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "PreOrder: ";
    bst.displayPreOrder();
    cout << endl;

    cout << "InOrder: ";
    bst.displayInOrder();
    cout << endl;

    cout << "PostOrder: ";
    bst.displayPostOrder();
    cout << endl;

    return 0;
}