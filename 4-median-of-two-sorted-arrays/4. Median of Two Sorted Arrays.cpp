class Solution {
    int i = 0;
    int j = 0;
public:
    int getMin(vector<int>& a, vector<int>& b) {
        if(i < a.size() && j < b.size()) {
            return a[i] < b[j] ? a[i++] : b[j++];
        } else if(i < a.size()) {
            return a[i++];
        } else if(j < b.size()) {
            return b[j++];
        }
        return -1;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = nums1.size() + nums2.size();
        vector<int> merged;
        if(total % 2 == 0) {
            for(int k = 0; k < total / 2 - 1; k++) {
                int _ = getMin(nums1, nums2);
            }
            return (double)(getMin(nums1, nums2) + getMin(nums1, nums2)) / 2;
        } else {
            for(int k = 0; k < total / 2; k++) {
                int _ = getMin(nums1, nums2);
            }
            return double(getMin(nums1, nums2));
        }
    }
};