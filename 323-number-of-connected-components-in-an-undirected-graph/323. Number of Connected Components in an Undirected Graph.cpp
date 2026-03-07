class Solution {
public:
    int find(vector<int>& rep, int v) {
        if(v == rep[v]) {
            return v;
        }
        return rep[v] = find(rep, rep[v]);
    }
    int combine(vector<int>& rep, vector<int>& size, int v1, int v2) {
        v1 = find(rep, v1);
        v2 = find(rep, v2);
        if(v1 == v2) {
            return 0;
        }
        if(size[v1] > size[v2]) {
            rep[v2] = v1;
            size[v1] += size[v2];
        }
        else {
            rep[v1] = v2;
            size[v2] += size[v1];
        }
        return 1;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> rep(n), size(n, 1);
        iota(rep.begin(), rep.end(), 0);
        int count = n;
        for(auto& edge: edges) {
            if(combine(rep, size, edge[0], edge[1])) {
                count -= 1;
            }
        }
        return count;
    }
};