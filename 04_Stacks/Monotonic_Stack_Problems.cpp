#include <bits/stdc++.h>
using namespace std;

// ==========================================
// MONOTONIC STACK APPLICATIONS IMPLEMENTATION
// ==========================================

/**
 * 1. Next Greater Element (NGE)
 * Concept: For each element, find the first element to its right that is strictly greater.
 * Traverse: Right to Left (i = n-1 down to 0)
 * Stack: Monotonic Decreasing Stack (elements bottom-to-top are decreasing).
 * Logic: Before pushing arr[i], pop all elements <= arr[i].
 */
vector<int> nextGreaterElement(const vector<int>& arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores potential next greater elements

    for (int i = n - 1; i >= 0; i--)
    {
        // Pop elements that are smaller than or equal to current element
        // because they can't be the "next greater" for any element to the left
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // If stack is not empty, top element is the next greater element
        if (!st.empty())
        {
            result[i] = st.top();
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

/**
 * 2. Next Smaller Element (NSE)
 * Concept: For each element, find the first element to its right that is strictly smaller.
 * Traverse: Right to Left (i = n-1 down to 0)
 * Stack: Monotonic Increasing Stack (elements bottom-to-top are increasing).
 * Logic: Before pushing arr[i], pop all elements >= arr[i].
 */
vector<int> nextSmallerElement(const vector<int>& arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores potential next smaller elements

    for (int i = n - 1; i >= 0; i--)
    {
        // Pop elements that are larger than or equal to current element
        // because they can't be the "next smaller" for any element to the left
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // If stack is not empty, top element is the next smaller element
        if (!st.empty())
        {
            result[i] = st.top();
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

/**
 * 3. Previous Greater Element (PGE)
 * Concept: For each element, find the first element to its left that is strictly greater.
 * Traverse: Left to Right (i = 0 to n-1)
 * Stack: Monotonic Decreasing Stack (elements bottom-to-top are decreasing).
 * Logic: Before pushing arr[i], pop all elements <= arr[i].
 */
vector<int> previousGreaterElement(const vector<int>& arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores potential previous greater elements

    for (int i = 0; i < n; i++)
    {
        // Pop elements that are smaller than or equal to current element
        // because they can't be the "previous greater" for any element to the right
        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }

        // If stack is not empty, top element is the previous greater element
        if (!st.empty())
        {
            result[i] = st.top();
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

/**
 * 4. Previous Smaller Element (PSE)
 * Concept: For each element, find the first element to its left that is strictly smaller.
 * Traverse: Left to Right (i = 0 to n-1)
 * Stack: Monotonic Increasing Stack (elements bottom-to-top are increasing).
 * Logic: Before pushing arr[i], pop all elements >= arr[i].
 */
vector<int> previousSmallerElement(const vector<int>& arr)
{
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st; // Stores potential previous smaller elements

    for (int i = 0; i < n; i++)
    {
        // Pop elements that are larger than or equal to current element
        // because they can't be the "previous smaller" for any element to the right
        while (!st.empty() && st.top() >= arr[i])
        {
            st.pop();
        }

        // If stack is not empty, top element is the previous smaller element
        if (!st.empty())
        {
            result[i] = st.top();
        }

        // Push current element into stack
        st.push(arr[i]);
    }

    return result;
}

// Helper function to print vector elements beautifully
void printVector(const string& label, const vector<int>& vec)
{
    cout << left << setw(30) << label << ": [";
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i];
        if (i < vec.size() - 1)
        {
            cout << ", ";
        }
    }
    cout << "]\n";
}

int main()
{
    // Sample Test Case
    vector<int> arr = {4, 5, 2, 10, 8};

    cout << "=========================================\n";
    cout << "      MONOTONIC STACK APPLICATIONS       \n";
    cout << "=========================================\n\n";

    printVector("Input Array", arr);
    cout << string(45, '-') << "\n";

    // 1. Next Greater Element
    vector<int> nge = nextGreaterElement(arr);
    printVector("Next Greater Element (NGE)", nge);

    // 2. Next Smaller Element
    vector<int> nse = nextSmallerElement(arr);
    printVector("Next Smaller Element (NSE)", nse);

    // 3. Previous Greater Element
    vector<int> pge = previousGreaterElement(arr);
    printVector("Previous Greater Element (PGE)", pge);

    // 4. Previous Smaller Element
    vector<int> pse = previousSmallerElement(arr);
    printVector("Previous Smaller Element (PSE)", pse);

    cout << "\n=========================================\n";

    return 0;
}
