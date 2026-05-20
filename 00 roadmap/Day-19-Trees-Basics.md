---
day: 19
topic: Trees Basics & Traversal
tags:
  - roadmap
  - dsa/topics/tree
created: 2026-05-20
---
# Day 19 - Trees Basics & Traversal

## Lý thuyết

### Definition

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

### Terminology

- **Root**: Node trên cùng
- **Leaf**: Node không có con
- **Height**: longest path từ root đến leaf
- **Depth**: distance từ root đến node
- **Diameter**: longest path giữa 2 nodes

### Traversal

#### DFS - 3 cách

```cpp
// Preorder: root -> left -> right
void preorder(TreeNode* root) {
    if (!root) return;
    visit(root);
    preorder(root->left);
    preorder(root->right);
}

// Inorder: left -> root -> right
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    visit(root);
    inorder(root->right);
}

// Postorder: left -> right -> root
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    visit(root);
}
```

#### Iterative DFS với stack

```cpp
// Inorder iterative
vector<int> inorderIter(TreeNode* root) {
    vector<int> ans;
    stack<TreeNode*> st;
    TreeNode* cur = root;
    while (cur || !st.empty()) {
        while (cur) { st.push(cur); cur = cur->left; }
        cur = st.top(); st.pop();
        ans.push_back(cur->val);
        cur = cur->right;
    }
    return ans;
}
```

#### BFS - Level Order

```cpp
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if (!root) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        ans.push_back(level);
    }
    return ans;
}
```

### Common patterns

#### Height

```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}
```

#### Diameter

```cpp
int diameter = 0;
int dfs(TreeNode* root) {
    if (!root) return 0;
    int l = dfs(root->left);
    int r = dfs(root->right);
    diameter = max(diameter, l + r);
    return 1 + max(l, r);
}
```

#### Path Sum (root to leaf)

```cpp
bool hasPathSum(TreeNode* root, int target) {
    if (!root) return false;
    if (!root->left && !root->right) return target == root->val;
    return hasPathSum(root->left, target - root->val) ||
           hasPathSum(root->right, target - root->val);
}
```

### Construct from Traversal

```cpp
// Build từ preorder + inorder
TreeNode* build(vector<int>& pre, vector<int>& in) {
    unordered_map<int,int> idx;
    for (int i = 0; i < in.size(); i++) idx[in[i]] = i;
    int p = 0;
    function<TreeNode*(int,int)> rec = [&](int l, int r) -> TreeNode* {
        if (l > r) return nullptr;
        TreeNode* root = new TreeNode(pre[p++]);
        int m = idx[root->val];
        root->left = rec(l, m - 1);
        root->right = rec(m + 1, r);
        return root;
    };
    return rec(0, in.size() - 1);
}
```

## Practice

### Easy

- [ ] Maximum Depth of Binary Tree (LC #104)
- [ ] Invert Binary Tree (LC #226)
- [ ] Same Tree (LC #100)
- [ ] Symmetric Tree (LC #101)
- [ ] Subtree of Another Tree (LC #572)
- [ ] Diameter of Binary Tree (LC #543)
- [ ] Balanced Binary Tree (LC #110)

### Medium

- [ ] Binary Tree Level Order Traversal (LC #102)
- [ ] Binary Tree Zigzag Level Order (LC #103)
- [ ] Construct Binary Tree from Preorder and Inorder (LC #105)
- [ ] Binary Tree Right Side View (LC #199)
- [ ] Lowest Common Ancestor of Binary Tree (LC #236)
- [ ] Path Sum II (LC #113)
- [ ] Binary Tree Maximum Path Sum (LC #124)

---

**Next**: [[Day-20-BST-Tree-DP]]
