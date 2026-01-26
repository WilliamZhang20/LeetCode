class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int p1 = 0, p2 = 0;
        string result;
        while(p1 < word1.length() || p2 < word2.length()) {
            if(p1 < word1.length()) {
                result += word1[p1];
                ++p1;
            }
            if(p2 < word2.length()) {
                result += word2[p2];
                ++p2;
            }
        }
        return result;
    }
};