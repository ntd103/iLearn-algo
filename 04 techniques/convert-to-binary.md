---
difficulty: 
tags:
  - dsa/problem
  - algorithm
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+



```cpp
int binary(int n) {
    if (n == 0) return 0;
    return n % 2 + 10 * binary(n / 2);
}
```