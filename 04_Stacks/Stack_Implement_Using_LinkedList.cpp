#include<bits/stdc++.h>
using namespace std;

// Node structure for Linked List
struct node{
public:
    int val;        // Stores data
    node* next;     // Pointer to next node

    // Constructor
    node(int x){
        val = x;
        next = NULL;
    }
};

// Stack implementation using Linked List
class Stack{

public:

    node* topnode;   // Points to top element of stack

    // Constructor
    Stack(){
        topnode = NULL;
    }

    // Push element into stack
    void push(int v){

        // Create new node
        node* temp = new node(v);

        // New node points to current top
        temp->next = topnode;

        // Update top
        topnode = temp;
    }

    // Remove top element
    void pop(){

        // Check stack underflow
        if(isempty()){
            cout << "Stack Underflow / Stack Empty" << endl;
            return;
        }

        // Store current top
        node* temp = topnode;

        // Move top to next node
        topnode = topnode->next;

        // Free memory
        delete temp;
    }

    // Return top element
    int top(){

        // Check if stack is empty
        if(isempty()){
            cout << "Stack Underflow / Stack Empty" << endl;
            return -1;
        }

        return topnode->val;
    }

    // Check whether stack is empty
    bool isempty(){
        return topnode == NULL;
    }

    // Count number of elements in stack
    int size(){

        int count = 0;

        node* temp = topnode;

        while(temp){
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display all elements from top to bottom
    void display(){

        if(isempty()){
            cout << "Stack Underflow / Stack Empty" << endl;
            return;
        }

        node* temp = topnode;

        cout << "Elements in Stack : ";

        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main(){

    Stack st;

    // Push elements
    st.push(10);
    st.push(20);

    // Display stack
    st.display();

    // Print top element
    cout << "Top element is : " << st.top() << endl;

    // Check stack status
    if(st.isempty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;

    // Remove elements
    st.pop();
    st.pop();

    // Underflow case
    st.pop();

    // Check again
    if(st.isempty())
        cout << "Stack is Empty" << endl;
    else
        cout << "Stack is not Empty" << endl;

    // Push new element
    st.push(30);

    // Display stack
    st.display();

    // Print size
    cout << "Size of Stack : " << st.size() << endl;

    return 0;
}