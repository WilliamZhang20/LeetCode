class Solution {
    int binarySearch(vector<int>& nums, int l, int r, int k) {
        while(l <= r) {
            int mid = (l + r) / 2;
            if(nums[mid] >= k) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-2; i++) {
            for(int j=i+1; j<nums.size()-1; j++) {
                int k = binarySearch(nums, j+1, nums.size()-1, nums[i]+nums[j]);
                count += (k - (j + 1));
            }
        }
        return count;
    }
};