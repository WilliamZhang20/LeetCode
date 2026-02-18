class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int count = 0;
        unordered_map<int, int> sumCount;
        sumCount[0] = 1;
        for(const int& i : nums) {
            sum += i;
            if(sumCount.count(sum - k)) {
                count += sumCount[sum - k];
            }
            sumCount[sum]++;
        }
        return count;
    }
};