class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {
        int maxQuality = 0;
        vector<int> result; // coordinates
        for(int i=0; i<towers.size(); i++) {
            int x = towers[i][0];
            int y = towers[i][1];
            int q = towers[i][2];
            int dist = abs(x - center[0]) + abs(y - center[1]);
            if(dist <= radius) {
                if(q > maxQuality) {
                    result = {x, y};
                    maxQuality = q;
                } else if(q == maxQuality) {
                    if(result.empty() || x < result[0]  || (x == result[0] && y < result[1])) {
                        result = {x, y};
                    }
                }
            }
        }
        if(result.empty()) {
            return {-1, -1};
        }
        return result;
    }
};