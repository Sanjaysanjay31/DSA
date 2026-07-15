#include <bits/stdc++.h>
using namespace std;

// Queue Implementation Using Array (Circular Queue)
class Queue
{
private:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int frontIdx;
    int rearIdx;
    int currentSize;

public:
    // Constructor
    Queue()
    {
        frontIdx = 0;
        rearIdx = -1;
        currentSize = 0;
    }

    // Check if queue is empty
    bool isEmpty()
    {
        return currentSize == 0;
    }

    // Check if queue is full
    bool isFull()
    {
        return currentSize == MAX_SIZE;
    }

    // Insert element at the rear
    bool enqueue(int x)
    {
        if (isFull())
        {
            cout << "Queue Overflow / Queue is Full";
            return false;
        }

        // Circular increment of rear index
        rearIdx = (rearIdx + 1) % MAX_SIZE;
        arr[rearIdx] = x;
        currentSize++;
        return true;
    }

    // Remove element from the front
    bool dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue Underflow / Queue is Empty";
            return false;
        }

        // Circular increment of front index
        frontIdx = (frontIdx + 1) % MAX_SIZE;
        currentSize--;
        return true;
    }

    // Return the front element
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[frontIdx];
    }

    // Return the rear element
    int rear()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return -1;
        }
        return arr[rearIdx];
    }

    // Return current size of queue
    int size()
    {
        return currentSize;
    }

    // Display queue elements from front to rear
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty";
            return;
        }

        cout << "Queue Elements (Front -> Rear): ";
        for (int i = 0; i < currentSize; i++)
        {
            int index = (frontIdx + i) % MAX_SIZE;
            cout << arr[index] << " ";
        }
        cout <<" ";
    }
};

int main()
{
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    q.display();

    cout << "Front element: " << q.front() << endl;
    cout << "Rear element: " << q.rear() << endl;

    // Dequeue elements
    q.dequeue();
    q.dequeue();

    cout << "After two dequeues:";
    q.display();

    cout << "Current size: " << q.size() << endl;

    return 0;
}
