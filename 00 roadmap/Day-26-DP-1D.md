---
day: 26
topic: Dynamic Programming 1D
tags:
  - roadmap
  - dsa/topics/dp
created: 2026-05-20
---
# Day 26 - DP 1D

## Lý thuyết

### DP framework

1. **State**: `dp[i]` = ?
2. **Transition**: `dp[i]` từ `dp[i-1]`, `dp[i-2]`, ... như thế nào?
3. **Base case**: `dp[0]` = ?
4. **Answer**: `dp[n]` hoặc max/min `dp[i]`

### Top-down (memoization) vs Bottom-up (tabulation)

```cpp
// Top-down: code dễ viết, có overhead recursion
unordered_map<int, int> memo;
int rec(int i) {
    if (i == 0) return base;
    if (memo.count(i)) return memo[i];
    return memo[i] = rec(i - 1) + rec(i - 2);
}

// Bottom-up: nhanh hơn, không stack overflow
vector<int> dp(n + 1);
dp[0] = base;
for (int i = 1; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
}
```

### Space optimization

Khi `dp[i]` chỉ phụ thuộc `dp[i-1]`, `dp[i-2]`:

```cpp
int prev2 = ..., prev1 = ...;
for (int i = 2; i <= n; i++) {
    int cur = prev1 + prev2;
    prev2 = prev1;
    prev1 = cur;
}
```

## Patterns

### Fibonacci-like

```cpp
// dp[i] = dp[i-1] + dp[i-2]
int fib(int n) {
    if (n < 2) return n;
    int a = 0, b = 1;
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        a = b; b = c;
    }
    return b;
}
```

### Climbing Stairs

```cpp
// dp[i] = số cách đến bậc i
// dp[i] = dp[i-1] + dp[i-2]
```

### House Robber

```cpp
// dp[i] = max tiền cướp được tới nhà i
// dp[i] = max(dp[i-1], dp[i-2] + nums[i])
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int cur = max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}
```

### Decode Ways

```cpp
// dp[i] = số cách decode chuỗi đến i
// dp[i] = (one digit valid ? dp[i-1] : 0) + (two digit valid ? dp[i-2] : 0)
```

### Coin Change (min coins)

```cpp
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        for (int c : coins) {
            if (i >= c && dp[i - c] != INT_MAX)
                dp[i] = min(dp[i], dp[i - c] + 1);
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}
```

### Jump Game

```cpp
// Greedy version
bool canJump(vector<int>& nums) {
    int reach = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (i > reach) return false;
        reach = max(reach, i + nums[i]);
    }
    return true;
}
```

## Recognition signals

- "Số cách..." -> count DP
- "Min/Max trên dãy" -> max/min DP
- "True/False có thể đạt..." -> boolean DP
- Có thể chia bài toán thành subproblems
- Overlapping subproblems

## Practice

### Easy

- [ ] Climbing Stairs (LC #70)
- [ ] Min Cost Climbing Stairs (LC #746)
- [ ] Fibonacci Number (LC #509)
- [ ] N-th Tribonacci Number (LC #1137)

### Medium

- [ ] House Robber (LC #198)
- [ ] House Robber II (LC #213) - circular
- [ ] Decode Ways (LC #91)
- [ ] Coin Change (LC #322)
- [ ] Maximum Subarray (LC #53) - Kadane
- [ ] Jump Game (LC #55)
- [ ] Jump Game II (LC #45)
- [ ] Word Break (LC #139)
- [ ] Longest Increasing Subsequence (LC #300) - O(n log n) optimal
- [ ] Maximum Product Subarray (LC #152)

---

**Next**: [[Day-27-DP-2D-Knapsack]]
