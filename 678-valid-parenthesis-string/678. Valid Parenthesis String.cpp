class Solution {
public:
    bool checkValidString(string s) {
        // two pointers approach - i overthought like crazy prior to seeing this in editorial
        int l = 0;
        int len = s.length();
        int r = len - 1;
        int open = 0, closed = 0;
        for(int i=0; i<len; i++) {
            if(s[i] == '(' || s[i] == '*') {
                open += 1;
            } else {
                open -= 1;
            }
            if(s[len - i - 1] == ')' || s[len-i-1] == '*') {
                closed += 1;
            } else {
                closed -= 1;
            }
            if(open < 0 || closed < 0) return false;
        }
        return true;
    }
};