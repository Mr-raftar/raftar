#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    Node* root;
    
    // Helper function for insertion
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        
        // Handle duplicates: Do not insert duplicate values in the tree
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        
        return node;
    }

    // Helper function for deletion
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with the value to be deleted found
            
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            // Node with two children: Get the inorder successor (smallest in the right subtree)
            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }
    
    // Helper function to find minimum value node
    Node* findMin(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Helper function for searching
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        
        if (value < node->data) {
            return search(node->left, value);
        } else if (value > node->data) {
            return search(node->right, value);
        }
        
        return true;
    }

    // Helper function to find the depth of the tree
    int depth(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        int leftDepth = depth(node->left);
        int rightDepth = depth(node->right);
        return max(leftDepth, rightDepth) + 1;
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

    // Helper function to display mirror image of the tree
    void mirror(Node* node) {
        if (node == nullptr) return;
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }

    // Helper function to create a copy of the tree
    Node* copy(Node* node) {
        if (node == nullptr) return nullptr;
        Node* newNode = new Node(node->data);
        newNode->left = copy(node->left);
        newNode->right = copy(node->right);
        return newNode;
    }

    // Helper function to display parent-child nodes
    void displayParentChild(Node* node) {
        if (node == nullptr) return;
        if (node->left != nullptr || node->right != nullptr) {
            cout << "Parent: " << node->data << " -> ";
            if (node->left != nullptr) {
                cout << "Left Child: " << node->left->data << " ";
            }
            if (node->right != nullptr) {
                cout << "Right Child: " << node->right->data;
            }
            cout << endl;
        }
        displayParentChild(node->left);
        displayParentChild(node->right);
    }

    // Helper function to display leaf nodes
    void displayLeafNodes(Node* node) {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            cout << node->data << " ";
        }
        displayLeafNodes(node->left);
        displayLeafNodes(node->right);
    }

    // Helper function to display tree level by level
    void levelOrder(Node* root) {
        if (root == nullptr) return;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front();
            cout << temp->data << " ";
            q.pop();
            if (temp->left != nullptr) {
                q.push(temp->left);
            }
            if (temp->right != nullptr) {
                q.push(temp->right);
            }
        }
        cout << endl;
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    // Function to insert a value
    void insert(int value) {
        root = insert(root, value);
    }

    // Function to delete a value
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Function to search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Function to display inorder traversal
    void inorder() {
        inorder(root);
        cout << endl;
    }

    // Function to display preorder traversal
    void preorder() {
        preorder(root);
        cout << endl;
    }

    // Function to display postorder traversal
    void postorder() {
        postorder(root);
        cout << endl;
    }

    // Function to display depth of the tree
    void displayDepth() {
        cout << "Depth of tree: " << depth(root) << endl;
    }

    // Function to display the mirror image of the tree
    void displayMirror() {
        mirror(root);
        cout << "Mirror image of the tree:" << endl;
        inorder(root);
        cout << endl;
    }

    // Function to create a copy of the tree
    BinarySearchTree* copy() {
        BinarySearchTree* newTree = new BinarySearchTree();
        newTree->root = copy(root);
        return newTree;
    }

    // Function to display parent-child nodes
    void displayParentChild() {
        displayParentChild(root);
    }

    // Function to display leaf nodes
    void displayLeafNodes() {
        cout << "Leaf nodes: ";
        displayLeafNodes(root);
        cout << endl;
    }

    // Function to display tree level by level
    void displayLevelOrder() {
        cout << "Level order traversal: ";
        levelOrder(root);
    }
};

int main() {
    BinarySearchTree bst;
    int choice, value;

    do {
        cout << "\nBinary Search Tree Operations Menu:\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Inorder Traversal\n";
        cout << "5. Preorder Traversal\n";
        cout << "6. Postorder Traversal\n";
        cout << "7. Display Depth of Tree\n";
        cout << "8. Display Mirror Image of Tree\n";
        cout << "9. Create a Copy of the Tree\n";
        cout << "10. Display Parent-Child Nodes\n";
        cout << "11. Display Leaf Nodes\n";
        cout << "12. Display Level-wise Tree\n";
        cout << "13. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insert(value);
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.deleteValue(value);
                break;
            case 3:
                cout << "Enter value to search: ";
                cin >> value;
                cout << (bst.search(value) ? "Found" : "Not Found") << endl;
                break;
            case 4:
                cout << "Inorder Traversal: ";
                bst.inorder();
                break;
            case 5:
                cout << "Preorder Traversal: ";
                bst.preorder();
                break;
            case 6:
                cout << "Postorder Traversal: ";
                bst.postorder();
                break;
            case 7:
                bst.displayDepth();
                break;
            case 8:
                bst.displayMirror();
                break;
            case 9:
                {
                    BinarySearchTree* copiedTree = bst.copy();
                    cout << "Inorder Traversal of the copied tree: ";
                    copiedTree->inorder();
                    delete copiedTree;
                }
                break;
            case 10:
                bst.displayParentChild();
                break;
            case 11:
                bst.displayLeafNodes();
                break;
            case 12:
                bst.displayLevelOrder();
                break;
            case 13:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 13);

    return 0;
}
