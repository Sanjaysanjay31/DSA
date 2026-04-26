## Priority Queue – Overall Explanation

A **Priority Queue** is a special type of data structure where each element
is associated with a priority. Elements are accessed based on their
priority, not on the order of insertion.

The element with the **highest priority** is always removed first.

---

## Priority Queue Using Heap

In C++, a priority queue is implemented using a **heap** data structure.
ō
- By default, it uses a **Max-Heap**
- The highest value has the highest priority
- A **Min-Heap** can be created using a comparator

---

## Types of Priority Queue

### Max-Priority Queue
- Largest element has the highest priority
- Implemented using Max-Heap
- Default behavior in C++

### Min-Priority Queue
- Smallest element has the highest priority
- Implemented using Min-Heap
- Created using `greater<>` comparator

---

## Operations in Priority Queue

### Insertion (`push`)
- Element is inserted at the end
- **Heapify Up** is performed
- Restores heap property
- Time Complexity: **O(log n)**

### Deletion (`pop`)
- Removes the top priority element
- Last element moves to root
- **Heapify Down** is performed
- Time Complexity: **O(log n)**

### Access Top (`top`)
- Returns highest priority element
- Time Complexity: **O(1)**

---

## Heapify Operations

- **Heapify Up** → Used during insertion
- **Heapify Down** → Used during deletion


---

## Time Complexity Summary

| Operation | Time Complexity |
|---------|----------------|
| Insert | O(log n) |
| Delete | O(log n) |
| Top | O(1) |
| Build Heap | O(n) |

---

## Applications of Priority Queue

- CPU scheduling
- Dijkstra’s shortest path algorithm
- Heap sort
- Task scheduling systems
- Event-driven simulations

---

## Advantages

- Efficient access to highest priority element
- Better performance than sorting every time
- Suitable for dynamic data

---

## Conclusion

A priority queue is an efficient data structure for managing elements
based on priority. By using heapify operations, it guarantees fast
insertion, deletion, and access, making it widely used in real-world
applications.

---

<details>
<summary><b><mark>Priority_Queue_Implementation<b><mark></summary>

```cpp
#include<bits/stdc++.h>   // Include all Standard Libraries
using namespace std;

//print function 
void print(vector<int>& a) {
    for (int x : a) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int n;
    // Initilize the size of the queue
    cout<<"\nEnter the size of queue :"; 
	cin>>n;
    vector<int> a(n);
    // Initilize the elements 
    cout<<"\nEnter the elements :";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 1. Max-Heap (Descending)
    // Constructor-based initialization is O(n) - much faster than n insertions
    priority_queue<int> maxHeap(a.begin(), a.end());

    // Print the elements in Descending order
    cout << "Values in descending: ";
    while (!maxHeap.empty()) {
        cout << maxHeap.top() << " ";
        maxHeap.pop();
    }
    cout << endl;
 
    // 2. Min-Heap (Ascending)
    priority_queue<int, vector<int>, greater<int>> minHeap(a.begin(), a.end());

    // Print the elements in ascending order 
    cout << "Values in ascending: ";
    while (!minHeap.empty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    cout << endl;

    return 0;
}
```
</details>
