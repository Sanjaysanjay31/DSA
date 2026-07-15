#include<bits/stdc++.h>
using namespace std;

// ==================== Node Structure ====================
struct node{
    int val;        // Stores data
    node* next;     // Stores address of next node

    // Constructor
    node(int v) : val(v), next(NULL) {}
};

// Head pointer
node* head = NULL;

// ==================== Length ====================
// Returns the number of nodes in the linked list
int length(node* head){

    int cnt = 0;

    while(head){
        cnt++;
        head = head->next;
    }

    return cnt;
}

// ==================== Insert at Head ====================
// Inserts a new node at the beginning of the list
void insert_at_head(node* &head, int val){

    node* temp = new node(val);

    temp->next = head;
    head = temp;
}

// ==================== Insert at Tail ====================
// Inserts a new node at the end of the list
void insert_at_tail(node* &head, int val){

    node* temp = new node(val);

    // If list is empty
    if(head == NULL){
        head = temp;
        return;
    }

    node* t = head;

    // Move to last node
    while(t->next){
        t = t->next;
    }

    t->next = temp;
}

// ==================== Insert at Position ====================
// Inserts a node at a given position
void insert_at_position(node* &head, int pos, int val){

    if(pos < 1 || pos > length(head) + 1){
        cout << "\nInvalid Position\n";
        return;
    }

    // Insert at beginning
    if(pos == 1){
        insert_at_head(head, val);
        return;
    }

    node* temp = head;

    // Move to node before required position
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }

    node* newNode = new node(val);

    newNode->next = temp->next;
    temp->next = newNode;
}

// ==================== Delete at Head ====================
// Deletes the first node
void delete_at_head(node* &head){

    if(head == NULL){
        cout << "\nLinked List is Empty\n";
        return;
    }

    node* temp = head;

    head = head->next;

    delete temp;
}

// ==================== Delete at Tail ====================
// Deletes the last node
void delete_at_tail(node* &head){

    if(head == NULL){
        cout << "\nLinked List is Empty\n";
        return;
    }

    // Only one node exists
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }

    node* temp = head;

    // Reach second last node
    while(temp->next->next){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// ==================== Delete at Position ====================
// Deletes node at a given position
void delete_at_position(node* &head, int pos){

    if(head == NULL){
        cout << "\nLinked List is Empty\n";
        return;
    }

    if(pos < 1 || pos > length(head)){
        cout << "\nInvalid Position\n";
        return;
    }

    if(pos == 1){
        delete_at_head(head);
        return;
    }

    node* temp = head;

    // Move to node before target node
    for(int i = 1; i < pos - 1; i++){
        temp = temp->next;
    }

    node* del = temp->next;

    temp->next = del->next;

    delete del;
}

// ==================== Search ====================
// Returns position of element if found, else -1
int search_element(node* head, int key){

    int pos = 1;

    while(head){

        if(head->val == key){
            return pos;
        }

        pos++;
        head = head->next;
    }

    return -1;
}

// ==================== Display Forward ====================
// Prints linked list from head to tail
void display_forward(node* head){

    if(head == NULL){
        cout << "\nLinked List is Empty\n";
        return;
    }

    cout << "\nLinked List (Head -> Tail): ";

    while(head){
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

// ==================== Display Backward ====================
// Prints linked list from tail to head using stack
void display_backward(node* head){

    if(head == NULL){
        cout << "\nLinked List is Empty\n";
        return;
    }

    stack<int> st;

    while(head){
        st.push(head->val);
        head = head->next;
    }

    cout << "\nLinked List (Tail -> Head): ";

    while(!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

// ==================== Main Function ====================
int main(){

    int choice, val, pos;

    while(true){

        cout << "\n\n========== LINKED LIST OPERATIONS ==========\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete at Head\n";
        cout << "5. Delete at Tail\n";
        cout << "6. Delete at Position\n";
        cout << "7. Search Element\n";
        cout << "8. Length of Linked List\n";
        cout << "9. Display Forward\n";
        cout << "10. Display Backward(Reverse)\n";
        cout << "11. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch(choice){

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
                cout << "Enter Position: ";
                cin >> pos;

                delete_at_position(head, pos);
                cout << "\nNode Deleted Successfully\n";
                break;

            case 7:
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

            case 8:
                cout << "\nLength of Linked List: " << length(head) << endl;
                break;

            case 9:
                display_forward(head);
                break;

            case 10:
                display_backward(head);
                break;
            case 11:
                cout << "\nExiting...\n";
                exit(0);
            default:
                cout << "\nInvalid Choice\n";
        }
    }

    return 0;
}
