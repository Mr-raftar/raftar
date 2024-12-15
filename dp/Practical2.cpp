#include <iostream>
#include <string>
#include <stack>
#include <cctype>
#include <cmath>
using namespace std;

// Node structure for singly linked list
struct Node {
    char data;
    Node* next;
};

// Stack implementation using linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    void push(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            throw runtime_error("Stack Underflow");
        }
        char value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    char peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

// Utility functions
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
}

string infixToPostfix(const string& infix) {
    Stack stack;
    string postfix = "";

    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else if (isOperator(ch)) {
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                postfix += stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.pop();
    }

    return postfix;
}

string infixToPrefix(const string& infix) {
    string reversedInfix = string(infix.rbegin(), infix.rend());
    for (char& ch : reversedInfix) {
        if (ch == '(') ch = ')';
        else if (ch == ')') ch = '(';
    }

    string reversedPrefix = infixToPostfix(reversedInfix);
    return string(reversedPrefix.rbegin(), reversedPrefix.rend());
}

int evaluatePostfix(const string& postfix) {
    stack<int> stack;

    for (char ch : postfix) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else if (isOperator(ch)) {
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            switch (ch) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                case '^': stack.push(pow(a, b)); break;
            }
        }
    }

    return stack.top();
}

int evaluatePrefix(const string& prefix) {
    stack<int> stack;
    for (auto it = prefix.rbegin(); it != prefix.rend(); ++it) {
        char ch = *it;
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else if (isOperator(ch)) {
            int a = stack.top(); stack.pop();
            int b = stack.top(); stack.pop();
            switch (ch) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(a / b); break;
                case '^': stack.push(pow(a, b)); break;
            }
        }
    }

    return stack.top();
}

// Main function
int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix: " << postfix << endl;

    string prefix = infixToPrefix(infix);
    cout << "Prefix: " << prefix << endl;

    cout << "Evaluating Postfix: " << evaluatePostfix(postfix) << endl;
    cout << "Evaluating Prefix: " << evaluatePrefix(prefix) << endl;

    return 0;
}
