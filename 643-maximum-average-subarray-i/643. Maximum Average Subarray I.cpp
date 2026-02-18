class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double avg = 0;
        double maxAvg;
        for(int i=0; i<k; i++) {
            avg += nums[i];
        }
        maxAvg = avg;
        for(int i=k; i<nums.size(); i++) {
            avg = avg - nums[i - k] + nums[i];
            if (avg > maxAvg) {
                maxAvg = avg;
            }
        }
        return maxAvg / k;
    }
};