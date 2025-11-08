class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<bool> next(m + 1, false), curr(m + 1, false);
        next[m] = true;
        for (int i = n; i >= 0; --i) {
            curr[m] = (i == n);
            for (int j = m - 1; j >= 0; --j) {
                bool match = (i < n) && (p[j] == s[i] || p[j] == '.');
                if (j + 1 < m && p[j + 1] == '*') {
                    curr[j] = next[j] && match || curr[j + 2];
                } else {
                    curr[j] = match && next[j + 1];
                }
            }
            next = curr; // move to next row
        }

        return next[0];
    }
};