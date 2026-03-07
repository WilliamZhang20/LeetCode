class UnionFind {
    vector<int> parent;
    vector<int> size;
public:
    UnionFind(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); 
        size.assign(n, 1);
    }
    int find(int a) {
        int root = a;
        while(parent[root] != root) {
            root = parent[root];
        }
        while(a != root) {
            int oldRoot = parent[a];
            parent[a] = root;
            a = oldRoot;
        }
        return a;
    }
    bool Union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if(rootA == rootB) {
            return false;
        }
        if(size[rootA] < size[rootB]) {
            parent[rootA] = rootB;
            size[rootB] += size[rootA];
        }
        else {
            parent[rootB] = rootA;
            size[rootA] += size[rootB];
        }
        return true;
    }
};
class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() != n-1) return false;
        UnionFind uf(n);
        for(auto& edge: edges) {
            if(!uf.Union(edge[0], edge[1])) {
                return false;
            }
        }
        return true;
    }
};