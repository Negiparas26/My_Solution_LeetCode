#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Insert a node at the end (for creating a list)
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

// Delete a node from the beginning
void deleteFromBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
    cout << "Node deleted from the beginning." << endl;
}

// Delete a node from the end
void deleteFromEnd(Node*& head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        cout << "Node deleted from the end." << endl;
        return;
    }
    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    cout << "Node deleted from the end." << endl;
}

// Delete a node from a specified position
void deleteFromPosition(Node*& head, int position) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete!" << endl;
        return;
    }
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < position - 1; i++) {
        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of bounds!" << endl;
            return;
        }
        temp = temp->next;
    }
    if (temp->next == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;
    cout << "Node deleted from position " << position << "." << endl;
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
    Node* head = nullptr;
    int choice;

    do {
        cout << "\n--- Linked List Operations ---\n";
        cout << "1. Insert at End\n";
        cout << "2. Delete from Beginning\n";
        cout << "3. Delete from End\n";
        cout << "4. Delete from Specific Position\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter the value to insert at the end: ";
                cin >> data;
                insertAtEnd(head, data);
                break;
            }
            case 2:
                deleteFromBeginning(head);
                break;
            case 3:
                deleteFromEnd(head);
                break;
            case 4: {
                int position;
                cout << "Enter the position to delete: ";
                cin >> position;
                deleteFromPosition(head, position);
                break;
            }
            case 5:
                cout << "Current Linked List: ";
                displayList(head);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
