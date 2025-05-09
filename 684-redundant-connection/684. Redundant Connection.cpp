class DSU {
private:
    int N;
    vector<int> size;
    vector<int> representative;
public:
    DSU(int n) {
        this->N = n;

        for(int node=0; node<N; node++) {
            size.push_back(1);
            representative.push_back(node);
        }
    }

    int find(int node) {
        if(representative[node] == node) {
            return node;
        }
        return representative[node] = find(representative[node]);
    }

    bool doUnion(int node1, int node2) {
        node1 = find(node1);
        node2 = find(node2);
        if(node1 == node2) {
            return false;
        }
        if(size[node1] > size[node2]) {
            representative[node2] = node1;
            size[node1] += size[node2];
        } else {
            representative[node1] = node2;
            size[node2] += size[node1];
        }
        return true;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        DSU dsu(N);
        for(auto edge : edges) {
            if(!dsu.doUnion(edge[0] - 1, edge[1] - 1)) {
                return edge;
            }
        }

        return {};
    }
};