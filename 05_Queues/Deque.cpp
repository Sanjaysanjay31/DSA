#include <bits/stdc++.h>
using namespace std;

// Node structure for Doubly Linked List
struct node
{
    int val;
    node* next;
    node* prev;

    // Constructor
    node(int v) : val(v), next(NULL), prev(NULL) {}
};

// Deque (Double-Ended Queue) implementation using Doubly Linked List
class Deque
{
private:
    node* frontNode;
    node* rearNode;
    int currentSize;

public:
    // Constructor
    Deque()
    {
        frontNode = NULL;
        rearNode = NULL;
        currentSize = 0;
    }

    // Insert at the front
    void insertFront(int v)
    {
        node* temp = new node(v);

        if (isEmpty())
        {
            frontNode = rearNode = temp;
        }
        else
        {
            temp->next = frontNode;
            frontNode->prev = temp;
            frontNode = temp;
        }
        currentSize++;
    }

    // Insert at the rear
    void insertRear(int v)
    {
        node* temp = new node(v);

        if (isEmpty())
        {
            frontNode = rearNode = temp;
        }
        else
        {
            temp->prev = rearNode;
            rearNode->next = temp;
            rearNode = temp;
        }
        currentSize++;
    }

    // Delete from the front
    void deleteFront()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow / Deque Empty" << endl;
            return;
        }

        node* temp = frontNode;
        frontNode = frontNode->next;

        if (frontNode == NULL)
        {
            rearNode = NULL;
        }
        else
        {
            frontNode->prev = NULL;
        }

        delete temp;
        currentSize--;
    }

    // Delete from the rear
    void deleteRear()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow / Deque Empty" << endl;
            return;
        }

        node* temp = rearNode;
        rearNode = rearNode->prev;

        if (rearNode == NULL)
        {
            frontNode = NULL;
        }
        else
        {
            rearNode->next = NULL;
        }

        delete temp;
        currentSize--;
    }

    // Get front element
    int getFront()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return frontNode->val;
    }

    // Get rear element
    int getRear()
    {
        if (isEmpty())
        {
            cout << "Deque is Empty" << endl;
            return -1;
        }
        return rearNode->val;
    }

    // Check whether deque is empty
    bool isEmpty()
    {
        return frontNode == NULL;
    }

    // Return current size of deque
    int size()
    {
        return currentSize;
    }

    // Display all elements from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Deque Underflow / Deque Empty" << endl;
            return;
        }

        node* temp = frontNode;
        cout << "Deque Elements (Front -> Rear): ";
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
    Deque dq;

    // Insertions
    dq.insertRear(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertFront(1);

    dq.display(); // Expected: 1 5 10 20

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    // Deletions
    dq.deleteFront();
    dq.deleteRear();

    cout << "After deleteFront and deleteRear:";
    dq.display(); // Expected: 5 10

    cout << "Final Size: " << dq.size() << endl;

    return 0;
}
