#include <bits/stdc++.h>
using namespace std;

// Node structure for Linked List
struct Node
{
    int val;        // Actual value stored in stack
    int mini;       // Minimum value till this node
    Node* next;     // Pointer to next node

    Node(int v)
    {
        val  = v;
        mini = INT_MAX;
        next = nullptr;
    }
};

// Min Stack Implementation Using Linked List
class MinStack
{
private:
    Node* topNode;   // Points to top of stack

public:

    // Constructor
    MinStack()
    {
        topNode = nullptr;
    }

    // Push element into stack
    void push(int value)
    {
        Node* temp = new Node(value);

        // First node case
        if (topNode == nullptr)
        {
            temp->mini = value;
        }
        else
        {
            // Store minimum till current node
            temp->mini = min(topNode->mini, value);
        }

        temp->next = topNode;
        topNode = temp;
    }

    // Remove top element
    void pop()
    {
        if (topNode == nullptr)
        {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;

        delete temp;
    }

    // Return top element
    int top()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return topNode->val;
    }

    // Return minimum element in O(1)
    int getMin()
    {
        if (topNode == nullptr)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return topNode->mini;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return topNode == nullptr;
    }

    // Display stack elements
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
            return;
        }

        Node* temp = topNode;

        cout << "Stack Elements (Top -> Bottom): ";

        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }

        cout << endl;
    }


};

int main()
{
    MinStack st;

    st.push(5);
    st.push(2);
    st.push(8);
    st.push(1);

    st.display();

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    st.pop();

    cout << "\nAfter Pop:" << endl;

    st.display();

    cout << "Top Element : " << st.top() << endl;
    cout << "Minimum Element : " << st.getMin() << endl;

    return 0;
}