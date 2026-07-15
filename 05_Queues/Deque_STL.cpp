#include <iostream>
#include <deque>

using namespace std;

int main() {
    // Creating a deque of integers
    deque<int> dq;

    // 1. push_back(): Adds an element to the end of the deque
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    cout << "Deque after push_back: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 2. push_front(): Adds an element to the front of the deque
    dq.push_front(5);
    dq.push_front(1);

    cout << "Deque after push_front: ";
    for (int x : dq) {
        cout << x << " ";
    }
    cout << endl;

    // 3. front(): Returns the element at the front
    cout << "Front element: " << dq.front() << endl;

    // 4. back(): Returns the element at the end
    cout << "Back element: " << dq.back() << endl;

    // 5. pop_front(): Removes the element from the front
    cout << "Popping front..." << endl;
    dq.pop_front();
    cout << "New front: " << dq.front() << endl;

    // 6. pop_back(): Removes the element from the end
    cout << "Popping back..." << endl;
    dq.pop_back();
    cout << "New back: " << dq.back() << endl;

    // 7. size(): Returns the number of elements
    cout << "Deque size: " << dq.size() << endl;

    // 8. empty(): Checks if the deque is empty
    if (dq.empty()) {
        cout << "Deque is empty" << endl;
    } else {
        cout << "Deque is not empty" << endl;
    }

    // 9. at() or operator[]: Access element at a specific index
    cout << "Element at index 1: " << dq[1] << endl;

    return 0;
}
