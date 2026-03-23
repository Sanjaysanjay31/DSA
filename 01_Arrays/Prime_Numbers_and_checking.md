# **Prime Numbers and Checking**

### **Prime Number**
A prime number is a number greater than `1` that has **only two divisors**: `1` and itself.  
Examples: `2, 3, 5, 7, 11`.

---
### **Prime Number Checking**
To check if a number is prime:
- A prime number has exactly **two divisors**: `1` and itself.
- Numbers **less than or equal to 1** are not prime.
- `2` and `3` are the **only consecutive prime numbers**.
- Any **even number greater than 2** is not prime.
- If a number is divisible by `2` or `3`, it is not prime.
- Checking divisibility is required **only up to √n**.
- All prime numbers greater than `3` are of the form **6k ± 1**.
- If no divisor is found, the number is **prime**.
- Numbers divisible by `2` or `3` are not prime.
  
**Time Complexity:** O(√n)  
**Space Complexity:** O(1)

---
### **Sieve of Eratosthenes**
Used to find **all prime numbers up to `n`**.
- Mark multiples of each number as non-prime.
- Remaining numbers are prime.

**Time Complexity:** O(n log log n)  
**Space Complexity:** O(n)

---
### **Conclusion**
- Use **prime checking** for a single number.
- Use **Sieve of Eratosthenes** to find many primes efficiently.

---
<details>
<summary><mark><b>Prime_Numbers_And_Checking Code_ implementation</b></mark></summary>

```cpp
#include <bits/stdc++.h>   // Includes all standard C++ libraries
using namespace std;

// Function to check whether a number is prime
bool isprime(int n) {
    // Numbers less than or equal to 1 are not prime
    if (n <= 1) return false;

    // 2 and 3 are prime numbers
    if (n == 2 || n == 3) return true;

    // Eliminate multiples of 2 and 3
    if (n % 2 == 0 || n % 3 == 0) return false;

    // Check divisibility from 5 onwards in steps of 6
    // All prime numbers greater than 3 are of the form 6k ± 1
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    // If no divisor is found, the number is prime
    return true;
}

// Function to generate all prime numbers up to n
// Uses Sieve of Eratosthenes algorithm
vector<int> Prime_numbers(int n) {

    // If n is less than 2, there are no prime numbers
    if (n < 2) return {};

    // Boolean array to mark prime numbers
    vector<bool> isprime(n + 1, true);

    // 0 and 1 are not prime
    isprime[0] = isprime[1] = false;

    // Mark non-prime numbers
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            // Mark all multiples of i as non-prime
            for (int j = i * i; j <= n; j += i) {
                isprime[j] = false;
            }
        }
    }

    // Store all prime numbers in a vector
    vector<int> primes;
    for (int i = 2; i <= n; i++) {
        if (isprime[i])
            primes.push_back(i);
    }

    return primes;
}

int main() {
    int n;

    // Input the number
    cin >> n;

    // Check whether the given number is prime
    if (isprime(n))
        cout << "The given number is prime" << endl;
    else
        cout << "The given number is not Prime" << endl;

    // Get all prime numbers up to n
    vector<int> r = Prime_numbers(n);

    // Print prime numbers up to n
    cout << "The prime numbers up to n : ";
    for (int i = 0; i < r.size(); i++) {
        cout << r[i] << "  ";
    }
}

```
</details>