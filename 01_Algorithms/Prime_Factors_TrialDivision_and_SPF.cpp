#include <bits/stdc++.h>
using namespace std;

/*
===============================================================================
1. PRIME FACTORIZATION WITHOUT SPF (TRIAL DIVISION)
===============================================================================

Idea:
Check every number from 2 to sqrt(n).
Whenever a number divides n, keep dividing until it no longer divides.

Example:
60 = 2 × 2 × 3 × 5
*/

vector<int> primeFactorsTrialDivision(int n) {

    vector<int> factors;

    // Try all possible divisors
    for(int i = 2; i * i <= n; i++) {

        // Extract all occurrences of i
        while(n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // Remaining number > 1 is also a prime factor
    if(n > 1) {
        factors.push_back(n);
    }

    return factors;
}

/*
===============================================================================
2. SPF (SMALLEST PRIME FACTOR SIEVE)
===============================================================================

Idea:
Precompute the smallest prime factor for every number.

Example:
spf[12] = 2
spf[15] = 3
spf[49] = 7

After preprocessing, factorization becomes very fast.
*/

vector<int> buildSPF(int N) {

    vector<int> spf(N + 1);

    // Initially assume every number is its own SPF
    for(int i = 0; i <= N; i++) {
        spf[i] = i;
    }

    // Sieve
    for(int i = 2; i * i <= N; i++) {

        // If spf[i] == i, then i is prime
        if(spf[i] == i) {

            // Mark multiples of i
            for(int j = i * i; j <= N; j += i) {

                // Set SPF only once
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    return spf;
}

/*
Factorize using SPF

Example:
60

spf[60] = 2
60 -> 30

spf[30] = 2
30 -> 15

spf[15] = 3
15 -> 5

spf[5] = 5
5 -> 1

Answer:
2 2 3 5
*/

vector<int> primeFactorsSPF(int n, vector<int>& spf) {

    vector<int> factors;

    while(n > 1) {
        factors.push_back(spf[n]);
        n /= spf[n];
    }

    return factors;
}

int main() {

    int n = 60;

    cout << "Prime Factorization using Trial Division:\n";

    vector<int> ans1 = primeFactorsTrialDivision(n);

    for(int x : ans1) {
        cout << x << " ";
    }

    cout << "\n\n";

    int N = 1000000;

    // Build SPF once
    vector<int> spf = buildSPF(N);

    cout << "Prime Factorization using SPF:\n";

    vector<int> ans2 = primeFactorsSPF(n, spf);

    for(int x : ans2) {
        cout << x << " ";
    }

    cout << "\n";

    return 0;
}

/*
===============================================================================
TIME COMPLEXITIES
===============================================================================

1. Trial Division

Prime Factorization:
O(√N)

Space:
O(1)

-------------------------------------------------------------------------------

2. SPF (Smallest Prime Factor)

Build SPF:
O(N log log N)

Prime Factorization:
O(log N)

Space:
O(N)

===============================================================================
USE CASES
===============================================================================

1. Trial Division

Use When:
✔ Only 1 or a few numbers need factorization
✔ Interview questions
✔ Small number of queries

Examples:
- Factorize 84
- Check prime factors of a single number
- Basic Number Theory

-------------------------------------------------------------------------------

2. SPF

Use When:
✔ Many factorization queries
✔ Competitive Programming
✔ Number Theory Problems
✔ Divisor Problems
✔ Prime Factor Queries
✔ GCD / LCM Problems
✔ DSU + Prime Factor Problems

Examples:
- Count Distinct Prime Factors
- Number of Divisors
- Sum of Divisors
- LeetCode 952
- LeetCode 1998
- LeetCode 2709

===============================================================================
INTERVIEW RULE
===============================================================================

Few Queries
→ Trial Division (O(√N))

Many Queries
→ SPF (O(N log log N) preprocessing + O(log N) per query)

===============================================================================
*/