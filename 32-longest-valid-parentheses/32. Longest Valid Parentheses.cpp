class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length()+2); // longest # of valid parentheses starting at index i
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == ')') continue;
            else {
                if(i+1 < s.length() && s[i+1] == ')') {
                    dp[i] = 2 + dp[i+2];
                } else {
                    // (valid)
                    int x = dp[i+1]; // track last index of valid
                    int idx = i + x+ 1;
                    if(idx < s.length() && s[idx] == ')') {
                        dp[i] = 2+ x + dp[idx + 1];
                    }
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};