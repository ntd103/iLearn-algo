---
day: 29
topic: DP Advanced - Bitmask, Tree, Digit
tags:
  - roadmap
  - dsa/topics/dp/bitmask
  - dsa/topics/dp/tree
created: 2026-05-20
---
# Day 29 - DP Advanced: Bitmask, Tree, Digit

## Lý thuyết

### Bitmask DP

State = bitmask thể hiện tập con đã visit/dùng.

```cpp
// TSP: dp[mask][i] = min cost để visit set mask, kết thúc ở i
int tsp(vector<vector<int>>& dist) {
    int n = dist.size();
    vector<vector<int>> dp(1 << n, vector<int>(n, INT_MAX));
    dp[1][0] = 0;  // bắt đầu từ 0
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u)) || dp[mask][u] == INT_MAX) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                int newMask = mask | (1 << v);
                dp[newMask][v] = min(dp[newMask][v], dp[mask][u] + dist[u][v]);
            }
        }
    }
    int ans = INT_MAX;
    for (int u = 0; u < n; u++)
        ans = min(ans, dp[(1 << n) - 1][u] + dist[u][0]);
    return ans;
}
```

Giới hạn: n <= 20 (do 2^20 = 10^6).

### Subset enumeration

```cpp
// Duyệt tất cả subset của mask
for (int sub = mask; sub > 0; sub = (sub - 1) & mask) {
    // sub là subset của mask
}
// Tổng complexity: 3^n thay vì 4^n
```

### Tree DP

DP trên cây, dùng postorder.

```cpp
// dp[u][0/1] = max value, 0 = không lấy u, 1 = lấy u
vector<vector<int>> dp;

void dfs(int u, int parent) {
    dp[u][0] = 0;
    dp[u][1] = val[u];
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];  // lấy u thì không lấy v
    }
}
```

### Rerooting Technique

Tính kết quả cho mọi root khác nhau, O(n).

```cpp
// Sum of distances from each node to all others
vector<int> ans(n), size_(n);

void dfs1(int u, int parent, int depth = 0) {
    size_[u] = 1;
    ans[0] += depth;
    for (int v : adj[u]) {
        if (v == parent) continue;
        dfs1(v, u, depth + 1);
        size_[u] += size_[v];
    }
}

void dfs2(int u, int parent) {
    for (int v : adj[u]) {
        if (v == parent) continue;
        ans[v] = ans[u] - size_[v] + (n - size_[v]);
        dfs2(v, u);
    }
}
```

### Digit DP

Đếm số trong [L, R] thỏa mãn điều kiện.

```cpp
string num;
vector<vector<int>> memo;

// dp[pos][tight] = số lượng số hợp lệ
int digitDP(int pos, bool tight, ...) {
    if (pos == num.size()) return 1;
    if (!tight && memo[pos][...] != -1) return memo[pos][...];
    int limit = tight ? (num[pos] - '0') : 9;
    int ans = 0;
    for (int d = 0; d <= limit; d++) {
        // additional state transitions
        ans += digitDP(pos + 1, tight && (d == limit), ...);
    }
    if (!tight) memo[pos][...] = ans;
    return ans;
}
```

## Practice

### Medium

- [ ] Beautiful Arrangement (LC #526) - bitmask
- [ ] Maximum Score Words Formed by Letters (LC #1255) - bitmask

### Hard

- [ ] Shortest Path Visiting All Nodes (LC #847) - BFS + bitmask
- [ ] Partition to K Equal Sum Subsets (LC #698) - bitmask
- [ ] Minimum Cost to Make Valid Path in Grid (LC #1368)
- [ ] Smallest Sufficient Team (LC #1125) - bitmask
- [ ] Number of Ways to Wear Different Hats (LC #1434) - bitmask
- [ ] Numbers At Most N Given Digit Set (LC #902) - digit DP

### Tree DP

- [ ] House Robber III (LC #337)
- [ ] Binary Tree Cameras (LC #968)
- [ ] Sum of Distances in Tree (LC #834) - rerooting

---

**Next**: [[Day-30-Greedy-Intervals]]
