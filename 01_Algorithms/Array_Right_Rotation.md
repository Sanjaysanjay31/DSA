# ***Array Right Rotation***

## **Approach 1 — Using Temporary Array (Extra Space)**

### Idea :
- Right rotation shifts elements to the right by `k` positions.  
- The last `k` elements move to the front, and the remaining elements shift right.

### Steps :
1. Reduce unnecessary rotations using:
2. Copy the last `k` elements of the array into the beginning of a temporary array.
3. Copy the remaining `n - k` elements after them.
4. Copy the temporary array back to the original array.

### Complexity : 
- Time Complexity: **O(n)**
- Space Complexity: **O(n)** (extra array used)

--- 
## **Approach 2 : Using Reverse Technique With No Extraa space**
### Idea :
The array is divided into two parts:
- First part: Last `k` elements
- Second part: remaining elements

To achieve the rotated result, the second part must come before the first part. This rearrangement is done using a sequence of reversals.


---

### Steps :
The algorithm performs three reversal operations:

1. Reversing the entire array
2. Reversing the first `k` elements
3. Reversing the remaining elements

This rearranges elements into the correct right-rotated order without extra memory.


### Complexity :
- Time Complexity: **O(n)**
- Space Complexity: **O(1)**

---

<details>
<summary><mark><b>Array_Left_Rotation Code implementation__</mark></b></summary>

```cpp
#include <bits/stdc++.h> // includes all Standard c++ Libraries 
using namespace std;

// Right rotation using extra space
// Approach 1
void Right_Rotation(vector<int>& a, int k) {
    int n = a.size(); // Size of the array

    // If k is greater than array size, rotating n times gives the same array,
    // so we reduce k using modulo
    k = k % n;

    vector<int> t(n);
    // Copy last k elements to the beginning
    for(int i = 0; i < k; i++) {
        t[i] = a[n - k + i];
    }
    // Copy remaining elements
    for (int i = 0; i < n - k; i++) {
        t[k + i] = a[i];
    }
    // Copy back to original array
    for (int i = 0; i < n; i++) {
        a[i]= t[i];
    }
    
}

//Right Rotatiion With No Extra Spaces
//Approach 2
void Right_Reverse_Rotation(vector<int>& a,int k){
    // If k is greater than array size, rotating n times gives the same array,
    // so we reduce k using modulo
    k = k % a.size();

    // Reverse the array (Index 0 to a.size()-1)
    reverse(a.begin() , a.end());

    // Reverse the first k elements (Index 0 to k-1)
    reverse(a.begin() , a.begin()+k);
    
    // Reverse the last  Size()- k  elements (Index k to a.size()-1)
    reverse(a.begin()+k , a.end());
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
    Right_Reverse_Rotation(a, r);
    // Output: rotated array
    cout << "\nAfter r rotation the array is : ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}


```
</details>