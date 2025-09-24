class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int mask = 0; mask < 32; mask++) {
            int cnt = 0;
            for (int num : nums) {
                if (num & (1 << mask)) cnt++;
            }
            if (cnt % 3 != 0) ans |= (1 << mask);
        }
        return ans;
    }
};