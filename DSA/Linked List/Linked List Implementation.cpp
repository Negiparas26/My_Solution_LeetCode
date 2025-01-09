#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {          //[_|_] node
    Node* newNode = new Node(); // Allocate memory for a new node
    newNode->data = data;       // Assign data to the new node
    newNode->next = nullptr;    // Initialize next as nullptr
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertNode(Node*& head, int data) {
    Node* newNode = createNode(data); // Create a new node
    if (head == nullptr) {            // If the list is empty
        head = newNode;               // The new node becomes the head
        return;
    }
    // Traverse to the end of the list
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode; // Attach the new node at the end
}

// Function to display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head; // Start from the head
    while (temp != nullptr) {
        cout << temp->data << " -> "; // Print the data
        temp = temp->next;           // Move to the next node
    }
    cout << "NULL" << endl; // Indicate the end of the list
}

int main() {
    Node* head = nullptr; // Initialize the head of the list as nullptr

    // Insert elements into the linked list
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 40);

    // Display the linked list
    cout << "Linked List: ";
    displayList(head);

    return 0;
}
