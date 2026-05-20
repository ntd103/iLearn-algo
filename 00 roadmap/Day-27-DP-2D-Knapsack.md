---
day: 27
topic: DP 2D & Knapsack
tags:
  - roadmap
  - dsa/topics/dp/knapsack
  - dsa/topics/dp/grid
created: 2026-05-20
---
# Day 27 - DP 2D & Knapsack

## Lý thuyết

### Grid DP

```cpp
// Unique Paths: dp[i][j] = số cách đến (i,j)
vector<vector<int>> dp(m, vector<int>(n, 0));
dp[0][0] = 1;
for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) {
        if (i > 0) dp[i][j] += dp[i-1][j];
        if (j > 0) dp[i][j] += dp[i][j-1];
    }
return dp[m-1][n-1];
```

### 0/1 Knapsack

Mỗi item lấy hoặc không lấy.

```cpp
// dp[i][w] = max value với i items đầu, weight <= w
int knapsack01(vector<int>& weights, vector<int>& values, int W) {
    int n = weights.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            dp[i][w] = dp[i-1][w];  // skip
            if (w >= weights[i-1])
                dp[i][w] = max(dp[i][w], dp[i-1][w - weights[i-1]] + values[i-1]);
        }
    }
    return dp[n][W];
}

// Space-optimized: 1D array, duyệt w từ phải qua trái
int knapsack01_1d(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < weights.size(); i++) {
        for (int w = W; w >= weights[i]; w--) {  // PHẢI qua TRÁI
            dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}
```

### Unbounded Knapsack

Mỗi item có thể lấy không giới hạn.

```cpp
// dp[w] = max value với weight <= w
int knapsackUnbounded(vector<int>& weights, vector<int>& values, int W) {
    vector<int> dp(W + 1, 0);
    for (int w = 0; w <= W; w++) {
        for (int i = 0; i < weights.size(); i++) {
            if (w >= weights[i])
                dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
        }
    }
    return dp[W];
}

// Hoặc duyệt items ngoài, w trong từ TRÁI qua PHẢI
for (int i = 0; i < n; i++) {
    for (int w = weights[i]; w <= W; w++) {  // TRÁI qua PHẢI
        dp[w] = max(dp[w], dp[w - weights[i]] + values[i]);
    }
}
```

### Phân biệt 0/1 vs Unbounded - chiều duyệt

```cpp
// 0/1: w từ PHẢI qua TRÁI (tránh dùng cùng item nhiều lần)
for (int w = W; w >= weights[i]; w--) ...

// Unbounded: w từ TRÁI qua PHẢI (cho phép dùng lại)
for (int w = weights[i]; w <= W; w++) ...
```

### Subset Sum

```cpp
// dp[s] = có subset với sum = s không?
bool canPartition(vector<int>& nums) {
    int total = accumulate(all(nums), 0);
    if (total & 1) return false;
    int target = total / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;
    for (int x : nums) {
        for (int s = target; s >= x; s--) {
            dp[s] = dp[s] || dp[s - x];
        }
    }
    return dp[target];
}
```

### Coin Change variants

```cpp
// Số cách đổi tiền (unbounded)
int change(int amount, vector<int>& coins) {
    vector<int> dp(amount + 1, 0);
    dp[0] = 1;
    for (int c : coins) {
        for (int s = c; s <= amount; s++) {
            dp[s] += dp[s - c];
        }
    }
    return dp[amount];
}
```

### Min Path Sum

```cpp
int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) continue;
            int up = i > 0 ? grid[i-1][j] : INT_MAX;
            int left = j > 0 ? grid[i][j-1] : INT_MAX;
            grid[i][j] += min(up, left);
        }
    }
    return grid[m-1][n-1];
}
```

## Practice

### Medium

- [ ] Unique Paths (LC #62)
- [ ] Unique Paths II (LC #63)
- [ ] Minimum Path Sum (LC #64)
- [ ] Triangle (LC #120)
- [ ] Partition Equal Subset Sum (LC #416) - subset sum
- [ ] Target Sum (LC #494)
- [ ] Coin Change 2 (LC #518) - unbounded count
- [ ] Ones and Zeroes (LC #474)

### Hard

- [ ] Dungeon Game (LC #174)
- [ ] Profitable Schemes (LC #879)

---

**Next**: [[Day-28-DP-Patterns]]
