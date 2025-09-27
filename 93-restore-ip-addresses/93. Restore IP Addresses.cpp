class Solution {
public:
    void explore(vector<string>& ans, string& s, string curr, int pos, int dots) {
        if (dots == 4 && pos == s.length()) {
            ans.push_back(curr.substr(0, curr.length() - 1)); // Remove trailing dot
            return;
        }
        if (dots > 4 || pos >= s.length()) {
            return;
        }
        for (int len = 1; len <= 3 && pos + len <= s.length(); len++) {
            string segment = s.substr(pos, len);
            // Check for invalid cases: leading zero or value > 255
            if ((segment.length() > 1 && segment[0] == '0') || (stoi(segment) > 255)) {
                continue;
            }
            // Recurse with the current segment added
            explore(ans, s, curr + segment + ".", pos + len, dots + 1);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        if(s.length() < 4 || s.length() > 12) {
            return {};
        }
        explore(ans, s, "", 0, 0);
        return ans;
    }
};