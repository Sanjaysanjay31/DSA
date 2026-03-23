# ***Array Left Rotation***
## **Approach 1 — Using Temporary Array (Extra Space)**

### Idea :
1. Store elements from index `k` to end in a temporary array.
2. Then append the first `k` elements.
3. Copy back into the original array.

### Steps :
1. Reduce rotations using `k = k % n`.
2. Copy elements from `k` to `n-1`.
3. Copy first `k` elements to the end.
4. Copy result back.

### Complexity : 
- Time Complexity: **O(n)**
- Space Complexity: **O(n)** (extra array used)

--- 
## **Approach 2 : Using Reverse Function With No Extraa space**
### Idea :
The array is divided into two parts:

- First part: first `k` elements
- Second part: remaining elements

To achieve the rotated result, the second part must come before the first part. This rearrangement is done using a sequence of reversals.

---

### Steps :
The algorithm performs three reversal operations:

1. Reverse the first `k` elements.
2. Reverse the remaining elements.
3. Reverse the entire array.

After these operations, the array elements appear in the correct left-rotated order.

### Complexity :
- Time Complexity: **O(n)**
- Space Complexity: **O(1)**

---

<details>
<summary><mark><b>Array_Left_Rotation Code implementation</b></mark></summary>

```cpp
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// Function to rotate the array to the LEFT by k positions
// Approach 1
void Left_Rotation(vector<int> &a, int k) {
    
    int n = a.size();     // Size of the array

    // If k is greater than array size, rotating n times gives the same array,
    // so we reduce k using modulo
    k = k % n;

    vector<int> t(n);     // Temporary array to store rotated elements

    // Copy elements from index k to n-1 into the beginning of temp array
    for (int i = 0; i < n - k; i++) {
        t[i] = a[k + i];
    }

    // Copy first k elements of original array to the end of temp array
    for (int i = 0; i < k; i++) {
        t[n - k + i] = a[i];
    }

    // Copy all elements from temp array back to original array
    for (int i = 0; i < n; i++) {
        a[i] = t[i];
    }
}

// Left Rotation with No Extra Spaces 
// Approach 2
void Left_Reverse_Rotation(vector<int> &a, int k) {
    // If k is greater than array size, rotating n times gives the same array,
    // so we reduce k using modulo
    k = k % a.size();

    // Reverse the first k elements (index 0 to k-1)
    reverse(a.begin(), a.begin() + k);

    // Reverse the remaining elements (index k to n-1)
    reverse(a.begin() + k, a.end());

    // Reverse the entire array to get the final rotated array
    reverse(a.begin(), a.end());
}

int main() {

    int n, r;

    // Input: size of the array
    cout << "\nEnter the size of array : ";
    cin >> n;

    // Input: number of rotations
    cout << "\nEnter the No.of Rotation performed : ";
    cin >> r;

    vector<int> a(n);    // Declare array of size n

    // Input: array elements
    cout << "\nEnter the elements : ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Call rotation function
    Left_Reverse_Rotation(a, r);

    // Output: rotated array
    cout << "\nAfter r rotation the array is : ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

```
</details>