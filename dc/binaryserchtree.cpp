#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root, int value) {
    if (root == nullptr) 
        return new Node(value);
    if (value < root->data) 
        root->left = insert(root->left, value);
    else 
        root->right = insert(root->right, value);
    return root;
}

bool search(Node* root, int value) {
    if (root == nullptr) 
        return false;
    if (root->data == value) 
        return true;
    return value < root->data ? search(root->left, value) : search(root->right, value);
}

int depth(Node* root) {
    if (root == nullptr) 
        return 0;
    return 1 + max(depth(root->left), depth(root->right));
}

void displayLeafNodes(Node* root) {
    if (root == nullptr) 
        return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->data << " ";
        return;
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

int main() {
    Node* root = nullptr;
    int choice, value;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Display Depth\n";
        cout << "4. Display Leaf Nodes\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                root = insert(root, value);
                break;
            case 2:
                cout << "Enter value to search: ";
                cin >> value;
                if (search(root, value)) 
                    cout << "Found\n";
                else 
                    cout << "Not Found\n";
                break;
            case 3:
                cout << "Depth of the tree: " << depth(root) << endl;
                break;
            case 4:
                cout << "Leaf Nodes: ";
                displayLeafNodes(root);
                cout << endl;
                break;
            case 5:
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
