---
day: 22
topic: Shortest Paths - Dijkstra & Bellman-Ford
tags:
  - roadmap
  - dsa/topics/graph
created: 2026-05-20
---
# Day 22 - Shortest Paths

## Lý thuyết

### Tổng quan

| Algorithm | Use case | Complexity | Negative weights |
|-----------|----------|------------|------------------|
| BFS | Unweighted | O(V+E) | N/A |
| 0-1 BFS | Weights 0 or 1 | O(V+E) | No |
| Dijkstra | Non-negative weights | O((V+E) log V) | No |
| Bellman-Ford | Negative weights | O(VE) | Yes |
| Floyd-Warshall | All pairs | O(V^3) | Yes |

### Dijkstra

```cpp
vector<int> dijkstra(int src, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});  // {distance, node}
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

**Lưu ý**:
- Không hoạt động với negative weights
- Lazy deletion: skip nếu `d > dist[u]`

### Bellman-Ford

```cpp
vector<int> bellmanFord(int src, int n, vector<tuple<int,int,int>>& edges) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    // Check negative cycle
    for (auto [u, v, w] : edges) {
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            // negative cycle exists
        }
    }
    return dist;
}
```

### Floyd-Warshall

```cpp
void floyd(vector<vector<int>>& dist, int n) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

### 0-1 BFS

Khi cạnh chỉ có weight 0 hoặc 1:

```cpp
vector<int> zeroOneBfs(int src, int n) {
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    deque<int> dq;
    dq.push_front(src);
    while (!dq.empty()) {
        int u = dq.front(); dq.pop_front();
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                if (w == 0) dq.push_front(v);
                else dq.push_back(v);
            }
        }
    }
    return dist;
}
```

### Reconstruct path

```cpp
vector<int> parent(n, -1);
// trong khi update dist[v]: parent[v] = u

vector<int> path;
for (int u = dst; u != -1; u = parent[u]) path.push_back(u);
reverse(all(path));
```

## Practice

### Medium

- [ ] Network Delay Time (LC #743) - Dijkstra
- [ ] Cheapest Flights Within K Stops (LC #787) - Bellman-Ford
- [ ] Path with Minimum Effort (LC #1631)
- [ ] Min Cost to Connect All Points (LC #1584) - MST hoặc Dijkstra
- [ ] Path with Maximum Probability (LC #1514)
- [ ] Find the City With Smallest Number of Neighbors (LC #1334) - Floyd

### Hard

- [ ] Reachable Nodes In Subdivided Graph (LC #882)
- [ ] Minimum Cost to Make at Least One Valid Path (LC #1368) - 0-1 BFS

## Mistakes thường gặp

- Dùng Dijkstra cho graph có negative edge -> sai
- Quên `if (d > dist[u]) continue;` -> TLE
- Dùng `int` cho dist khi sum có thể overflow -> long long

---

**Next**: [[Day-23-Topological-Sort]]
