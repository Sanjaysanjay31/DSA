# ***Min Heap***

- A **Min Heap** is a complete binary tree in which the value of each node is
**less than or equal to** the values of its children.

- This property ensures that the **minimum element is always present at the root**.

---

## Properties of Min Heap

- It is a **complete binary tree**
- Root node contains the **smallest element**
- Left and right subtrees are also Min Heaps
- Stored efficiently using an **array (vector)**

---

## Array Representation

For a node at index `i`:
- Left child  → `2*i + 1`
- Right child → `2*i + 2`
- Parent      → `(i - 1) / 2`

---

## Heap Operations

### Insertion (Heapify Up)

1. Insert the element at the end of the heap
2. Compare it with its parent
3. If parent is greater, swap them
4. Repeat until Min Heap property is restored

**Time Complexity:** `O(log n)`

---

### Deletion (Heapify Down)

1. Remove the root element (minimum)
2. Move the last element to the root
3. Compare it with its children
4. Swap with the smaller child
5. Repeat until heap property is restored

**Time Complexity:** `O(log n)`

---

### Access Minimum Element

- The minimum element is always at the root
- Access time is constant

**Time Complexity:** `O(1)`

---

## Heapify Operations

- **Heapify Up** → Used during insertion
- **Heapify Down** → Used during deletion

These operations maintain the Min Heap property.

---

## Applications of Min Heap

- Priority Queue implementation
- Dijkstra’s shortest path algorithm
- Job scheduling systems
- Event-driven simulations
- Finding minimum element efficiently

---

## Advantages

- Fast access to minimum element
- Efficient insertion and deletion
- Uses array-based storage (no pointers)

---

<details>
<summary><mark><b>Min_Heap Code Implementation</b><mark></summary>

```cpp
#include<bits/stdc++.h>   // Include all Standard Libraries
using namespace std;

// Structure representing a Min Heap
struct MinHeap {

    vector<int> H;   // Dynamic array to store heap elements

    // Restore heap property after insertion (Heapify Up)
    void heapifyUp(int child) {
        while (child > 0) {
            int parent = (child - 1) / 2;

            // If parent is greater than child, swap them
            if (H[parent] > H[child]) {
                swap(H[parent], H[child]);
                child = parent;
            } else {
                break;  // Heap property satisfied
            }
        }
    }

    // Insert a new value into the heap
    void push(int val) {
        H.push_back(val);              // Insert at the end
        int idx = H.size() - 1;        // Index of new element
        heapifyUp(idx);                // Fix heap property
    }

    // Restore heap property after deletion (Heapify Down)
    void heapifyDown(int idx) {
        int n = H.size();

        while (idx < n) {
            int left = 2 * idx + 1;    // Left child index
            int right = 2 * idx + 2;   // Right child index
            int smallest = idx;        // Assume current is smallest

            // Compare with left child
            if (left < n && H[left] < H[smallest])
                smallest = left;

            // Compare with right child
            if (right < n && H[right] < H[smallest])
                smallest = right;

            // If smallest is not current node, swap
            if (smallest != idx) {
                swap(H[idx], H[smallest]);
                idx = smallest;        // Continue downwards
            } else {
                break;                 // Heap property restored
            }
        }
    }

    // Remove the minimum element (root)
    void pop() {
        if (H.empty()) return;         // If heap is empty

        // Move last element to root
        H[0] = H.back();
        H.pop_back();

        // Restore heap property
        heapifyDown(0);
    }

    // Return the minimum element
    int top() {
        if (H.empty()) return -1;
        return H[0];
    }

    // Check if heap is empty
    bool Empty() {
        return H.empty();
    }
};

int main() {
    int n;
    // Initialize the size of the vector
    cout << "\nEnter the size  :";
    cin >> n;

    vector<int> a(n);
    // Initialize the elements
    cout << "\nEnter the elements :";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MinHeap H1;     // Called an object MinHeap

    // Insert elements into Min Heap
    for (int i = 0; i < n; i++) {
        H1.push(a[i]);
    }

    // Print elements in ascending order
    while (!H1.Empty()) {
        cout << H1.top() << " ";
        H1.pop();
    }
    return 0;
}

```
</details>

