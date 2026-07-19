class DSU {
public:
    vector<int> size;
    vector<int> rep;
    DSU(int sz) {
        size.resize(sz+1, 1);
        rep.resize(sz+1);
        for(int i=0; i<=sz; i++) {
            rep[i] = i;
        }
    }
    int find(int i) {
        if(rep[i] == i) {
            return i;
        }
        return rep[i] = find(rep[i]);
    }

    bool doUnion(int i, int j) {
        int a = find(i);
        int b = find(j);
        if(a == b) return false;
        if(size[a] < size[b]) {
            swap(a, b);
        }
        rep[b] = a;
        size[a] += size[b];
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        DSU graph(edges.size());
        for(auto& edge: edges) {
            // do union from those
            if(!graph.doUnion(edge[0], edge[1])) {
                return edge;
            }
        }
        return {};
    }
};