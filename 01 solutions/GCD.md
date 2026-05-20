---
difficulty: Easy
tags:
  - dsa/Problem
  - fundamental
  - algorithm
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+ Hàm ước chung lớn nhất

```cpp
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
```

>Note:
>Giải thuật Euclid

