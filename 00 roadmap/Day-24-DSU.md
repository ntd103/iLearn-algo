---
day: 24
topic: Disjoint Set Union (Union-Find)
tags:
  - roadmap
  - dsa/topics/dsu
created: 2026-05-20
---
# Day 24 - DSU (Union-Find)

## Lý thuyết

### Use case

- Connected components dynamic (thêm cạnh)
- Cycle detection
- Kruskal's MST
- Group merging

### Implementation

```cpp
struct DSU {
    vector<int> parent, rank_;
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(all(parent), 0);  // parent[i] = i
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    
    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        // union by rank
        if (rank_[px] < rank_[py]) swap(px, py);
        parent[py] = px;
        if (rank_[px] == rank_[py]) rank_[px]++;
        return true;
    }
    
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
};
```

### Complexity

Với both path compression + union by rank:
- find/unite: O(alpha(n)) - gần như O(1) trong thực tế

### Variations

#### DSU với size

```cpp
vector<int> size_;
// size_[i] = số node trong component có root i

bool unite(int x, int y) {
    int px = find(x), py = find(y);
    if (px == py) return false;
    if (size_[px] < size_[py]) swap(px, py);
    parent[py] = px;
    size_[px] += size_[py];
    return true;
}
```

#### Counting components

```cpp
int components;
DSU(int n) : parent(n), size_(n, 1), components(n) {
    iota(all(parent), 0);
}
bool unite(int x, int y) {
    // ... if successful:
    components--;
    return true;
}
```

#### Weighted DSU

Tracks distance/weight giữa node và root.

```cpp
vector<int> weight;  // distance từ node đến parent

int find(int x) {
    if (parent[x] != x) {
        int root = find(parent[x]);
        weight[x] += weight[parent[x]];
        parent[x] = root;
    }
    return parent[x];
}
```

## Patterns

### Cycle detection in undirected graph

```cpp
DSU dsu(n);
for (auto [u, v] : edges) {
    if (!dsu.unite(u, v)) {
        // cycle found
    }
}
```

### Number of provinces

```cpp
int findCircleNum(vector<vector<int>>& isConn) {
    int n = isConn.size();
    DSU dsu(n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (isConn[i][j]) dsu.unite(i, j);
    set<int> roots;
    for (int i = 0; i < n; i++) roots.insert(dsu.find(i));
    return roots.size();
}
```

### Offline queries

Đảo ngược thứ tự: thay vì xóa cạnh, làm reverse và thêm cạnh.

## Practice

### Medium

- [ ] Number of Provinces (LC #547)
- [ ] Redundant Connection (LC #684)
- [ ] Accounts Merge (LC #721)
- [ ] Number of Connected Components (LC #323)
- [ ] Most Stones Removed (LC #947)
- [ ] Satisfiability of Equality Equations (LC #990)
- [ ] Smallest String With Swaps (LC #1202)

### Hard

- [ ] Bricks Falling When Hit (LC #803) - reverse time
- [ ] Number of Islands II (LC #305) - dynamic islands
- [ ] Couples Holding Hands (LC #765)
- [ ] Swim in Rising Water (LC #778) - DSU + sort

---

**Next**: [[Day-25-MST]]
