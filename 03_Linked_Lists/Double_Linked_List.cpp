#include<bits/stdc++.h>
using namespace std;

// ======================================================
// Doubly Linked List Node
// ======================================================
struct node{
    node* prev;     // Points to previous node
    int val;        // Stores data
    node* next;     // Points to next node

    // Constructor
    node(int v) : prev(nullptr), val(v), next(nullptr) {}
};

// Head and Tail pointers
node* head = nullptr;
node* tail = nullptr;

// ======================================================
// Returns length of Doubly Linked List
// ======================================================
int length(node* head){

    int cnt = 0;

    while(head){
        cnt++;
        head = head->next;
    }

    return cnt;
}

// ======================================================
// Insert at Head
// ======================================================
void insert_at_head(node* &head, node* &tail, int val){

    node* newnode = new node(val);

    // If list is empty
    if(head == nullptr){
        head = tail = newnode;
        return;
    }

    newnode->next = head;
    head->prev = newnode;

    head = newnode;
}

// ======================================================
// Insert at Tail
// ======================================================
void insert_at_tail(node* &head, node* &tail, int val){

    node* newnode = new node(val);

    // If list is empty
    if(tail == nullptr){
        head = tail = newnode;
        return;
    }

    newnode->prev = tail;
    tail->next = newnode;

    tail = newnode;
}

// ======================================================
// Insert at Position
// ======================================================
void insert_at_position(node* &head, int pos, int val){

    if(pos < 1 || pos > length(head) + 1){
        cout << "\nInvalid Position";
        return;
    }

    if(pos == 1){
        insert_at_head(head, tail, val);
        return;
    }

    if(pos == length(head) + 1){
        insert_at_tail(head, tail, val);
        return;
    }

    node* temp = head;

    // Move to node before insertion position
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }

    node* newnode = new node(val);

    newnode->next = temp->next;
    newnode->prev = temp;

    temp->next->prev = newnode;
    temp->next = newnode;
}


// ======================================================
// Insert a node after a given value
// ======================================================
void insert_after_value(node* &head,
                        node* &tail,
                        int target,
                        int value){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    node* temp = head;

    while(temp){

        if(temp->val == target){

            // Insert after last node
            if(temp == tail){
                insert_at_tail(head, tail, value);
                return;
            }

            node* newnode = new node(value);

            newnode->next = temp->next;
            newnode->prev = temp;

            temp->next->prev = newnode;
            temp->next = newnode;

            cout << "\nNode Inserted Successfully";
            return;
        }

        temp = temp->next;
    }

    cout << "\nTarget Value Not Found";
}


// ======================================================
// Delete at Head
// ======================================================
void delete_at_head(node* &head, node* &tail){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    // Only one node exists
    if(head == tail){

        delete head;

        head = nullptr;
        tail = nullptr;

        return;
    }

    node* temp = head;

    head = head->next;
    head->prev = nullptr;

    delete temp;
}

// ======================================================
// Delete at Tail
// ======================================================
void delete_at_tail(node* &head, node* &tail){

    if(tail == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    // Only one node exists
    if(head == tail){

        delete tail;

        head = nullptr;
        tail = nullptr;

        return;
    }

    node* temp = tail;

    tail = tail->prev;
    tail->next = nullptr;

    delete temp;
}

// ======================================================
// Delete at Position
// ======================================================
void delete_at_position(node* &head, node* &tail, int pos){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    if(pos < 1 || pos > length(head)){
        cout << "\nInvalid Position";
        return;
    }

    if(pos == 1){
        delete_at_head(head, tail);
        return;
    }

    if(pos == length(head)){
        delete_at_tail(head, tail);
        return;
    }

    node* temp = head;

    // Move to target node
    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }

    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    delete temp;
}


