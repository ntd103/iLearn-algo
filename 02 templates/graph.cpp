// ========================================
// Graph Algorithms Library
// ========================================

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

// ============ DIJKSTRA ============
// Time: O((V + E) log V)
vector<ll> dijkstra(int src, const vector<vector<pii>> &graph) {
    int n = graph.size();
    vector<ll> dist(n, LLONG_MAX);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// ============ BELLMAN-FORD ============
// Time: O(VE), detects negative cycles
pair<vector<ll>, bool> bellman_ford(int src, int n, const vector<tuple<int, int, ll>> &edges) {
    vector<ll> dist(n, LLONG_MAX);
    dist[src] = 0;

    // Relax edges n-1 times
    for (int i = 0; i < n - 1; i++) {
        for (auto [u, v, w] : edges) {
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycles
    for (auto [u, v, w] : edges) {
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v]) {
            return {dist, true}; // Negative cycle exists
        }
    }

    return {dist, false};
}

// ============ KRUSKAL MST ============
// Time: O(E log E)
class DSU {
    vector<int> parent, rank;

public:
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }

    bool unite(int x, int y) {
        x = find(x), y = find(y);
        if (x == y)
            return false;
        if (rank[x] < rank[y])
            swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y])
            rank[x]++;
        return true;
    }
};

ll kruskal(int n, vector<tuple<ll, int, int>> &edges) {
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    ll mst_cost = 0;

    for (auto [w, u, v] : edges) {
        if (dsu.unite(u, v)) {
            mst_cost += w;
        }
    }

    return mst_cost;
}

// ============ TOPOLOGICAL SORT ============
// Time: O(V + E)
vector<int> topological_sort(const vector<vector<int>> &graph) {
    int n = graph.size();
    vector<int> indeg(n, 0);

    for (int u = 0; u < n; u++) {
        for (int v : graph[u]) {
            indeg[v]++;
        }
    }

    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indeg[i] == 0)
            q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);

        for (int v : graph[u]) {
            if (--indeg[v] == 0) {
                q.push(v);
            }
        }
    }

    return order.size() == n ? order : vector<int>(); // Empty if cycle exists
}

// ============ STRONGLY CONNECTED COMPONENTS (KOSARAJU) ============
// Time: O(V + E)
class SCC {
private:
    vector<vector<int>> graph, rev_graph;
    vector<bool> visited;
    vector<int> order, comp;
    int n;

    void dfs1(int u) {
        visited[u] = true;
        for (int v : graph[u]) {
            if (!visited[v])
                dfs1(v);
        }
        order.push_back(u);
    }

    void dfs2(int u, int c) {
        comp[u] = c;
        for (int v : rev_graph[u]) {
            if (comp[v] == -1)
                dfs2(v, c);
        }
    }

public:
    SCC(int size) : n(size), graph(n), rev_graph(n), visited(n, false), comp(n, -1) {}

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        rev_graph[v].push_back(u);
    }

    int find_sccs() {
        for (int i = 0; i < n; i++) {
            if (!visited[i])
                dfs1(i);
        }

        reverse(order.begin(), order.end());
        int num_sccs = 0;

        for (int u : order) {
            if (comp[u] == -1) {
                dfs2(u, num_sccs++);
            }
        }

        return num_sccs;
    }

    vector<int> get_components() { return comp; }
};

// ============ BINARY LIFTING LCA ============
// Time: O(n log n) preprocessing, O(log n) per query
class LCA {
private:
    vector<vector<int>> up;
    vector<int> depth;
    int LOG;

    void dfs(int u, int p, const vector<vector<int>> &tree) {
        up[u][0] = p;
        for (int i = 1; i < LOG; i++) {
            if (up[u][i - 1] != -1) {
                up[u][i] = up[up[u][i - 1]][i - 1];
            }
        }

        for (int v : tree[u]) {
            if (v != p) {
                depth[v] = depth[u] + 1;
                dfs(v, u, tree);
            }
        }
    }

public:
    LCA(int n, int root, const vector<vector<int>> &tree) {
        LOG = ceil(log2(n)) + 1;
        up.assign(n, vector<int>(LOG, -1));
        depth.assign(n, 0);
        dfs(root, -1, tree);
    }

    int query(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];
        for (int i = 0; i < LOG; i++) {
            if ((diff >> i) & 1) {
                u = up[u][i];
            }
        }

        if (u == v)
            return u;

        for (int i = LOG - 1; i >= 0; i--) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }
};
