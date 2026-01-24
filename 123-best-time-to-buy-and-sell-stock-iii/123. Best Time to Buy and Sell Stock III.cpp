class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int t1_cost = INT_MAX, t1_profit = 0;
        int t2_cost = INT_MAX, t2_profit = 0;
        for(auto& price: prices) {
            t1_cost = min(price, t1_cost);
            t1_profit = max(t1_profit, price - t1_cost); // from part I
            t2_cost = min(t2_cost, price - t1_profit);
            t2_profit = max(t2_profit, price - t2_cost);
        }
        return t2_profit;
    }
};