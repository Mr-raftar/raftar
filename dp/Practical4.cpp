#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

// Node structure for Expression Tree
struct Node {
    string data;
    Node* left;
    Node* right;
    
    Node(string val) : data(val), left(nullptr), right(nullptr) {}
};

// Class for Expression Tree
class ExpressionTree {
public:
    // Function to construct tree from postfix expression
    Node* constructFromPostfix(const string& postfix) {
        stack<Node*> stk;
        for (char ch : postfix) {
            if (isalnum(ch)) {
                stk.push(new Node(string(1, ch)));
            } else if (isOperator(ch)) {
                Node* right = stk.top(); stk.pop();
                Node* left = stk.top(); stk.pop();
                Node* root = new Node(string(1, ch));
                root->left = left;
                root->right = right;
                stk.push(root);
            }
        }
        return stk.top();
    }

    // Function to construct tree from prefix expression
    Node* constructFromPrefix(const string& prefix) {
        stack<Node*> stk;
        for (int i = prefix.length() - 1; i >= 0; --i) {
            char ch = prefix[i];
            if (isalnum(ch)) {
                stk.push(new Node(string(1, ch)));
            } else if (isOperator(ch)) {
                Node* left = stk.top(); stk.pop();
                Node* right = stk.top(); stk.pop();
                Node* root = new Node(string(1, ch));
                root->left = left;
                root->right = right;
                stk.push(root);
            }
        }
        return stk.top();
    }

    // Recursive In-order Traversal
    void inorderRecursive(Node* root) {
        if (root == nullptr) return;
        inorderRecursive(root->left);
        cout << root->data << " ";
        inorderRecursive(root->right);
    }

    // Non-recursive In-order Traversal (Iterative)
    void inorderNonRecursive(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stk;
        Node* current = root;
        while (current != nullptr || !stk.empty()) {
            while (current != nullptr) {
                stk.push(current);
                current = current->left;
            }
            current = stk.top(); stk.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    // Recursive Pre-order Traversal
    void preorderRecursive(Node* root) {
        if (root == nullptr) return;
        cout << root->data << " ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }

    // Non-recursive Pre-order Traversal (Iterative)
    void preorderNonRecursive(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stk;
        stk.push(root);
        while (!stk.empty()) {
            Node* node = stk.top(); stk.pop();
            cout << node->data << " ";
            if (node->right) stk.push(node->right);
            if (node->left) stk.push(node->left);
        }
    }

    // Recursive Post-order Traversal
    void postorderRecursive(Node* root) {
        if (root == nullptr) return;
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout << root->data << " ";
    }

    // Non-recursive Post-order Traversal (Iterative)
    void postorderNonRecursive(Node* root) {
        if (root == nullptr) return;
        stack<Node*> stk1, stk2;
        stk1.push(root);
        while (!stk1.empty()) {
            Node* node = stk1.top(); stk1.pop();
            stk2.push(node);
            if (node->left) stk1.push(node->left);
            if (node->right) stk1.push(node->right);
        }
        while (!stk2.empty()) {
            cout << stk2.top()->data << " ";
            stk2.pop();
        }
    }

private:
    bool isOperator(char ch) {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
};

int main() {
    ExpressionTree tree;
    string postfix, prefix;

    // Construct Expression Tree from Postfix expression
    cout << "Enter postfix expression: ";
    cin >> postfix;
    Node* rootPostfix = tree.constructFromPostfix(postfix);

    cout << "\nRecursive In-order traversal (Postfix): ";
    tree.inorderRecursive(rootPostfix);
    
    cout << "\nNon-recursive In-order traversal (Postfix): ";
    tree.inorderNonRecursive(rootPostfix);

    cout << "\nRecursive Pre-order traversal (Postfix): ";
    tree.preorderRecursive(rootPostfix);
    
    cout << "\nNon-recursive Pre-order traversal (Postfix): ";
    tree.preorderNonRecursive(rootPostfix);

    cout << "\nRecursive Post-order traversal (Postfix): ";
    tree.postorderRecursive(rootPostfix);
    
    cout << "\nNon-recursive Post-order traversal (Postfix): ";
    tree.postorderNonRecursive(rootPostfix);

    // Construct Expression Tree from Prefix expression
    cout << "\n\nEnter prefix expression: ";
    cin >> prefix;
    Node* rootPrefix = tree.constructFromPrefix(prefix);

    cout << "\nRecursive In-order traversal (Prefix): ";
    tree.inorderRecursive(rootPrefix);
    
    cout << "\nNon-recursive In-order traversal (Prefix): ";
    tree.inorderNonRecursive(rootPrefix);

    cout << "\nRecursive Pre-order traversal (Prefix): ";
    tree.preorderRecursive(rootPrefix);
    
    cout << "\nNon-recursive Pre-order traversal (Prefix): ";
    tree.preorderNonRecursive(rootPrefix);

    cout << "\nRecursive Post-order traversal (Prefix): ";
    tree.postorderRecursive(rootPrefix);
    
    cout << "\nNon-recursive Post-order traversal (Prefix): ";
    tree.postorderNonRecursive(rootPrefix);

    return 0;
}
