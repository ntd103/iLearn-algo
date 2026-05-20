# DSA Quick Reference Cheatsheet

## Time Complexity Hierarchy

```
O(1) < O(log n) < O(√n) < O(n) < O(n log n) < O(n²) < O(n³) < O(2^n) < O(n!)
```

**Common examples:**
- `O(1)`: Array access, hash map lookup, stack push/pop
- `O(log n)`: Binary search, balanced BST operations, heap insert/delete
- `O(n)`: Linear scan, hash map build, BFS/DFS
- `O(n log n)`: Merge sort, heap sort, quick sort (average)
- `O(n²)`: Bubble/insertion/selection sort, naive string matching, nested loops
- `O(2^n)`: Subsets, recursive fibonacci without memo
- `O(n!)`: Permutations, brute-force TSP

**Constraint → Acceptable Complexity:**
| n | Max acceptable |
|---|----------------|
| ≤ 20 | O(2^n), O(n!) |
| ≤ 500 | O(n³) |
| ≤ 5,000 | O(n²) |
| ≤ 10^5 | O(n log n) |
| ≤ 10^6 | O(n) |
| ≤ 10^8 | O(log n), O(1) |

---

## Data Structure Operations

### Array / Vector
| Operation | Time |
|-----------|------|
| Access by index | O(1) |
| Search (unsorted) | O(n) |
| Search (sorted, binary) | O(log n) |
| Insert at end | O(1) amortized |
| Insert at middle | O(n) |
| Delete | O(n) |

**C++ STL:** `vector<int>`, `array<int,N>`

---

### Hash Map / Hash Set
| Operation | Average | Worst |
|-----------|---------|-------|
| Insert | O(1) | O(n) |
| Delete | O(1) | O(n) |
| Lookup | O(1) | O(n) |

**C++ STL:** `unordered_map<K,V>`, `unordered_set<T>`
**Ordered variant:** `map<K,V>`, `set<T>` — O(log n) all ops, sorted iteration

---

### Stack
| Operation | Time |
|-----------|------|
| Push | O(1) |
| Pop | O(1) |
| Peek (top) | O(1) |

**C++ STL:** `stack<T>` or `vector<T>` with `push_back`/`pop_back`
**Use for:** DFS, expression parsing, backtracking, matching brackets, monotonic stack

---

### Queue / Deque
| Operation | Time |
|-----------|------|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Peek (front) | O(1) |

**C++ STL:** `queue<T>`, `deque<T>`
**Use for:** BFS, level-order traversal, sliding window maximum

---

### Heap (Priority Queue)
| Operation | Time |
|-----------|------|
| Insert | O(log n) |
| Get min/max | O(1) |
| Remove min/max | O(log n) |
| Build from array | O(n) |

**C++ STL:** `priority_queue<T>` (max-heap by default)
**Min-heap:** `priority_queue<int, vector<int>, greater<int>>`
**Use for:** Top K, running median, Dijkstra, Prim's MST

---

### Binary Search Tree (Balanced: AVL / Red-Black)
| Operation | Average | Worst |
|-----------|---------|-------|
| Search | O(log n) | O(log n) |
| Insert | O(log n) | O(log n) |
| Delete | O(log n) | O(log n) |
| Min/Max | O(log n) | O(log n) |
| Sorted iteration | O(n) | O(n) |

**C++ STL:** `set<T>`, `map<K,V>` (Red-Black Tree internally)
**Use for:** Sorted data + fast ops, range queries, order statistics

---

### Trie (Prefix Tree)
| Operation | Time |
|-----------|------|
| Insert | O(m) |
| Search | O(m) |
| Prefix search | O(m) |

*m = length of string*

**Use for:** Autocomplete, prefix matching, word dictionary, IP routing

---

### Disjoint Set Union (Union-Find)
| Operation | Time |
|-----------|------|
| Find | O(α(n)) ≈ O(1) |
| Union | O(α(n)) ≈ O(1) |

*α = inverse Ackermann function, effectively constant*

**Use for:** Dynamic connectivity, Kruskal's MST, cycle detection in undirected graphs

---

### Segment Tree
| Operation | Time |
|-----------|------|
| Build | O(n) |
| Range query | O(log n) |
| Point update | O(log n) |
| Range update (lazy) | O(log n) |

**Use for:** Range sum/min/max queries with updates

---

### Fenwick Tree (Binary Indexed Tree)
| Operation | Time |
|-----------|------|
| Build | O(n log n) |
| Prefix sum query | O(log n) |
| Point update | O(log n) |

**Use for:** Prefix sum queries with updates (simpler than Segment Tree for this case)

---

## Sorting Algorithms

| Algorithm | Best | Average | Worst | Space | Stable |
|-----------|------|---------|-------|-------|--------|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | |
| Counting Sort | O(n+k) | O(n+k) | O(n+k) | O(k) | |
| Radix Sort | O(nk) | O(nk) | O(nk) | O(n+k) | |

