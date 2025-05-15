class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        for(int i=0; i<strs.size(); i++) {
            string curr = strs[i];
            std::sort(curr.begin(), curr.end());
            freq[curr].push_back(strs[i]);
        }
        vector<vector<string>> groups;
        for(auto e : freq) {
            groups.push_back(std::move(e.second));
        }
        return groups;
    }
};