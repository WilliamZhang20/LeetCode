class Solution {
    vector<pair<int, int>> adj[101];
public:
    void dijkstra(vector<int>& signalRcvdAt, int source, int n) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, source);
        signalRcvdAt[source] = 0;
        while(!pq.empty()) {
            int currNodetime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
            if(currNodetime > signalRcvdAt[currNode]) {
                continue;
            }
            for(auto& edge: adj[currNode]) {
                int time = edge.first;
                int neighborNode = edge.second;
                if(signalRcvdAt[neighborNode] > currNodetime + time) {
                    signalRcvdAt[neighborNode] = currNodetime + time;
                    pq.emplace(signalRcvdAt[neighborNode], neighborNode);
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto time: times) {
            int source = time[0];
            int dest = time[1];
            int travelTime = time[2];
            adj[source].emplace_back(travelTime, dest);
        }
        vector<int> signalRcvdAt(n+1, INT_MAX);
        dijkstra(signalRcvdAt, k, n);
        int ans = INT_MIN;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, signalRcvdAt[i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};