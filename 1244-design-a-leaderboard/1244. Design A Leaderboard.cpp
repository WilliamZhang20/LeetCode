class Leaderboard {
    unordered_map<int, int> track;
public:
    Leaderboard() {}
    
    void addScore(int playerId, int score) {
        track[playerId] += score;
    }
    
    int top(int K) {
        priority_queue<int, vector<int>, greater<int>> scores;
        for(auto& [_, v] : track) {
            scores.push(v);
            if(scores.size() > K) {
                scores.pop();
            }
        }
        int ans = 0;
        while(!scores.empty()) {
            ans += scores.top();
            scores.pop();
        }
        return ans;
    }
    
    void reset(int playerId) {
        track[playerId] = 0;
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */