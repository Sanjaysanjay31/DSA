# Kadane’s Algorithm 

### Problem
You are given an array of numbers (both positive and negative).  
Your task is to find the **maximum sum of a continuous subarray**.


###  Idea
Kadane’s Algorithm works on one simple rule:
- If the current sum becomes negative, it is useless for future subarrays, so reset it.
- A negative sum will only decrease the total, so we start fresh from the next element.



### Steps
1. Start with a running sum = 0.
2. Add each element to the running sum.
3. Keep checking if this running sum is the largest we have seen so far.
4. If the running sum becomes negative, reset it to 0.
5. Continue this process until the end of the array.


### Tracking the Subarray
To print the subarray:
- A temporary start index is stored.
- When a new maximum sum is found, the start and end positions are saved.
- When the sum resets, the next index becomes the new starting point.

**This helps us find:**
- Maximum subarray sum
- Subarray length
- Subarray elements

--- 


<details>
<summary><mark><b>Kadane's_Algorithm Code implementation</b></mark></summary>

```cpp
#include <bits/stdc++.h> // includes all Standard c++ Libraries
using namespace std;

int main() {
    int n;
    // Input : Size of the array
    cout << "\nEnter the size: ";
    cin >> n;
    // Declare an array 
    vector<int> a(n);
    // Input : array elements 
    cout << "\nEnter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long maxi = LLONG_MIN;      // Declare an Long long variable for storing maximum subarray sum
    long long sum = 0;
    int start = 0, end = 0;          // the final maximum sum subarray indexes
    int s = 0;                       // s is temporary starting index
    // Traverse array to apply Kadane's Algorithm
    for (int i = 0; i < n; i++) {
        sum += a[i];          // add current element to running sum
        // Update maximum sum and indices if better sum found
        if (sum > maxi) {
            maxi = sum;            // Update the maximum subarray sum indexes
            start = s; 
            end = i;
        }

        if (sum < 0) {
            sum = 0;
            s = i + 1; // next subarray starts from i+1
        }
    }

    int len = end - start + 1;
    // Output : Maximum sum
    cout << "\nThe maximum subarray sum is: " << maxi;
    // Output : Lenght of the Subarray
    cout << "\nThe length of the maximum subarray is: " << len;
    cout << "\nThe maximum subarray is: ";
    // Output : Print subarray elements
    for (int i = start; i <= end; i++){
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}

```
</details>