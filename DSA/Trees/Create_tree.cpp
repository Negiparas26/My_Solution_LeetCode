#include<iostream>
#include<queue>
using namespace std;

struct Node {
    int data;      // To store the value of the node
    Node* left;    // Pointer to the left child
    Node* right;   // Pointer to the right child

    // Constructor to initialize a node with a value
    Node(int value) {
        data = value;
        left = nullptr; // No left child initially
        right = nullptr; // No right child initially
    }
};

int main(){
    int value;
cout << "Enter root value: ";
cin >> value;
Node* root = new Node(value);
queue<Node*> q;
q.push(root);

while (!q.empty()) {
    Node* current = q.front(); // Get the node at the front of the queue
    q.pop();                   // Remove it from the queue

    int leftValue, rightValue;
    cout << "Enter left child of " << current->data << " (-1 for no child): ";
    cin >> leftValue;
    if (leftValue != -1) { // If the user enters a valid value
        current->left = new Node(leftValue); // Create the left child
        q.push(current->left); // Add the left child to the queue
    }

    cout << "Enter right child of " << current->data << " (-1 for no child): ";
    cin >> rightValue;
    if (rightValue != -1) { // If the user enters a valid value
        current->right = new Node(rightValue); // Create the right child
        q.push(current->right); // Add the right child to the queue
    }
}



}