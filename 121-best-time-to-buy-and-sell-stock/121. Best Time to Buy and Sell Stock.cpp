class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur = INT_MAX, ans = 0;
        for(int i=0; i < prices.size(); i++) {
            cur = min(prices[i], cur);
            ans = max(prices[i] - cur, ans);
        }
        return ans;
    }
};