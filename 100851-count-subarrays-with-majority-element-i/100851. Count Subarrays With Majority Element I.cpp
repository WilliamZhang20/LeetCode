class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> diff(n);
        for(int i=0; i<n; ++i) {
            diff[i] = (nums[i] == target) ? 1 : -1;
        }
        long long ans = 0;
        long long prefix = 0;
        map<long long, int> freq;
        freq[0] = 1;
        for(int x: diff) {
            prefix += x;
            for(auto& p : freq) {
                if(p.first < prefix) {
                    ans += p.second;
                } else {
                    break;
                }
            }
            freq[prefix]++;
        }
        return ans;
    }
};