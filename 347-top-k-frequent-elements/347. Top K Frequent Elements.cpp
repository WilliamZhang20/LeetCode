class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int n: nums) {
            freq[n]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(const auto& [num, count] : freq) {
            buckets[count].push_back(num);
        }
        vector<int> ans;
        for(int i = nums.size(); i>=0 && ans.size() < k; i--) {
            for(int num : buckets[i]) {
                ans.push_back(num);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};