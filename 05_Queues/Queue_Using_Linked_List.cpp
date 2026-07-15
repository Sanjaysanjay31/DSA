#include <bits/stdc++.h>
using namespace std;

// Node structure for Linked List
struct node
{
public:
    int val;
    node* next;

    // Constructor
    node(int x)
    {
        val = x;
        next = NULL;
    }
};

// Queue implementation using Linked List
class Queue
{
private:
    node* frontNode;
    node* rearNode;
    int currentSize;

public:
    // Constructor
    Queue()
    {
        frontNode = NULL;
        rearNode = NULL;
        currentSize = 0;
    }

    // Insert element into queue (at rear)
    void enqueue(int v)
    {
        node* temp = new node(v);

        if (isEmpty())
        {
            frontNode = rearNode = temp;
        }
        else
        {
            rearNode->next = temp;
            rearNode = temp;
        }
        currentSize++;
    }

    // Remove element from queue (from front)
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow / Queue Empty" << endl;
            return;
        }

        node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == NULL)
        {
            rearNode = NULL;
        }

        delete temp;
        currentSize--;
    }

    // Return front element
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return frontNode->val;
    }

    // Return rear element
    int rear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
            return -1;
        }
        return rearNode->val;
    }

    // Check whether queue is empty
    bool isEmpty()
    {
        return frontNode == NULL;
    }

    // Count number of elements in queue
    int size()
    {
        return currentSize;
    }

    // Display all elements from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow / Queue Empty" << endl;
            return;
        }

        node* temp = frontNode;
        cout << "Queue Elements (Front -> Rear): ";
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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front: " << q.front() << endl;
    cout << "Rear: " << q.rear() << endl;

    q.dequeue();
    q.dequeue();

    cout << "After two dequeues:";
    q.display();

    cout << "Size: " << q.size() << endl;

    return 0;
}
