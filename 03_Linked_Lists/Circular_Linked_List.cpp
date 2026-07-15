#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Circular Linked List Node
// ======================================================
struct node {
    int val;
    node* next;

    node(int v) : val(v), next(nullptr) {}
};

node* head = nullptr;

// ======================================================
// Helper: Calculate Length
// ======================================================
int length(node* head) {
    if (head == nullptr) return 0;
    
    int cnt = 0;
    node* temp = head;
    
    do {
        cnt++;
        temp = temp->next;
    } while (temp != head);
    
    return cnt;
}

// ======================================================
// Insert at Head
// ======================================================
void insert_at_head(node* &head, int val) {
    node* newnode = new node(val);
    
    if (head == nullptr) {
        newnode->next = newnode; // Point to itself to form a circle
        head = newnode;
        return;
    }
    
    // Traverse to the last node to update the circular link
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    newnode->next = head;
    temp->next = newnode; // Last node must now point to new head
    head = newnode;
}

// ======================================================
// Insert at Tail
// ======================================================
void insert_at_tail(node* &head, int val) {
    node* newnode = new node(val);
    
    if (head == nullptr) {
        newnode->next = newnode;
        head = newnode;
        return;
    }
    
    // Traverse to find the current tail
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    temp->next = newnode; // Old tail points to new node
    newnode->next = head; // New node points to head to maintain circularity
}

// ======================================================
// Insert at Position
// ======================================================
void insert_at_position(node* &head, int pos, int val) {
    int len = length(head);
    
    if (pos < 1 || pos > len + 1) {
        cout << "\nInvalid Position\n";
        return;
    }
    
    if (pos == 1) {
        insert_at_head(head, val);
        return;
    }
    
    if (pos == len + 1) {
        insert_at_tail(head, val);
        return;
    }

    node* temp = head;
    // Move to the node right before the insertion point
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    
    node* newnode = new node(val);
    newnode->next = temp->next;
    temp->next = newnode; // Standard insertion between two nodes
}

// ======================================================
// Delete at Head
// ======================================================
void delete_at_head(node* &head) {
    if (head == nullptr) {
        cout << "\nLinked List is Empty\n";
        return;
    }
    
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    
    // Need to find the last node to update its 'next' pointer
    node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    
    node* toDelete = head;
    head = head->next;
    temp->next = head; // New head needs to be linked from last node
    
    delete toDelete;
}

// ======================================================
// Delete at Tail
// ======================================================
void delete_at_tail(node* &head) {
    if (head == nullptr) {
        cout << "\nLinked List is Empty\n";
        return;
    }
    
    if (head->next == head) {
        delete head;
        head = nullptr;
        return;
    }
    
    // Need the second last node to make it the new tail
    node* temp = head;
    while (temp->next->next != head) {
        temp = temp->next;
    }
    
    node* toDelete = temp->next;
    temp->next = head; // New tail must point back to head
    
    delete toDelete;
}

// ======================================================
// Display
// ======================================================
void display(node* head) {
    if (head == nullptr) {
        cout << "\nLinked List is Empty\n";
        return;
    }
    
    node* temp = head;
    cout << "\nCircular Linked List : ";
    
    do {
        cout << temp->val << " ";
        temp = temp->next;
    } while (temp != head);
    
    cout << endl;
}

// ======================================================
// Main Function
// ======================================================
int main() {
    int choice, val, pos;

    while (true) {
        cout << "\n\n========== CIRCULAR LINKED LIST ==========\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Length of Linked List\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Value: ";
                cin >> val;
                insert_at_head(head, val);
                break;
            case 2:
                cout << "Enter Value: ";
                cin >> val;
                insert_at_tail(head, val);
                break;
            case 3:
                cout << "Enter Position: ";
                cin >> pos;
                cout << "Enter Value: ";
                cin >> val;
                insert_at_position(head, pos, val);
                break;
            case 4:
                delete_at_head(head);
                cout << "\nNode Deleted Successfully\n";
                break;
            case 5:
                delete_at_tail(head);
                cout << "\nNode Deleted Successfully\n";
                break;
            case 6:
                cout << "\nLength of Linked List: " << length(head) << endl;
                break;
            case 7:
                display(head);
                break;
            case 8:
                cout << "\nExiting...\n";
                return 0;
            default:
                cout << "\nInvalid Choice\n";
        }
    }
    return 0;
}
