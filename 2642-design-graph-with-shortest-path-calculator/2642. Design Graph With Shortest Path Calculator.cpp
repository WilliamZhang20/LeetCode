class Graph {
    vector<vector<int>> dist;
    int n;
public:
    Graph(int n, vector<vector<int>>& edges) {
        this->n = n;
        dist.resize(n, vector<int>(n, INT_MAX));
        for(int i=0; i<edges.size(); i++) {
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
        }
        for(int i=0; i<n; i++) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        dist[edge[0]][edge[1]] = edge[2];
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    
    int shortestPath(int node1, int node2) {
        return dist[node1][node2] != INT_MAX ? dist[node1][node2] : -1;
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */