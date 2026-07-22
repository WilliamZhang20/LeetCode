class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // min heap 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> sell;
        // max heap
        long long buyTotal = 0;
        long long sellTotal = 0;
        priority_queue<pair<int, int>> buy;
        for(auto& order: orders) {
            int price = order[0];
            int amount = order[1];
            int type = order[2];
            if(!type) {
                while(amount > 0 && !sell.empty() && sell.top().first <= price) {
                    auto [sellPrice, sellAmount] = sell.top();
                    sell.pop();
                    int matched = min(amount, sellAmount);
                    amount -= matched;
                    sellAmount -= matched;
                    sellTotal -= matched;

                    if (sellAmount > 0) {
                        sell.emplace(sellPrice, sellAmount);
                    }
                }

                if (amount > 0) {
                    buy.emplace(price, amount);
                    buyTotal += amount;
                }   
            } else {
                 while (amount > 0 &&
                       !buy.empty() &&
                       buy.top().first >= price) {

                    auto [buyPrice, buyAmount] = buy.top();
                    buy.pop();

                    int matched = min(amount, buyAmount);

                    amount -= matched;
                    buyAmount -= matched;
                    buyTotal -= matched;

                    if (buyAmount > 0) {
                        buy.emplace(buyPrice, buyAmount);
                    }
                }

                if (amount > 0) {
                    sell.emplace(price, amount);
                    sellTotal += amount;
                }
            }
        }
        const int MOD = 1e9 + 7;
        return (buyTotal + sellTotal) % MOD;
    }
};