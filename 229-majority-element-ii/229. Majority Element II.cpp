class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]] += 1;
        }
        vector<int> result;
        int n = nums.size();
        for(auto m = freq.begin(); m != freq.end(); m++) {
            if(m->second > floor(n/3)) {
                result.push_back(m->first);
            }
        }
        return result;
    }
};