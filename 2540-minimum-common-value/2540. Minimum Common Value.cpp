class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> f1;
        for(auto& val: nums1) {
            f1[val]++;
        }
        for(auto& val: nums2) {
            if(f1[val] > 0) return val;
        }
        return -1;
    }
};