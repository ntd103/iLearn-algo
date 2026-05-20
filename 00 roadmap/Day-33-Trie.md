---
day: 33
topic: Trie
tags:
  - roadmap
  - dsa/topics/trie
created: 2026-05-20
---
# Day 33 - Trie (Prefix Tree)

## Lý thuyết

### Definition

Cây dùng để lưu strings, mỗi node represent 1 ký tự, path từ root -> node = prefix.

### Implementation

```cpp
struct Trie {
    Trie* children[26] = {};
    bool isEnd = false;
    
    void insert(string& word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->isEnd = true;
    }
    
    bool search(string& word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return node->isEnd;
    }
    
    bool startsWith(string& prefix) {
        Trie* node = this;
        for (char c : prefix) {
            int i = c - 'a';
            if (!node->children[i]) return false;
            node = node->children[i];
        }
        return true;
    }
};
```

### Map-based (cho character set lớn)

```cpp
struct Trie {
    unordered_map<char, Trie*> children;
    bool isEnd = false;
    // ...
};
```

### Array với uint16_t cho memory

```cpp
// CP: tạo array tĩnh thay vì pointer để nhanh
const int MAXN = 1e6;
int trie[MAXN][26];
bool isEnd[MAXN];
int trieSize = 1;  // root = 0

void insert(string& s) {
    int u = 0;
    for (char c : s) {
        int i = c - 'a';
        if (!trie[u][i]) trie[u][i] = trieSize++;
        u = trie[u][i];
    }
    isEnd[u] = true;
}
```

### Use cases

#### Prefix matching

Word search II (LC #212), implementing autocomplete.

#### Maximum XOR

```cpp
// Trie với 32 bit nhị phân
int findMaxXOR(vector<int>& nums) {
    Trie* root = new Trie();
    int max_xor = 0;
    for (int x : nums) {
        Trie* cur = root;
        Trie* find = root;
        int cur_xor = 0;
        for (int b = 30; b >= 0; b--) {
            int bit = (x >> b) & 1;
            int opp = 1 - bit;
            if (!cur->children[bit]) cur->children[bit] = new Trie();
            cur = cur->children[bit];
            
            if (find->children[opp]) {
                cur_xor |= (1 << b);
                find = find->children[opp];
            } else {
                find = find->children[bit];
            }
        }
        max_xor = max(max_xor, cur_xor);
    }
    return max_xor;
}
```

#### Word Search II với Trie

```cpp
void dfs(vector<vector<char>>& board, int i, int j, Trie* node, vector<string>& ans, string& path) {
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()) return;
    char c = board[i][j];
    if (c == '#' || !node->children[c - 'a']) return;
    
    node = node->children[c - 'a'];
    path += c;
    if (node->isEnd) {
        ans.push_back(path);
        node->isEnd = false;  // tránh duplicate
    }
    
    board[i][j] = '#';
    dfs(board, i+1, j, node, ans, path);
    dfs(board, i-1, j, node, ans, path);
    dfs(board, i, j+1, node, ans, path);
    dfs(board, i, j-1, node, ans, path);
    board[i][j] = c;
    path.pop_back();
}
```

## Practice

### Medium

- [ ] Implement Trie (LC #208)
- [ ] Design Add and Search Words (LC #211) - wildcard
- [ ] Replace Words (LC #648)
- [ ] Map Sum Pairs (LC #677)
- [ ] Implement Magic Dictionary (LC #676)

### Hard

- [ ] Word Search II (LC #212)
- [ ] Maximum XOR of Two Numbers in Array (LC #421)
- [ ] Concatenated Words (LC #472)
- [ ] Stream of Characters (LC #1032)
- [ ] Palindrome Pairs (LC #336)

## Memory tip

Trie có thể dùng nhiều memory. Pre-allocate static array nếu biết max size.

---

**Next**: [[Day-34-Segment-Tree-Fenwick]]
