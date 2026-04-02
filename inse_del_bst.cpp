#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
Node* insert(Node* root, int value) {
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);
    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

// Find minimum value node
Node* findMin(Node* root) {
    while(root->left != NULL)
        root = root->left;
    return root;
}

// Delete node from BST
Node* deleteNode(Node* root, int key) {
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with only one child or no child
        if(root->left == NULL)
            return root->right;
        else if(root->right == NULL)
            return root->left;

        // Node with two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if(root != NULL) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main() {
    Node* root = NULL;
    int n, value, del;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> value;
        root = insert(root, value);
    }

    cout << "BST Inorder Traversal: ";
    inorder(root);

    cout << "\nEnter element to delete: ";
    cin >> del;

    root = deleteNode(root, del);

    cout << "BST after deletion: ";
    inorder(root);

    return 0;
}