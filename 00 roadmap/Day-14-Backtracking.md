---
day: 14
topic: Backtracking
tags:
  - roadmap
  - dsa/topics/backtracking
created: 2026-05-20
---
# Day 14 - Backtracking

## Lý thuyết

### Template chuẩn

```cpp
void backtrack(state, choices) {
    if (is_solution(state)) {
        save(state);
        return;
    }
    for (choice : choices) {
        if (!is_valid(choice)) continue;
        apply(choice);              // make choice
        backtrack(new_state, ...);  // explore
        undo(choice);               // undo (BACKTRACK)
    }
}
```

### Pruning - giảm branch

```cpp
// Pruning ví dụ - sum > target trong subset sum
void backtrack(int i, int sum) {
    if (sum > target) return;  // PRUNE
    if (sum == target) { count++; return; }
    if (i == n) return;
    // ...
}
```

### Phân biệt Permutations vs Combinations vs Subsets

```cpp
// Permutations [a,b,c] -> 6 results: abc, acb, bac, bca, cab, cba
void perm(vector<int>& cur, vector<bool>& used) {
    if (cur.size() == n) { results.push_back(cur); return; }
    for (int i = 0; i < n; i++) {
        if (used[i]) continue;
        used[i] = true;
        cur.push_back(arr[i]);
        perm(cur, used);
        cur.pop_back();
        used[i] = false;
    }
}

// Combinations C(n,k) - chọn k từ n
void comb(int start, vector<int>& cur, int k) {
    if (cur.size() == k) { results.push_back(cur); return; }
    for (int i = start; i < n; i++) {
        cur.push_back(arr[i]);
        comb(i + 1, cur, k);
        cur.pop_back();
    }
}

// Subsets - 2^n
void subset(int i, vector<int>& cur) {
    if (i == n) { results.push_back(cur); return; }
    subset(i + 1, cur);              // skip
    cur.push_back(arr[i]);
    subset(i + 1, cur);              // take
    cur.pop_back();
}
```

### Backtracking với duplicates

```cpp
sort(all(arr));

void backtrack(int start, vector<int>& cur) {
    results.push_back(cur);
    for (int i = start; i < n; i++) {
        if (i > start && arr[i] == arr[i - 1]) continue;  // skip duplicate
        cur.push_back(arr[i]);
        backtrack(i + 1, cur);
        cur.pop_back();
    }
}
```

## Common problems

- N-Queens
- Sudoku Solver
- Word Search (DFS với backtrack)
- Combination Sum (target sum)
- Generate parentheses

## Practice

### Medium

- [ ] Subsets (LC #78)
- [ ] Subsets II (LC #90) - duplicates
- [ ] Permutations (LC #46)
- [ ] Permutations II (LC #47) - duplicates
- [ ] Combinations (LC #77)
- [ ] Combination Sum (LC #39)
- [ ] Combination Sum II (LC #40)
- [ ] Letter Combinations of Phone Number (LC #17)
- [ ] Generate Parentheses (LC #22)
- [ ] Word Search (LC #79)
- [ ] Palindrome Partitioning (LC #131)

### Hard

- [ ] N-Queens (LC #51)
- [ ] Sudoku Solver (LC #37)
- [ ] Word Search II (LC #212) - backtrack + Trie

## Mistakes thường gặp

- Quên `pop_back()` khi backtrack
- Pass by value thay vì reference -> TLE và sai logic
- Không sort khi có duplicates -> kết quả trùng
- `i = start` vs `i = 0` trong combinations vs permutations

---

**Next**: [[Day-15-Linked-Lists]]
