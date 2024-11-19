#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    char data;
    Node* next;
};

// Function to create a linked list from the input string
Node* createLinkedList(const string& str) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (char c : str) {
        Node* newNode = new Node{c, nullptr};
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

// Function to free the memory of the linked list
void deleteLinkedList(Node* head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// DFA simulation function
bool isAccepted(Node* head) {
    bool state = false; // false = q0, true = q1
    Node* current = head;

    while (current) {
        if (current->data == '1') {
            state = !state; // Toggle state on '1'
        } else if (current->data == '0') {
            // Remain in the same state
        } else {
            // Reject if input is invalid
            return false;
        }
        current = current->next;
    }
    return state; // Accept if state is q1 (true)
}

int main() {
    string input;

    // Get binary string input
    cout << "Enter a binary string: ";
    cin >> input;

    // Check if input contains only '0' or '1'
    for (char c : input) {
        if (c != '0' && c != '1') {
            cout << "Invalid input! Only binary strings (0s and 1s) are allowed." << endl;
            return 0;
        }
    }

    // Create linked list
    Node* head = createLinkedList(input);

    // Check if the string is accepted or rejected
    if (isAccepted(head)) {
        cout << "The string is ACCEPTED." << endl;
    } else {
        cout << "The string is REJECTED." << endl;
    }

    // Free linked list memory
    deleteLinkedList(head);

    return 0;
}
