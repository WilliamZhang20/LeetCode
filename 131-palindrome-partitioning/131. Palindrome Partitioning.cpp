class Solution {
    vector<vector<string>> result;
public:
    bool isPalindrome(const string& s, int left, int right) {
        // Check if the substring s[left:right+1] is a palindrome
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
    void backtrack(int start, string& s, vector<string>& path) {
        if(start == s.length()) {
            result.push_back(path);
            return;
        }
        for(int i=start+1; i<=s.length(); i++) {
            if(isPalindrome(s, start, i-1)) {
                path.push_back(s.substr(start, i-start));
                backtrack(i, s, path);
                path.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> path;
        backtrack(0, s, path);
        return result;
    }
};