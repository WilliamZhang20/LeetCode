class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Using Bayer-More Majority Voting Algorithm
        int majority1=0, majority2=0, count1=0, count2 = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == majority1) {
                ++count1;
            }
            else if(nums[i] == majority2) {
                ++count2;
            } 
            else if(count1 == 0) {
                majority1 = nums[i];
                ++count1;
            }
            else if(count2 == 0) {
                majority2 = nums[i];
                ++count2;
            } 
            else {
                --count1;
                --count2;
            }
        }
        count1 = 0;
        count2 = 0;
        cout << majority1 << "\n";
        // second step for verification
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == majority1) {
                ++count1;
            }
            else if(nums[i] == majority2) {
                ++count2;
            }
        }
        vector<int> res;
        if(count1 > floor(nums.size()/3)) {
            res.push_back(majority1);
        }
        if(count2 > floor(nums.size()/3)) {
            res.push_back(majority2);
        }
        return res;
    }
};