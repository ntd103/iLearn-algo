---
day: 21
topic: Graphs - Representation, DFS, BFS
tags:
  - roadmap
  - dsa/topics/graph
created: 2026-05-20
---
# Day 21 - Graphs: Representation, DFS, BFS

## Lý thuyết

### Representations

#### Adjacency List

```cpp
vector<vector<int>> adj(n);          // unweighted
vector<vector<pii>> adj(n);          // weighted: {neighbor, weight}

// Undirected
adj[u].push_back(v);
adj[v].push_back(u);

// Directed
adj[u].push_back(v);
```

Memory: O(V + E). **Khuyến khích trong CP**.

#### Adjacency Matrix

```cpp
vector<vector<int>> adj(n, vector<int>(n, 0));
adj[u][v] = 1;
```

Memory: O(V^2). Chỉ dùng khi V nhỏ (<= 1000).

#### Edge List

```cpp
vector<tuple<int,int,int>> edges;  // {u, v, w}
edges.push_back({u, v, w});
```

Use case: Kruskal's MST, Bellman-Ford.

### DFS

```cpp
vector<bool> visited(n, false);

void dfs(int u) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}
```

Iterative với stack:

```cpp
void dfs_iter(int src) {
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) st.push(v);
        }
    }
}
```

### BFS - tính shortest path (số cạnh)

```cpp
vector<int> bfs(int src, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}
```

### Connected Components

```cpp
int countComponents(int n) {
    vector<bool> visited(n, false);
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { dfs(i); count++; }
    }
    return count;
}
```

### Cycle Detection

#### Undirected

```cpp
bool hasCycle(int u, int parent) {
    visited[u] = true;
    for (int v : adj[u]) {
        if (!visited[v]) {
            if (hasCycle(v, u)) return true;
        } else if (v != parent) return true;
    }
    return false;
}
```

#### Directed (3-color DFS)

```cpp
// 0 = unvisited, 1 = in stack, 2 = done
vector<int> color(n, 0);

bool hasCycle(int u) {
    color[u] = 1;
    for (int v : adj[u]) {
        if (color[v] == 1) return true;     // back edge
        if (color[v] == 0 && hasCycle(v)) return true;
    }
    color[u] = 2;
    return false;
}
```

### Bipartite Check (2-coloring)

```cpp
bool isBipartite(int n) {
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++) {
        if (color[i] != -1) continue;
        queue<int> q;
        q.push(i);
        color[i] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = 1 - color[u];
                    q.push(v);
                } else if (color[v] == color[u]) return false;
            }
        }
    }
    return true;
}
```

### Grid as Graph

```cpp
int dx[] = {-1, 1, 0, 0};  // 4 directions
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
        if (visited[nx][ny] || grid[nx][ny] == '0') continue;
        visited[nx][ny] = true;
        dfs(nx, ny);
    }
}
```

## Practice

### Medium

- [ ] Number of Islands (LC #200)
- [ ] Clone Graph (LC #133)
- [ ] Pacific Atlantic Water Flow (LC #417)
- [ ] Course Schedule (LC #207)
- [ ] Number of Provinces (LC #547)
- [ ] Rotting Oranges (LC #994)
- [ ] Walls and Gates (LC #286)
- [ ] Surrounded Regions (LC #130)
- [ ] Is Graph Bipartite (LC #785)
- [ ] Word Ladder (LC #127)

### Hard

- [ ] Word Ladder II (LC #126)
- [ ] Longest Increasing Path in a Matrix (LC #329) - DFS + memo

---

**Next**: [[Day-22-Shortest-Paths]]
