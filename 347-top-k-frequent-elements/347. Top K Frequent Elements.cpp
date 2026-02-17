class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> ktop;
        vector<int> ans;
        for(int n: nums) {
            freq[n]++;
        }
        for(auto [key, v]: freq) {
            if(ktop.size() < k) {
                ktop.emplace(v, key);
            } else if(v > ktop.top().first) {
                ktop.pop();
                ktop.emplace(v, key);
            }
        }
        while(!ktop.empty()) {
            ans.push_back(ktop.top().second);
            ktop.pop();
        }
        return ans;
    }
};