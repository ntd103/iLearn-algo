// ========================================
// Disjoint Set Union (Union-Find)
// Time: O(α(n)) amortized per operation
// ========================================

class DSU {
private:
    vector<int> parent, rank, size;
    int num_components;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);
        num_components = n;
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py)
            return false;

        // Union by rank
        if (rank[px] < rank[py])
            swap(px, py);
        parent[py] = px;
        size[px] += size[py];
        if (rank[px] == rank[py])
            rank[px]++;

        num_components--;
        return true;
    }

    bool connected(int x, int y) {
        return find(x) == find(y);
    }

    int get_size(int x) {
        return size[find(x)];
    }

    int count_components() {
        return num_components;
    }
};

// Usage:
// DSU dsu(n);
// dsu.unite(a, b);
// if (dsu.connected(a, b)) { ... }
