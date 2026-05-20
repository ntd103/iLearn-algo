---
day: 10
topic: Strings & Pattern Matching
tags:
  - roadmap
  - dsa/topics/string
  - dsa/topics/string-algo
created: 2026-05-20
---
# Day 10 - Strings & Pattern Matching

## Lý thuyết

### String basics C++

```cpp
string s = "hello";
s.size();
s.substr(pos, len);
s.find(pat);              // string::npos if not found
s.replace(pos, len, "x");
s + s;                    // concat
s == s2;                  // O(n)

// Char manipulation
isdigit(c); isalpha(c); isupper(c); islower(c);
toupper(c); tolower(c);
```

### String hashing

Polynomial hash: `H(s) = s[0]*p^(n-1) + s[1]*p^(n-2) + ... + s[n-1]`

```cpp
const ll MOD = 1e9 + 7;
const ll P = 31;

vector<ll> hashes(n + 1, 0), p_pow(n + 1, 1);
for (int i = 0; i < n; i++) {
    hashes[i + 1] = (hashes[i] * P + (s[i] - 'a' + 1)) % MOD;
    p_pow[i + 1] = (p_pow[i] * P) % MOD;
}

// hash of s[l..r]
ll get_hash(int l, int r) {
    ll h = (hashes[r + 1] - hashes[l] * p_pow[r - l + 1]) % MOD;
    return (h % MOD + MOD) % MOD;
}
```

Use case: so sánh substrings nhanh O(1) sau O(n) preprocessing.

### KMP - Pattern Matching

Tìm `pat` trong `text` trong O(n + m).

```cpp
vector<int> kmp_failure(string& p) {
    int m = p.size();
    vector<int> f(m, 0);
    for (int i = 1, k = 0; i < m; i++) {
        while (k > 0 && p[k] != p[i]) k = f[k - 1];
        if (p[k] == p[i]) k++;
        f[i] = k;
    }
    return f;
}

vector<int> kmp_search(string& t, string& p) {
    auto f = kmp_failure(p);
    vector<int> matches;
    int n = t.size(), m = p.size();
    for (int i = 0, k = 0; i < n; i++) {
        while (k > 0 && p[k] != t[i]) k = f[k - 1];
        if (p[k] == t[i]) k++;
        if (k == m) {
            matches.push_back(i - m + 1);
            k = f[k - 1];
        }
    }
    return matches;
}
```

### Z-function

`z[i]` = độ dài longest substring bắt đầu tại i match với prefix của s.

```cpp
vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) z[i]++;
        if (i + z[i] > r) { l = i; r = i + z[i]; }
    }
    return z;
}
```

## Practice

### Easy

- [ ] Reverse String (LC #344)
- [ ] Valid Palindrome (LC #125)
- [ ] Implement strStr (LC #28) - first KMP application

### Medium

- [ ] Longest Palindromic Substring (LC #5)
- [ ] String to Integer atoi (LC #8)
- [ ] Group Anagrams (LC #49)
- [ ] Repeated Substring Pattern (LC #459) - KMP trick
- [ ] Find the Index of the First Occurrence in a String (LC #28) - KMP

### Hard

- [ ] Shortest Palindrome (LC #214)
- [ ] Distinct Echo Substrings (LC #1316) - hashing

---

**Next**: [[Day-11-Sorting]]
