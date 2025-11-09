class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin = 0;
        int end = numbers.size()-1;
        while(begin < end) {
            int a = numbers[begin] + numbers[end];
            if(a < target) {
                begin++;
            } else if(a > target) {
                end--;
            } else {
                break;
            }
        }
        return vector<int>{begin+1, end+1};
    }
};