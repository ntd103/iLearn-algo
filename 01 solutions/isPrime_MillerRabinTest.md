---
difficulty: 
tags:
  - dsa/Problem
  - algorithm
  - Math
  - cryptography
lastReviewed: 2026-05-19
reviewCount: 0
status: solved
---
>[!question]+

# isPrime_MillerRabinTest

```cpp
// Hàm tính (a^d) % n bằng phương pháp bình phương lũy thừa
long long powerMod(long long a, long long d, long long n) {
    long long result = 1;
    a %= n;
    while (d > 0) {
        if (d & 1) result = (result * a) % n;
        a = (a * a) % n;
        d >>= 1; //dịch phải 1 bit => chia 2^1
    }
    return result;
}

// Kiểm tra Miller-Rabin với cơ sở a
bool millerTest(long long d, long long n) {
    long long a = 2 + rand() % (n - 4);
    long long x = powerMod(a, d, n);
    if (x == 1 || x == n - 1) return true;

    while (d != n - 1) {
        x = (x * x) % n;
        d *= 2;
        if (x == n - 1) return true;
        if (x == 1) return false;
    }
    return false;
}

// Kiểm tra Miller-Rabin chính
bool isPrime(long long n, int k = 5) {
    if (n <= 1 || n % 2 == 0) return n == 2;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    for (int i = 0; i < k; i++)
        if (!millerTest(d, n)) return false;
    return true;
}
```


