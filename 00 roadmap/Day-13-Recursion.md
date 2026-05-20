---
day: 13
topic: Recursion Fundamentals
tags:
  - roadmap
  - dsa/topics/recursion
created: 2026-05-20
---
# Day 13 - Recursion

## Lý thuyết

### 3 thành phần

1. **Base case**: khi nào dừng
2. **Recursive case**: chia bài toán thành nhỏ hơn
3. **Return value**: trả về cái gì

### Thinking model

```
fn(n):
    if base_case: return base_value
    smaller_result = fn(n - 1)  // hoặc fn(n / 2)
    return combine(n, smaller_result)
```

### Stack depth limit

```cpp
// Mặc định ~1MB stack (Linux)
// Đệ quy quá sâu -> stack overflow

// Fix Python:
import sys
sys.setrecursionlimit(10**6)
```

### Memoization (top-down DP)

```cpp
unordered_map<int, int> memo;

int fib(int n) {
    if (n < 2) return n;
    if (memo.count(n)) return memo[n];
    return memo[n] = fib(n - 1) + fib(n - 2);
}
```

```python
from functools import cache

@cache
def fib(n):
    if n < 2: return n
    return fib(n-1) + fib(n-2)
```

### Tail recursion

```cpp
// Không tail recursion - dùng stack
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Tail recursion - compiler có thể optimize
int factorial_tail(int n, int acc = 1) {
    if (n <= 1) return acc;
    return factorial_tail(n - 1, acc * n);
}
```

### Recursion vs Iteration

| Recursion | Iteration |
|-----------|-----------|
| Code đẹp, tự nhiên cho tree/divide-conquer | Nhanh hơn (no function call overhead) |
| Stack overflow risk | Không stack issue |
| Dễ debug logic | Cần explicit stack |

## Common Patterns

### Divide and Conquer

```cpp
T solve(arr, l, r) {
    if (l >= r) return base;
    int mid = (l + r) / 2;
    T left = solve(arr, l, mid);
    T right = solve(arr, mid + 1, r);
    return combine(left, right);
}
```

Examples: Merge sort, Maximum subarray (D&C version), Power of x.

### Recursion with Helper

```cpp
// Wrapper với extra param
int helper(TreeNode* root, int& maxSum) {
    if (!root) return 0;
    int l = max(0, helper(root->left, maxSum));
    int r = max(0, helper(root->right, maxSum));
    maxSum = max(maxSum, l + r + root->val);
    return root->val + max(l, r);
}
```

## Practice

### Easy

- [ ] Fibonacci Number (LC #509)
- [ ] Power of Three (LC #326)
- [ ] Reverse String (LC #344) - recursive
- [ ] Sum of Digits using Recursion

### Medium

- [ ] Pow(x, n) (LC #50) - fast exponentiation
- [ ] Permutations (LC #46)
- [ ] Subsets (LC #78)
- [ ] Combinations (LC #77)

## Mistakes thường gặp

- Quên base case -> infinite recursion
- Base case sai -> kết quả sai
- Không pass reference cho large data -> TLE
- Stack overflow với n > 10^5 không có memoization

---

**Next**: [[Day-14-Backtracking]]
