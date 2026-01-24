class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<int> buy(k+1, INT_MIN); // max profit after j-th buy
        vector<int> sell(k+1, 0);
        for(auto& price: prices) {
            for(int j=1; j<=k; j++) {
                buy[j] = max(buy[j], sell[j-1] - price);
                sell[j] = max(sell[j], buy[j] + price);
            }
        }
        return sell[k];
    }
};