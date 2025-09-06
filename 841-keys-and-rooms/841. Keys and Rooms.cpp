class Solution {
private:
    vector<bool> vis;
public:
    void dfs(int source, vector<vector<int>>& rooms) {
        vis[source] = true;
        for(int i=0; i < rooms[source].size(); i++) {
            if(!vis[rooms[source][i]]) {
                dfs(rooms[source][i], rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vis.assign(n, false);
        dfs(0, rooms);
        return std::reduce(vis.begin(), vis.end(), true, std::logical_and<>());
    }
};