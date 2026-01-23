class Solution {
public:
    static constexpr int MOD = 1e9 + 7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        using A = array<int,2>; // {price, amount}
        priority_queue<A, vector<A>, greater<>> ask;
        priority_queue<A> bid;

        for (auto &o : orders) {
            int p = o[0], a = o[1], t = o[2];

            if (t == 0) { // buy
                while (a && !ask.empty() && ask.top()[0] <= p) {
                    auto cur = ask.top(); ask.pop();
                    int m = min(a, cur[1]);
                    a -= m;
                    cur[1] -= m;
                    if (cur[1]) ask.push(cur);
                }
                if (a) bid.push({p, a});
            } else { // sell
                while (a && !bid.empty() && bid.top()[0] >= p) {
                    auto cur = bid.top(); bid.pop();
                    int m = min(a, cur[1]);
                    a -= m;
                    cur[1] -= m;
                    if (cur[1]) bid.push(cur);
                }
                if (a) ask.push({p, a});
            }
        }

        long long res = 0;
        while (!bid.empty()) res = (res + bid.top()[1]) % MOD, bid.pop();
        while (!ask.empty()) res = (res + ask.top()[1]) % MOD, ask.pop();
        return res;
    }
};
