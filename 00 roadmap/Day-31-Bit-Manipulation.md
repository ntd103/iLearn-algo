---
day: 31
topic: Bit Manipulation
tags:
  - roadmap
  - dsa/topics/bit-manipulation
created: 2026-05-20
---
# Day 31 - Bit Manipulation

## Lý thuyết

### Operators

| Op | Effect |
|----|--------|
| `&` | AND |
| `\|` | OR |
| `^` | XOR |
| `~` | NOT |
| `<<` | Left shift |
| `>>` | Right shift |

### Common tricks

```cpp
// Test bit i
(x >> i) & 1
x & (1 << i)

// Set bit i
x | (1 << i)

// Clear bit i
x & ~(1 << i)

// Toggle bit i
x ^ (1 << i)

// Lowest set bit
x & -x          // isolate lowest 1 bit
x & (x - 1)     // turn off lowest 1 bit

// Check power of 2
(x & (x - 1)) == 0  // x > 0

// Count 1 bits
__builtin_popcount(x);       // int
__builtin_popcountll(x);     // long long

// Number of trailing/leading zeros
__builtin_ctz(x);   // counting trailing zeros
__builtin_clz(x);   // counting leading zeros

// XOR properties
a ^ a = 0
a ^ 0 = a
a ^ b ^ a = b
```

### Subsets enumeration

```cpp
// All 2^n subsets of {0, 1, ..., n-1}
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) {
            // i is in subset
        }
    }
}

// Subsets of mask
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // sub is subset of mask (excluding 0)
}
```

### Single Number variants

```cpp
// Single Number I: chỉ 1 phần tử xuất hiện 1 lần, còn lại 2 lần
int singleNumber(vector<int>& nums) {
    int x = 0;
    for (int n : nums) x ^= n;
    return x;
}

// Single Number III: 2 phần tử khác xuất hiện 1 lần
vector<int> singleNumber3(vector<int>& nums) {
    int xorAll = 0;
    for (int n : nums) xorAll ^= n;
    int diff = xorAll & -xorAll;  // lowest different bit
    int a = 0, b = 0;
    for (int n : nums) {
        if (n & diff) a ^= n;
        else b ^= n;
    }
    return {a, b};
}
```

### Bit DP

State là bitmask, mỗi bit = 1 phần tử đã dùng.

### Useful conversions

```cpp
// Reverse bits in 32-bit int
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
    n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
    n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
    n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
    return n;
}

// Gray code
int grayCode(int n) { return n ^ (n >> 1); }
```

## Practice

### Easy

- [ ] Single Number (LC #136)
- [ ] Number of 1 Bits (LC #191)
- [ ] Counting Bits (LC #338)
- [ ] Missing Number (LC #268)
- [ ] Reverse Bits (LC #190)
- [ ] Power of Two (LC #231)
- [ ] Hamming Distance (LC #461)

### Medium

- [ ] Single Number II (LC #137) - count mod 3
- [ ] Single Number III (LC #260)
- [ ] Bitwise AND of Numbers Range (LC #201)
- [ ] Sum of Two Integers (LC #371) - không dùng `+`
- [ ] UTF-8 Validation (LC #393)
- [ ] Subsets (LC #78) - bitmask approach

### Hard

- [ ] Maximum XOR of Two Numbers (LC #421) - Trie
- [ ] Smallest Sufficient Team (LC #1125) - bitmask DP

## Tips

- `& 1` thay vì `% 2` để check chẵn lẻ
- `<< 1` thay vì `* 2`, `>> 1` thay vì `/ 2`
- Cẩn thận với negative numbers trong shifts (UB trong C++)
- Long long: `1LL << 60`, không phải `1 << 60`

---

**Next**: [[Day-32-Number-Theory]]
