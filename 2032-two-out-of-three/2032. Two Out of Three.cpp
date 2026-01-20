class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> result;
        struct Present {
            bool pFirst = false;
            bool pSecond = false;
            bool pThird = false;
        };
        unordered_map<int, Present> mp;
        for(auto& val: nums1) { mp[val].pFirst = true; }
        for(auto& val: nums2) { mp[val].pSecond = true; }
        for(auto& val: nums3) { mp[val].pThird = true; }
        for(auto [k, v] : mp) {
            if(v.pFirst + v.pSecond + v.pThird >= 2) {
                result.push_back(k);
            }
        }
        return result;
    }
};