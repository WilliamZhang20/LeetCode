class Solution {
public:
    int longestSubsequence(string s, int k) {
        int ans = 0;
        int val = 0;
        int ones = 32 - __builtin_clz(k); // crazy compiler intrinsic trick
        for(int i=0; i<s.length(); i++) {
            char ch = s[s.length() - i - 1];
            if(ch == '1') {
                if(i < ones && (val + (1 << i) <= k)) {
                    val += (1 << i);
                    ans += 1;
                }
            }
            else {
                ans += 1;
            }
        }
        return ans;
    }
};