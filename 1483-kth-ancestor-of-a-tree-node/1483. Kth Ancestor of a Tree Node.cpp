class TreeAncestor {
private:
    int LOG;
    vector<vector<int>> up;

public:
    TreeAncestor(int n, vector<int>& parent) {
        LOG = 32 - __builtin_clz(n);  // ceil(log2(n))
        up.assign(n, vector<int>(LOG, -1));
        
        // 2^0 ancestors (direct parents)
        for (int i = 0; i < n; i++) {
            up[i][0] = parent[i];
        }

        // Fill binary lifting table
        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                if (up[i][j - 1] != -1) {
                    up[i][j] = up[up[i][j - 1]][j - 1];
                }
            }
        }
    }

    int getKthAncestor(int node, int k) {
        for (int j = 0; j < LOG; j++) {
            if (k & (1 << j)) {
                node = up[node][j];
                if (node == -1)
                    return -1;
            }
        }
        return node;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */