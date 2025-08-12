---
difficulty: 
tags:
  - dsa/Problem
  - algorithm
---
>[!question]+



```cpp
int binary(int n) {
    if (n == 0) return 0;
    return n % 2 + 10 * binary(n / 2);
}
```