---
day: 23
topic: Topological Sort & DAG
tags:
  - roadmap
  - dsa/topics/graph
created: 2026-05-20
---
# Day 23 - Topological Sort

## Lý thuyết

### Topological order

Sắp xếp các node trong DAG sao cho với mọi cạnh `u -> v`, `u` đứng trước `v`.

Tồn tại khi và chỉ khi graph là DAG (không có cycle).

### Kahn's Algorithm (BFS)

```cpp
vector<int> topoSort(int n) {
    vector<int> indeg(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indeg[v]++;
    
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);
    
    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    
    if (order.size() != n) return {};  // cycle exists
    return order;
}
```

### DFS-based

```cpp
vector<int> order;
vector<int> color;  // 0 = unvisited, 1 = in stack, 2 = done

bool dfs(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return false;  // cycle
        if (color[v] == 0 && !dfs(v)) return false;
    }
    color[u] = 2;
    order.push_back(u);
    return true;
}

vector<int> topoSortDfs(int n) {
    color.assign(n, 0);
    order.clear();
    for (int i = 0; i < n; i++)
        if (color[i] == 0 && !dfs(i)) return {};
    reverse(all(order));
    return order;
}
```

### DP on DAG

Khi DAG, có thể DP theo topological order.

```cpp
// Longest path in DAG
vector<int> dist(n, 0);
auto order = topoSort(n);
for (int u : order) {
    for (auto [v, w] : adj[u]) {
        dist[v] = max(dist[v], dist[u] + w);
    }
}
```

### Course Schedule pattern

```cpp
bool canFinish(int n, vector<vector<int>>& prereqs) {
    vector<vector<int>> adj(n);
    vector<int> indeg(n, 0);
    for (auto& p : prereqs) {
        adj[p[1]].push_back(p[0]);
        indeg[p[0]]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indeg[i] == 0) q.push(i);
    int count = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        count++;
        for (int v : adj[u]) {
            if (--indeg[v] == 0) q.push(v);
        }
    }
    return count == n;
}
```

## Practice

### Medium

- [ ] Course Schedule (LC #207)
- [ ] Course Schedule II (LC #210)
- [ ] Find Eventual Safe States (LC #802)
- [ ] All Paths From Source to Target (LC #797)
- [ ] Minimum Height Trees (LC #310)

### Hard

- [ ] Alien Dictionary (LC #269)
- [ ] Parallel Courses III (LC #2050) - DAG DP
- [ ] Sort Items by Groups Respecting Dependencies (LC #1203)

## Tips

- Topo sort tồn tại <=> DAG
- Kahn's BFS trả về 1 thứ tự lexicographically (dùng priority_queue thay queue)
- Có thể dùng để tìm cycle trong directed graph

---

**Next**: [[Day-24-DSU]]
