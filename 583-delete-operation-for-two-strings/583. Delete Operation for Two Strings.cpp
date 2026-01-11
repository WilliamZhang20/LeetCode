class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<int> dp(m + 1);

        // Base case: word1 is empty, so we delete all characters of word2
        for (int j = 0; j <= m; j++) dp[j] = j;

        for(int i=1; i<=n; i++) {
            int prev_diagonal=dp[0];
            dp[0] = i;
            for(int j=1; j<=m; j++) {
                int temp = dp[j];
                if(word1[i-1] == word2[j-1]) {
                    dp[j] = prev_diagonal;
                } else {
                    dp[j] = 1 + min(dp[j], dp[j-1]);
                }
                prev_diagonal = temp;
            }
        }
        return dp[m];
    }
};