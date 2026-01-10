class Solution {
public:
    int helperBinarySearch(vector<int>& arr, int left, int right, int target) {
        while(left < right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] >= target) 
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        while(left + 1 < n && arr[left] <= arr[left+1]) {
            ++left;
        }
        while(right - 1 >= 0 && arr[right] >= arr[right-1]) {
            --right;
        }
        if(left >= right) {
            return 0;
        }
        // either remove amount after left OR everything left of the right
        int ans = min(n - (left + 1), right);
        for (int i = 0; i <= left; i++) {
            int target = arr[i];
            int j = helperBinarySearch(arr, right, n, target);
            ans = min(ans, j - (i + 1));
        }
        return ans;
    }
};