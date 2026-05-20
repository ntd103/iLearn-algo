---
day: 28
topic: DP Patterns - LIS, LCS, Edit Distance
tags:
  - roadmap
  - dsa/topics/dp/string
created: 2026-05-20
---
# Day 28 - DP Patterns: LIS, LCS, Edit Distance

## Lý thuyết

### Longest Increasing Subsequence (LIS)

```cpp
// O(n^2)
int lis(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
    return *max_element(all(dp));
}

// O(n log n) - patience sort
int lis_fast(vector<int>& a) {
    vector<int> tails;
    for (int x : a) {
        auto it = lower_bound(all(tails), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}
```

**Lưu ý**: `tails` sau cùng KHÔNG phải LIS thật, chỉ độ dài là đúng.

### Longest Common Subsequence (LCS)

```cpp
// dp[i][j] = LCS của a[0..i-1] và b[0..j-1]
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    return dp[n][m];
}
```

### Edit Distance (Levenshtein)

```cpp
// dp[i][j] = số ops min để biến a[0..i-1] thành b[0..j-1]
// 3 ops: insert, delete, replace
int editDistance(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i <= n; i++) dp[i][0] = i;  // delete all
    for (int j = 0; j <= m; j++) dp[0][j] = j;  // insert all
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1];
            else dp[i][j] = 1 + min({
                dp[i-1][j],     // delete
                dp[i][j-1],     // insert
                dp[i-1][j-1]    // replace
            });
        }
    return dp[n][m];
}
```

### Longest Palindromic Subsequence

```cpp
// = LCS(s, reverse(s))
// Hoặc trực tiếp: dp[i][j] = LPS của s[i..j]
int lps(string& s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
            else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}
```

### Longest Palindromic Substring (khác Subsequence!)

```cpp
// dp[i][j] = s[i..j] có là palindrome không
string longestPalSubstring(string& s) {
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int start = 0, len = 1;
    for (int i = 0; i < n; i++) dp[i][i] = true;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j] && (j - i == 1 || dp[i+1][j-1])) {
                dp[i][j] = true;
                if (j - i + 1 > len) {
                    len = j - i + 1; start = i;
                }
            }
        }
    }
    return s.substr(start, len);
}
```

### Reconstruct path

```cpp
// Reconstruct LCS string
string reconstruct(string& a, string& b, vector<vector<int>>& dp) {
    string ans;
    int i = a.size(), j = b.size();
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            ans = a[i-1] + ans;
            i--; j--;
        } else if (dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    return ans;
}
```

## Practice

### Medium

- [ ] Longest Increasing Subsequence (LC #300)
- [ ] Longest Common Subsequence (LC #1143)
- [ ] Longest Palindromic Substring (LC #5)
- [ ] Longest Palindromic Subsequence (LC #516)
- [ ] Word Break II (LC #140)
- [ ] Number of Longest Increasing Subsequence (LC #673)
- [ ] Russian Doll Envelopes (LC #354) - 2D LIS

### Hard

- [ ] Edit Distance (LC #72)
- [ ] Distinct Subsequences (LC #115)
- [ ] Interleaving String (LC #97)
- [ ] Wildcard Matching (LC #44)
- [ ] Regular Expression Matching (LC #10)

---

**Next**: [[Day-29-DP-Bitmask-Tree]]