**When to use:**
- **std::sort (introsort):** Default choice, O(n log n) guaranteed
- **Merge Sort:** Need stable sort, sorting linked lists
- **Counting Sort:** Small integer range (k ≤ 10^6)
- **Insertion Sort:** Nearly sorted data, small n (< 20)

---

## Graph Algorithms

### BFS
- **Time:** O(V + E)
- **Space:** O(V)
- **Use:** Shortest path (unweighted), level-order, minimum steps, nearest neighbor

### DFS
- **Time:** O(V + E)
- **Space:** O(V) — recursion stack
- **Use:** Connectivity, cycle detection, topological sort, all paths, SCC

### Dijkstra's Algorithm
- **Time:** O((V + E) log V) with binary heap
- **Space:** O(V)
- **Use:** Shortest path with non-negative weights
- **Fails on:** Negative edge weights

### Bellman-Ford
- **Time:** O(V · E)
- **Space:** O(V)
- **Use:** Shortest path with negative weights, detect negative cycles

### Floyd-Warshall
- **Time:** O(V³)
- **Space:** O(V²)
- **Use:** All-pairs shortest path, small graphs (V ≤ 500)

### Topological Sort (Kahn's BFS)
- **Time:** O(V + E)
- **Space:** O(V)
- **Use:** Task scheduling, course prerequisites, dependency resolution

### Kruskal's MST
- **Time:** O(E log E)
- **Space:** O(V)
- **Use:** Minimum spanning tree, uses Union-Find

### Prim's MST
- **Time:** O((V + E) log V) with heap
- **Space:** O(V)
- **Use:** Minimum spanning tree, better for dense graphs

---

## Pattern Recognition Guide

| Problem Signal | Pattern |
|----------------|---------|
| "Contiguous subarray with condition" | Sliding Window |
| "Pairs in sorted array" | Two Pointers |
| "All combinations / permutations / subsets" | Backtracking |
| "Maximum / minimum (optimization)" | DP or Greedy |
| "Count number of ways" | DP |
| "Shortest path (unweighted)" | BFS |
| "Shortest path (weighted, non-negative)" | Dijkstra |
| "Is there a cycle?" | DFS or Union-Find |
| "Top K elements" | Heap |
| "Range queries with updates" | Segment Tree / Fenwick |
| "Search in sorted array" | Binary Search |
| "Find minimum X such that condition holds" | Binary Search on answer |
| "Parentheses matching / next greater element" | Stack |
| "Tree level-order" | BFS |
| "Tree paths / connectivity" | DFS |
| "Prefix matching / autocomplete" | Trie |
| "Dynamic connectivity" | Union-Find |
| "Subarray sum = k" | Prefix Sum + Hash Map |
| "Overlapping intervals" | Sort + Sweep |

---

## Code Templates (C++)

### Binary Search
```cpp
// Find target in sorted array
int left = 0, right = n - 1;
while (left <= right) {
 int mid = left + (right - left) / 2; // avoid overflow
 if (arr[mid] == target) return mid;
 else if (arr[mid] < target) left = mid + 1;
 else right = mid - 1;
}
// target not found

// Binary search on answer: find minimum x where check(x) is true
int left = lo, right = hi;
while (left < right) {
 int mid = left + (right - left) / 2;
 if (check(mid)) right = mid;
 else left = mid + 1;
}
// answer is left
```

### Two Pointers
```cpp
int left = 0, right = n - 1;
while (left < right) {
 int sum = arr[left] + arr[right];
 if (sum == target) { /* found */ }
 else if (sum < target) left++;
 else right--;
}
```

### Sliding Window (Variable Size)
```cpp
int left = 0, result = 0;
// window state (e.g., unordered_map, int count)
for (int right = 0; right < n; right++) {
 // expand: add arr[right] to window
 while (/* window invalid */) {
 // shrink: remove arr[left] from window
 left++;
 }
 result = max(result, right - left + 1);
}
```

### DFS (Graph)
```cpp
vector<bool> visited(n, false);
void dfs(int node) {
 visited[node] = true;
 for (int neighbor : adj[node]) {
 if (!visited[neighbor])
 dfs(neighbor);
 }
}
```

### BFS (Graph)
```cpp
queue<int> q;
vector<bool> visited(n, false);
q.push(start);
visited[start] = true;
while (!q.empty()) {
 int node = q.front(); q.pop();
 for (int neighbor : adj[node]) {
 if (!visited[neighbor]) {
 visited[neighbor] = true;
 q.push(neighbor);
 }
 }
}
```

### Backtracking
```cpp
void backtrack(vector<int>& path, vector<int>& choices) {
 if (is_solution(path)) {
 result.push_back(path);
 return;
 }
 for (int i = 0; i < choices.size(); i++) {
 if (can_use(choices[i])) {
 path.push_back(choices[i]);
 backtrack(path, choices);
 path.pop_back(); // undo
 }
 }
}
```

