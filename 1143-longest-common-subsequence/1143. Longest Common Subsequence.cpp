class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        if(n < m) {
            swap(text1, text2);
            swap(n, m);
        }
        vector<int> row1(m+1, 0);
        vector<int> row2(m+1, 0);
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<m+1; j++) {
                if(text1[i-1] == text2[j-1]) {
                    row1[j] = row2[j-1] + 1;
                } else {
                    row1[j] = max(row2[j], row1[j-1]);
                }
            }
            row2 = row1;
            row1.assign(m+1, 0);
        }
        return row2[m];
    }
};