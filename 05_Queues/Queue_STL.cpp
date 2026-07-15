#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Creating a queue of integers
    queue<int> q;

    // 1. push(): Adds an element to the end of the queue
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    cout << "Queue elements after push: ";
    // To print a queue, we usually iterate and pop, 
    // but since we want to keep the queue for other demos, we'll use a copy
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    // 2. front(): Returns the element at the front of the queue
    cout << "Front element: " << q.front() << endl;

    // 3. back(): Returns the element at the end of the queue
    cout << "Back element: " << q.back() << endl;

    // 4. size(): Returns the number of elements in the queue
    cout << "Queue size: " << q.size() << endl;

    // 5. pop(): Removes the element from the front of the queue
    cout << "Popping front element..." << endl;
    q.pop();
    cout << "New front element: " << q.front() << endl;

    // 6. empty(): Checks if the queue is empty
    if (q.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    // Clearing the queue
    while (!q.empty()) {
        q.pop();
    }
    cout << "Queue cleared. Is empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