// ======================================================
// Delete first occurrence of a value
// ======================================================
void delete_by_value(node* &head, node* &tail, int key){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    node* temp = head;

    while(temp){

        if(temp->val == key){

            // First node
            if(temp == head){
                delete_at_head(head, tail);
                return;
            }

            // Last node
            if(temp == tail){
                delete_at_tail(head, tail);
                return;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            delete temp;

            cout << "\nNode Deleted Successfully";
            return;
        }

        temp = temp->next;
    }

    cout << "\nValue Not Found";
}


// ======================================================
// Search Element
// Returns Position if found else -1
// ======================================================
int search_element(node* head, int key){

    int pos = 1;

    while(head){

        if(head->val == key)
            return pos;

        head = head->next;
        pos++;
    }

    return -1;
}


// ======================================================
// Update value at a given position
// ======================================================
void update_value(node* head, int pos, int newVal){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    if(pos < 1 || pos > length(head)){
        cout << "\nInvalid Position";
        return;
    }

    node* temp = head;

    // Move to required position
    for(int i = 1; i < pos; i++){
        temp = temp->next;
    }

    temp->val = newVal;

    cout << "\nValue Updated Successfully";
}





// ======================================================
// Display Forward (Head -> Tail)
// ======================================================
void display_forward(node* head){

    if(head == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    cout << "\nHead -> Tail : ";

    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// ======================================================
// Display Backward (Tail -> Head)
// ======================================================
void display_backward(node* tail){

    if(tail == nullptr){
        cout << "\nLinked List is Empty.";
        return;
    }

    cout << "\nTail -> Head : ";

    while(tail){
        cout << tail->val << " ";
        tail = tail->prev;
    }

    cout << endl;
}

// ======================================================
// Main Function
// ======================================================
int main(){

    int choice, val, pos;

    while(true){

        cout << "\n\n========== DOUBLY LINKED LIST ==========\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Insert after a Value\n";
        cout << "5. Delete at Head\n";
        cout << "6. Delete at Tail\n";
        cout << "7. Delete at Position\n";
        cout << "8. Delete by Value\n";
        cout << "9. Search Element\n";
        cout << "10. Length of Linked List\n";
        cout << "11. Update Value at Position\n";
        cout << "12. Display Forward\n";
        cout << "13. Display Backward(Reverse)\n";
        cout << "14. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice){

            case 1:
                cout << "Enter Value: ";
                cin >> val;
                insert_at_head(head, tail, val);
                break;

            case 2:
                cout << "Enter Value: ";
                cin >> val;
                insert_at_tail(head, tail, val);
                break;

            case 3:
                cout << "Enter Position: ";
                cin >> pos;

                cout << "Enter Value: ";
                cin >> val;

                insert_at_position(head, pos, val);
                break;

            case 4:
                int target, value;

                cout << "Enter Target Value: ";
                cin >> target;

                cout << "Enter New Value: ";
                cin >> value;

                insert_after_value(head, tail, target, value);

                break;

            case 5:
                delete_at_head(head, tail);
                cout << "\nNode Deleted Successfully\n";
                break;

            case 6:
                delete_at_tail(head, tail);
                cout << "\nNode Deleted Successfully\n";
                break;

            case 7:
                cout << "Enter Position: ";
                cin >> pos;

                delete_at_position(head, tail, pos);
                cout << "\nNode Deleted Successfully\n";
                break;
            
            case 8:
                {
                    int key;

                    cout << "Enter Value to Delete: ";
                    cin >> key;

                    delete_by_value(head, tail, key);

                    break;
                }

            case 9:
            {
                cout << "Enter Element to Search: ";
                cin >> val;

                int res = search_element(head, val);

                if(res == -1)
                    cout << "\nElement Not Found\n";
                else
                    cout << "\nElement Found at Position: " << res << endl;

                break;
            }

            case 10:
                cout << "\nLength of Linked List: "
                     << length(head) << endl;
                break;

            case 11:
                {
                    int newVal;

                    cout << "Enter Position: ";
                    cin >> pos;

                    cout << "Enter New Value: ";
                    cin >> newVal;

                    update_value(head, pos, newVal);

                    break;
                }

            case 12:
                display_forward(head);
                break;

            case 13:
                display_backward(tail);
                break;

            case 14:
                cout << "\nExiting...\n";
                return 0;

            default:
                cout << "\nInvalid Choice\n";
        }
    }

    return 0;
}

