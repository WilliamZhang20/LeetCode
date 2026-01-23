class Solution {
public:
    static constexpr int MOD = 1e9+7;
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // buy want smallest sell, sell wants largest buy
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> asks;
        priority_queue<pair<int, int>, vector<pair<int, int>>> bids;
        
        for(auto& order: orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            if(type == 0) { // incoming buy order (bid)
                // if match with cheapest sell, clear
                while(amount > 0 && !asks.empty() && asks.top().first <= price) {
                    auto [sellPrice, sellAmount] = asks.top();
                    asks.pop();
                    int matched = min(amount, sellAmount);
                    // decrement amount
                    // decrement sellAmount
                    amount -= matched;
                    sellAmount -= matched;
                    
                    // if sellAmount > 0, push back into asks
                    if(sellAmount > 0) {
                        asks.emplace(sellPrice, sellAmount);
                    }
                }
                // else if amount > 0, push into bids
                if(amount > 0) {
                    bids.emplace(price, amount);
                }
            } else { // incoming sell order (ask)
                // if match with most expensive buy, clear
                while(amount > 0 && !bids.empty() && bids.top().first >= price) {
                    auto [bPrice, bAmount] = bids.top();
                    bids.pop();
                    int matched = min(amount, bAmount);
                    amount -= matched;
                    bAmount -= matched;
                    if(bAmount > 0) {
                        bids.emplace(bPrice, bAmount);
                    }
                }
                if(amount > 0) {
                    asks.emplace(price, amount);
                }
            }
        }
        long long count = 0;
        while(!bids.empty()) {
            count += bids.top().second;
            bids.pop();
            count %= MOD;
        }
        while(!asks.empty()) {
            count += asks.top().second;
            asks.pop();
            count %= MOD;
        }
        return int(count);
    }
};