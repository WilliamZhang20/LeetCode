class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i=0; i<nums.size(); i++) {
            if(minHeap.size() < k || nums[i] > minHeap.top()) {
                minHeap.push(nums[i]);
                if(minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
        return minHeap.top();
    }
};