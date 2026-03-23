# ***Max Heap Implementation***

- A Max Heap is a **complete binary tree** where the value
of each parent node is **greater than or equal to its children**.
- This program implements a **Max Heap** manually using a dynamic array
(`vector<int>`).
- The maximum element is always stored at the **root (index 0)**.

---

## Heap Representation

- The heap is stored in a vector `H`
- Index-based relationships:
  - Parent index: `(i - 1) / 2`
  - Left child: `2*i + 1`
  - Right child: `2*i + 2`

---

## heapifyUp (Insertion Adjustment)

`heapifyUp()` is used after inserting a new element.

### How it works:
- The new element is added at the end of the heap
- It is compared with its parent
- If the parent is smaller, they are swapped
- This continues until the heap property is restored

### Used in:
- `push()` operation

### Time Complexity:
- **O(log n)**

---

## push Operation

The `push()` function inserts a new element into the heap.

Steps:
1. Add element at the end of the vector
2. Call `heapifyUp()` to maintain Max Heap property

---

## heapifyDown (Deletion Adjustment)

`heapifyDown()` is used after deleting the root element.

### How it works:
- The last element is moved to the root
- It is compared with its children
- Swapped with the largest child if needed
- Process continues until heap property is restored

### Used in:
- `pop()` operation

### Time Complexity:
- **O(log n)**

---

## pop Operation

The `pop()` function removes the maximum element (root).

Steps:
1. Replace root with last element
2. Remove last element
3. Call `heapifyDown()` from root

---

## top Operation

- Returns the maximum element in the heap
- Does not remove the element
- Time Complexity: **O(1)**

---

## Empty Check

The `Empty()` function checks whether the heap is empty.

---


## Time Complexity Summary

| Operation | Time Complexity |
|---------|----------------|
| Insert (push) | O(log n) |
| Delete (pop) | O(log n) |
| Get Max (top) | O(1) |
| Build Heap (n inserts) | O(n log n) |

---


<details>
<summary><mark><b>Max_Heap Code Implementation</b><mark></summary>

```cpp
#include<bits/stdc++.h>   // Include all Standard Libraries
using namespace std;

// Structure representing a Max Heap
struct MaxHeap {

    vector<int> H;   // Dynamic array to store heap elements

    // Restore heap property after insertion (Heapify Up)
    void heapifyUp(int child) {
        while (child > 0) {
            int parent = (child - 1) / 2;

            // If parent is smaller than child, swap them
            if (H[parent] < H[child]) {
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
            int largest = idx;         // Assume current is largest

            // Compare with left child
            if (left < n && H[left] > H[largest])
                largest = left;

            // Compare with right child
            if (right < n && H[right] > H[largest])
                largest = right;

            // If largest is not current node, swap
            if (largest != idx) {
                swap(H[idx], H[largest]);
                idx = largest;         // Continue downwards
            } else {
                break;                 // Heap property restored
            }
        }
    }

    // Remove the maximum element (root)
    void pop() {
        if (H.empty()) return;         // If heap is empty

        // Move last element to root
        H[0] = H.back();
        H.pop_back();

        // Restore heap property
        heapifyDown(0);
    }

    // Return the maximum element
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
    // Initilize the size of the vector
    cout<<"\nEnter the size  :"; 
	cin>>n;
    vector<int> a(n);
    // Initilize the elements 
    cout<<"\nEnter the elements :";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    MaxHeap H1;     // Called an object Maxheap 

    // Insert elements into Max Heap
    for (int i = 0; i < n; i++) {
        H1.push(a[i]);
    }

    // Print elements in descending order
    while (!H1.Empty()) {
        cout << H1.top() << " ";
        H1.pop();
    }
    return 0;
}

```

</details>