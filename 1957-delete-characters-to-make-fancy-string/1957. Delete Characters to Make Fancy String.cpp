class Solution {
public:
    string makeFancyString(string s) {
        if (s.length() < 3) return s;
        int count = 1;
        std::string result;
        result += s[0];
        for(int i=1; i<s.length(); i++) {
            if(s[i] == s[i-1]) {
                count++;
                if(count < 3) {
                    result += s[i];
                }
            } else {
                count = 1;
                result += s[i];
            }
        }
        return result;
    }
};