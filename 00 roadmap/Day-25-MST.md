---
day: 25
topic: MST - Kruskal & Prim
tags:
  - roadmap
  - dsa/topics/graph
  - dsa/topics/dsu
created: 2026-05-20
---
# Day 25 - Minimum Spanning Tree

## Lý thuyết

### MST definition

Cây con của graph có:
- Tất cả V vertices
- V - 1 cạnh
- Tổng weight nhỏ nhất

### Kruskal's Algorithm

Greedy + DSU. Sort cạnh, thêm cạnh không tạo cycle.

```cpp
struct Edge { int u, v, w; };

int kruskal(int n, vector<Edge>& edges) {
    sort(all(edges), [](Edge a, Edge b) { return a.w < b.w; });
    DSU dsu(n);
    int total = 0, count = 0;
    for (auto& e : edges) {
        if (dsu.unite(e.u, e.v)) {
            total += e.w;
            if (++count == n - 1) break;
        }
    }
    return count == n - 1 ? total : -1;  // -1 nếu không connected
}
```

Complexity: O(E log E).

### Prim's Algorithm

Greedy, dùng priority queue. Tương tự Dijkstra.

```cpp
int prim(int n) {
    vector<int> minEdge(n, INT_MAX);
    vector<bool> inMST(n, false);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    minEdge[0] = 0;
    pq.push({0, 0});
    int total = 0, count = 0;
    while (!pq.empty()) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        total += w;
        count++;
        for (auto [v, weight] : adj[u]) {
            if (!inMST[v] && weight < minEdge[v]) {
                minEdge[v] = weight;
                pq.push({weight, v});
            }
        }
    }
    return count == n ? total : -1;
}
```

Complexity: O((V+E) log V).

### Khi nào dùng cái nào

| Graph | Algorithm |
|-------|-----------|
| Sparse (E ~ V) | Kruskal |
| Dense (E ~ V^2) | Prim với matrix |
| Small V, all-pairs | Prim |

## Patterns

### Min Cost to Connect All Points

Tạo edge giữa mọi pair, dùng Kruskal hoặc Prim.

```cpp
int minCostConnectPoints(vector<vector<int>>& points) {
    int n = points.size();
    vector<tuple<int,int,int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int d = abs(points[i][0] - points[j][0]) + 
                    abs(points[i][1] - points[j][1]);
            edges.push_back({d, i, j});
        }
    }
    sort(all(edges));
    DSU dsu(n);
    int total = 0;
    for (auto [d, u, v] : edges) {
        if (dsu.unite(u, v)) total += d;
    }
    return total;
}
```

### Critical & Pseudo-Critical Edges

Critical: bỏ thì MST tăng cost. Test bằng cách bỏ cạnh, tính MST.
Pseudo: có thể có trong MST nào đó. Force include rồi tính MST.

## Practice

### Medium

- [ ] Min Cost to Connect All Points (LC #1584)
- [ ] Connecting Cities With Minimum Cost (LC #1135)
- [ ] Optimize Water Distribution in a Village (LC #1168) - virtual node trick

### Hard

- [ ] Find Critical and Pseudo-Critical Edges in MST (LC #1489)
- [ ] Optimize Water Distribution (LC #1168)

---

**Next**: [[Day-26-DP-1D]]
