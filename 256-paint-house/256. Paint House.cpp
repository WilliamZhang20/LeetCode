class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        for(int n = costs.size() - 2; n >= 0; n--) {
            costs[n][0] += min(costs[n+1][1], costs[n+1][2]);
            costs[n][1] += min(costs[n+1][0], costs[n+1][2]);
            costs[n][2] += min(costs[n+1][0], costs[n+1][1]);
        }
        return min(min(costs[0][0], costs[0][1]), costs[0][2]);
    }
};