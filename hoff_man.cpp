#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Node structure
struct Node {
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

// Comparator for Min Heap
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Function to print Huffman Codes
void printCodes(Node* root, string code) {
    if (!root)
        return;

    // If leaf node
    if (!root->left && !root->right)
        cout << root->data << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        char ch;
        int freq;
        cin >> ch >> freq;
        minHeap.push(new Node(ch, freq));
    }

    // Build Huffman Tree
    while (minHeap.size() > 1) {
        Node* left = minHeap.top(); minHeap.pop();
        Node* right = minHeap.top(); minHeap.pop();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        minHeap.push(parent);
    }

    cout << "\nHuffman Codes:\n";
    printCodes(minHeap.top(), "");

    return 0;
}