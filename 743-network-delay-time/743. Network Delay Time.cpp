class Solution {
public:
    void dijkstra(vector<vector<pair<int,int>>>& adj,
                  vector<int>& signalRcvdAt,
                  int source) {

        priority_queue<pair<int,int>,
                       vector<pair<int,int>>,
                       greater<pair<int,int>>> pq;

        pq.emplace(0, source);
        signalRcvdAt[source] = 0;

        while (!pq.empty()) {
            auto [currTime, currNode] = pq.top();
            pq.pop();

            if (currTime > signalRcvdAt[currNode])
                continue;

            for (auto& [time, neighbor] : adj[currNode]) {
                if (signalRcvdAt[neighbor] > currTime + time) {
                    signalRcvdAt[neighbor] = currTime + time;
                    pq.emplace(signalRcvdAt[neighbor], neighbor);
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // Build adjacency list dynamically
        vector<vector<pair<int,int>>> adj(n + 1);

        for (auto& time : times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            adj[source].emplace_back(travelTime, dest);
        }

        vector<int> signalRcvdAt(n + 1, INT_MAX);

        dijkstra(adj, signalRcvdAt, k);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (signalRcvdAt[i] == INT_MAX)
                return -1;
            ans = max(ans, signalRcvdAt[i]);
        }

        return ans;
    }
};
