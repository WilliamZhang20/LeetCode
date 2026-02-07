class Leaderboard {
    unordered_map<int, int> score;
    multiset<int> ms;

public:
    void addScore(int playerId, int s) {
        if (score.count(playerId)) {
            ms.erase(ms.find(score[playerId]));
        }
        score[playerId] += s;
        ms.insert(score[playerId]);
    }

    int top(int K) {
        int sum = 0;
        auto it = ms.rbegin();
        while (K-- && it != ms.rend()) {
            sum += *it;
            ++it;
        }
        return sum;
    }

    void reset(int playerId) {
        ms.erase(ms.find(score[playerId]));
        score.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */