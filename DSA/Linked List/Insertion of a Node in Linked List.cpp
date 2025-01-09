#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Insert a node at the beginning
void insertAtBeginning(Node*& head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
}

// Insert a node at the end
void insertAtEnd(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert a node at a specified position
void insertAtPosition(Node*& head, int data, int position) {
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Display the linked list
void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr; // Initialize an empty linked list
    int choice;

    do {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Specific Position\n";
        cout << "4. Display List\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the value to insert at the beginning: ";
                cin >> data;
                insertAtBeginning(head, data);
                break;
            }
            case 2: {
                int data;
                cout << "Enter the value to insert at the end: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            }
            case 3: {
                int data, position;
                cout << "Enter the value to insert: ";
                cin >> data;
                cout << "Enter the position to insert the value: ";
                cin >> position;
                insertAtPosition(head, data, position);
                break;
            }
            case 4:
                cout << "Current Linked List: ";
                displayList(head);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
