#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    bool leftThread, rightThread;
};

// Function to create a new node
Node* createNode(int data) {
    Node* node = new Node();
    node->data = data;
    node->left = node->right = nullptr;
    node->leftThread = node->rightThread = true;
    return node;
}

// Insert a node into the Threaded Binary Tree
Node* insert(Node* root, int data) {
    Node* newNode = createNode(data);
    if (!root) {
        return newNode;
    }

    Node* current = root;
    Node* parent = nullptr;

    while (current) {
        parent = current;
        if (data < current->data) {
            if (!current->leftThread) {
                current = current->left;
            } else {
                break;
            }
        } else {
            if (!current->rightThread) {
                current = current->right;
            } else {
                break;
            }
        }
    }

    if (data < parent->data) {
        newNode->left = parent->left;
        newNode->right = parent;
        parent->leftThread = false;
        parent->left = newNode;
    } else {
        newNode->right = parent->right;
        newNode->left = parent;
        parent->rightThread = false;
        parent->right = newNode;
    }

    return root;
}

// In-order traversal of Threaded Binary Tree
void inOrder(Node* root) {
    if (!root) {
        cout << "Tree is empty.\n";
        return;
    }

    Node* current = root;
    while (!current->leftThread) {
        current = current->left;
    }

    while (current) {
        cout << current->data << " ";
        if (current->rightThread) {
            current = current->right;
        } else {
            current = current->right;
            while (current && !current->leftThread) {
                current = current->left;
            }
        }
    }
    cout << endl;
}

// Search for a node in the Threaded Binary Tree
bool search(Node* root, int data) {
    Node* current = root;
    while (current) {
        if (data == current->data) {
            return true;
        }
        if (data < current->data) {
            if (current->leftThread) {
                return false;
            }
            current = current->left;
        } else {
            if (current->rightThread) {
                return false;
            }
            current = current->right;
        }
    }
    return false;
}

// Delete a node from Threaded Binary Tree
Node* deleteNode(Node* root, int data) {
    cout << "Delete operation is complex for TBT and is not implemented in this simplified version.\n";
    return root;
}

// Clear the tree
void clear(Node*& root) {
    root = nullptr;
    cout << "Tree cleared.\n";
}

int main() {
    Node* root = nullptr;
    int choice, data;

    do {
        cout << "\n1. Insert\n2. In-order Traversal\n3. Search\n4. Delete\n5. Clear Tree\n6. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> data;
                root = insert(root, data);
                break;
            case 2:
                cout << "In-order Traversal: ";
                inOrder(root);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> data;
                if (search(root, data)) {
                    cout << "Value found.\n";
                } else {
                    cout << "Value not found.\n";
                }
                break;
            case 4:
                cout << "Enter value to delete: ";
                cin >> data;
                root = deleteNode(root, data);
                break;
            case 5:
                clear(root);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 6);

    return 0;
}
