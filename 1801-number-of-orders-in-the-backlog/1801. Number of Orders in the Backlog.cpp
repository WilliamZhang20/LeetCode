class Solution {
public:
    static constexpr int MOD = 1e9+7;
    using Order = array<int,2>;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // buy want smallest sell, sell wants largest buy
        priority_queue<Order, vector<Order>, greater<>> asks;
        priority_queue<Order> bids;
        
        for(auto& order: orders) {
            int p = order[0], a = order[1], t = order[2];
            if(t == 0) { // incoming buy order (bid)
                // if match with cheapest sell, clear
                while(a > 0 && !asks.empty() && asks.top()[0] <= p) {
                    auto cur = asks.top();
                    asks.pop();
                    int matched = min(a, cur[1]);
                    // decrement amount
                    // decrement sellAmount
                    a -= matched;
                    cur[1] -= matched;
                    
                    // if sellAmount > 0, push back into asks
                    if(cur[1]) asks.push(cur);
                }
                // else if amount > 0, push into bids
                if (a) bids.push({p, a});
            } else { // incoming sell order (ask)
                // if match with most expensive buy, clear
                while(a && !bids.empty() && bids.top()[0] >= p) {
                    auto cur = bids.top();
                    bids.pop();
                    int matched = min(a, cur[1]);
                    a -= matched;
                    cur[1] -= matched;
                    if(cur[1]) bids.push(cur);
                }
                if(a) asks.push({p, a});
            }
        }
        long long res = 0;
        while (!bids.empty()) res = (res + bids.top()[1]) % MOD, bids.pop();
        while (!asks.empty()) res = (res + asks.top()[1]) % MOD, asks.pop();
        return res;
    }
};