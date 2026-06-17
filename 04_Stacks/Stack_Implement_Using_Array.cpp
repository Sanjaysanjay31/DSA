#include <bits/stdc++.h>
using namespace std;

// Stack Implementation Using Array
class Stack
{
private:
    static const int MAX_SIZE = 100;

    int arr[MAX_SIZE];   // Array to store stack elements
    int topIdx;          // Index of top element

public:

    // Constructor
    Stack()
    {
        topIdx = -1;
    }

    // Check if stack is empty
    bool isEmpty()
    {
        return topIdx == -1;
    }

    // Check if stack is full
    bool isFull()
    {
        return topIdx == MAX_SIZE - 1;
    }

    // Insert element into stack
    bool push(int x)
    {
        if (isFull())
            return false;

        arr[++topIdx] = x;
        return true;
    }

    // Remove top element
    bool pop()
    {
        if (isEmpty())
            return false;

        topIdx--;
        return true;
    }

    // Return top element
    int peek()
    {
        if (isEmpty())
            return -1;

        return arr[topIdx];
    }

    // Return current size of stack
    int size()
    {
        return topIdx + 1;
    }

    // Display stack from top to bottom
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Stack Elements (Top -> Bottom): ";

        for (int i = topIdx; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }

        cout << '\n';
    }
};

int main()
{
    Stack st;

    // Push elements
    st.push(10);
    st.push(20);
    st.push(30);

    // Display stack
    st.display();

    // Show top element
    cout << "Top Element : " << st.peek() << '\n';

    // Remove top element
    st.pop();

    // Display updated stack
    st.display();

    // Show current size
    cout << "Size : " << st.size() << '\n';

    // Check stack status
    if (st.isEmpty())
        cout << "Stack is Empty\n";
    else
        cout << "Stack is Not Empty\n";

    if (st.isFull())
        cout << "Stack is Full\n";
    else
        cout << "Stack is Not Full\n";

    return 0;
}