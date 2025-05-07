class Solution {
int INF = 10000;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int, vector<pair<int, int>>> graph;
        vector<int> dist(n+1, INF);
        for(int i=0; i<times.size(); i++) {
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        dist[k] = 0;
        queue<int> q;
        q.push(k);
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(int i=0; i<graph[curr].size(); i++) {
                if(dist[curr] + graph[curr][i].second < dist[graph[curr][i].first]) {
                    dist[graph[curr][i].first] = dist[curr] + graph[curr][i].second;
                    q.push(graph[curr][i].first);
                }
            }
        }
        int count = 0;
        int time = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INF) {
                continue;
            }
            else if(i != k) {
                cout << i << " " << dist[i] << endl;
                time = max(time, dist[i]);
            }
            count++;
        }
        if(count == n) {
            return time;
        }
        return -1;
    }
};