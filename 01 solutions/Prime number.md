---
difficulty: Easy
tags:
  - fundamental
  - dsa/Problem
  - algorithm
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+ Prime Number

```cpp
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int n) {
    if (n <= 1)
        return false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n;
    cin >> n;
    cout << (isPrime(n) ? "YES" : "NO");
}
```

Recursive ver:

```cpp
bool isPrime(int num, int divisor = 2) {
    if (num <= 1) return false;
    if (divisor > sqrt(num)) return true;
    if (num % divisor == 0) return false;
    
    return isPrime(num, divisor + 1);
}
```
