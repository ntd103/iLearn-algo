---
day: 32
topic: Number Theory & Math
tags:
  - roadmap
  - dsa/topics/math
  - dsa/topics/number-theory
created: 2026-05-20
---
# Day 32 - Number Theory & Math

## Lý thuyết

### GCD & LCM

```cpp
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
// Hoặc dùng built-in: __gcd(a, b)

ll lcm(ll a, ll b) { return a / __gcd(a, b) * b; }  // tránh overflow
```

### Extended Euclidean

Tìm x, y sao cho `ax + by = gcd(a, b)`.

```cpp
int extgcd(int a, int b, int& x, int& y) {
    if (!b) { x = 1; y = 0; return a; }
    int x1, y1;
    int g = extgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return g;
}
```

### Modular Arithmetic

```cpp
const int MOD = 1e9 + 7;

ll add(ll a, ll b) { return (a + b) % MOD; }
ll sub(ll a, ll b) { return ((a - b) % MOD + MOD) % MOD; }
ll mul(ll a, ll b) { return a * b % MOD; }
```

### Modular Inverse

Khi MOD prime: `a^(-1) = a^(MOD-2) mod MOD` (Fermat's little theorem).

```cpp
ll power(ll a, ll b, ll m) {
    ll ans = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) ans = ans * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ans;
}

ll inverse(ll a, ll m) {
    return power(a, m - 2, m);  // assume m is prime
}
```

### Sieve of Eratosthenes

```cpp
vector<bool> sieve(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    return isPrime;
}
```

Complexity: O(n log log n).

### Linear Sieve - smallest prime factor

```cpp
vector<int> spf(int n) {  // spf[i] = smallest prime factor
    vector<int> spf(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            for (int j = i; j <= n; j += i) {
                if (spf[j] == 0) spf[j] = i;
            }
        }
    }
    return spf;
}
```

### Prime Factorization

```cpp
vector<pii> factorize(int n) {
    vector<pii> factors;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            int count = 0;
            while (n % p == 0) { n /= p; count++; }
            factors.push_back({p, count});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}
```

### Fast Exponentiation

```cpp
ll power(ll a, ll b) {
    ll ans = 1;
    while (b > 0) {
        if (b & 1) ans *= a;
        a *= a;
        b >>= 1;
    }
    return ans;
}
```

### Combinatorics

```cpp
// Precompute factorials & inverse factorials
const int MAXN = 1e6 + 5;
ll fact[MAXN], inv_fact[MAXN];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) fact[i] = fact[i-1] * i % MOD;
    inv_fact[MAXN-1] = power(fact[MAXN-1], MOD - 2, MOD);
    for (int i = MAXN - 2; i >= 0; i--)
        inv_fact[i] = inv_fact[i+1] * (i+1) % MOD;
}

ll C(int n, int k) {
    if (k < 0 || k > n) return 0;
    return fact[n] * inv_fact[k] % MOD * inv_fact[n-k] % MOD;
}
```

### Euler Totient Function

`phi(n)` = số nguyên trong [1, n] coprime với n.

```cpp
int phi(int n) {
    int result = n;
    for (int p = 2; p * p <= n; p++) {
        if (n % p == 0) {
            while (n % p == 0) n /= p;
            result -= result / p;
        }
    }
    if (n > 1) result -= result / n;
    return result;
}
```

## Practice

### Easy

- [ ] Power of Two (LC #231)
- [ ] Power of Three (LC #326)
- [ ] Count Primes (LC #204) - sieve
- [ ] Happy Number (LC #202)
- [ ] Excel Sheet Column Number (LC #171)

### Medium

- [ ] Pow(x, n) (LC #50) - fast exp
- [ ] Fraction to Recurring Decimal (LC #166)
- [ ] Largest Number (LC #179)
- [ ] Ugly Number II (LC #264)
- [ ] Super Pow (LC #372) - modular exp
- [ ] Permutation Sequence (LC #60) - factorial

### Hard

- [ ] Number of Digit One (LC #233) - digit DP
- [ ] Random Pick with Weight (LC #528)

---

**Next**: [[Day-33-Trie]]
