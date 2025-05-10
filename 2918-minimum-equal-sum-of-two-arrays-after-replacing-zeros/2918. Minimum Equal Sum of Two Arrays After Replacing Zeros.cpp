class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zero1 = 0, zero2 = 0;
        long long sum1 = 0, sum2 = 0;
        for(int i=0; i<nums1.size(); ++i) {
            if(nums1[i] == 0) {
                zero1 += 1;
                ++sum1;
            } else {
                sum1 += nums1[i];
            }
        }
        for(int i=0; i<nums2.size(); ++i) {
            if(nums2[i] == 0) {
                ++sum2;
                zero2 += 1;
            } else {
                sum2 += nums2[i];
            }
        }
        cout << sum1 << " " << sum2 << endl;
        if(!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        }
        return max(sum1, sum2);
    }
};