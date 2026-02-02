class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> seen;
        unordered_set<string> res;
        for(int start=0; start + 10 <= s.length(); ++start) {
            string tmp = s.substr(start, 10);
            if(seen.count(tmp)) res.insert(tmp);
            seen.insert(tmp);
        }
        return vector<string>(res.begin(), res.end());
    }
};