### Dynamic Programming (1D)
```cpp
vector<int> dp(n + 1, 0);
dp[0] = base_case;
for (int i = 1; i <= n; i++) {
 dp[i] = /* recurrence using dp[i-1], dp[i-2], etc. */;
}
return dp[n];
```

### Dynamic Programming (2D)
```cpp
vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
// initialize base cases
for (int i = 1; i <= m; i++) {
 for (int j = 1; j <= n; j++) {
 dp[i][j] = /* recurrence */;
 }
}
return dp[m][n];
```

### Union-Find
```cpp
vector<int> parent, rank_;
void init(int n) {
 parent.resize(n); rank_.resize(n, 0);
 iota(parent.begin(), parent.end(), 0);
}
int find(int x) {
 if (parent[x] != x) parent[x] = find(parent[x]); // path compression
 return parent[x];
}
bool unite(int x, int y) {
 int px = find(x), py = find(y);
 if (px == py) return false;
 if (rank_[px] < rank_[py]) swap(px, py);
 parent[py] = px;
 if (rank_[px] == rank_[py]) rank_[px]++;
 return true;
}
```

### Dijkstra
```cpp
vector<int> dist(n, INT_MAX);
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
dist[src] = 0;
pq.push({0, src});
while (!pq.empty()) {
 auto [d, u] = pq.top(); pq.pop();
 if (d > dist[u]) continue; // stale entry
 for (auto [v, w] : adj[u]) {
 if (dist[u] + w < dist[v]) {
 dist[v] = dist[u] + w;
 pq.push({dist[v], v});
 }
 }
}
```

### Monotonic Stack (Next Greater Element)
```cpp
vector<int> result(n, -1);
stack<int> st; // stores indices
for (int i = 0; i < n; i++) {
 while (!st.empty() && arr[st.top()] < arr[i]) {
 result[st.top()] = arr[i];
 st.pop();
 }
 st.push(i);
}
```

---

## Edge Cases Checklist

Always consider before submitting:
- [ ] Empty input (`n = 0`, empty array/string)
- [ ] Single element (`n = 1`)
- [ ] All elements the same
- [ ] Already sorted (ascending and descending)
- [ ] Duplicates
- [ ] Negative numbers (if applicable)
- [ ] Maximum constraints (`n = 10^5`, values up to `10^9`)
- [ ] Integer overflow — use `long long` when `int * int` can exceed 2^31
- [ ] Off-by-one in loop bounds and array indices
- [ ] Disconnected graph (if graph problem)
- [ ] Cycle in graph (if path problem)

---

## C++ STL Quick Reference

### Useful Containers
```cpp
vector<int> v; // dynamic array
unordered_map<int,int> mp; // hash map O(1)
map<int,int> ordered_mp; // sorted map O(log n)
unordered_set<int> st; // hash set O(1)
set<int> ordered_st; // sorted set O(log n)
priority_queue<int> maxpq; // max-heap
priority_queue<int,vector<int>,greater<int>> minpq; // min-heap
queue<int> q; // FIFO
deque<int> dq; // double-ended queue
stack<int> stk; // LIFO
```

### Useful Algorithms
```cpp
sort(v.begin(), v.end()); // O(n log n)
sort(v.begin(), v.end(), greater<int>()); // descending
reverse(v.begin(), v.end());
int mx = *max_element(v.begin(), v.end());
int mn = *min_element(v.begin(), v.end());
int sum = accumulate(v.begin(), v.end(), 0);
auto it = lower_bound(v.begin(), v.end(), x); // first >= x
auto it = upper_bound(v.begin(), v.end(), x); // first > x
```

### Bit Manipulation
```cpp
x & (x-1) // clear lowest set bit; x & (x-1) == 0 iff x is power of 2
x & (-x) // isolate lowest set bit
x | (1 << i) // set bit i
x & ~(1 << i) // clear bit i
x ^ (1 << i) // toggle bit i
(x >> i) & 1 // check bit i
__builtin_popcount(x) // count set bits
```

### Math
```cpp
__gcd(a, b) // GCD
lcm(a, b) = a / __gcd(a,b) * b // LCM (avoid overflow)
// Sum 1..n = n*(n+1)/2
// Combinations C(n,k) = n! / (k! * (n-k)!)
```

---

## Interview Tips

**Before coding:**
1. Read the problem twice
2. Ask clarifying questions (constraints, edge cases, output format)
3. Work through 2-3 examples by hand
4. Identify the pattern
5. State your approach and complexity before coding
6. Get confirmation

**While coding:**
- Think out loud
- Use meaningful variable names
- Handle edge cases explicitly
- Write clean, readable code

**After coding:**
- Trace through your code with an example
- Test edge cases mentally
- State time and space complexity
- Discuss possible optimizations
