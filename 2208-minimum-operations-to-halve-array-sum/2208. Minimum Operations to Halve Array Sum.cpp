class Solution {
public:
    int halveArray(vector<int>& nums) {
        int ops = 0;
        double sum = std::reduce(nums.begin(), nums.end(), 0.0);
        sort(nums.begin(), nums.end());
        priority_queue<double> pq(nums.begin(), nums.end());
        double curr = sum;
        while(curr > sum / 2) {
            double val = pq.top();
            pq.pop();
            pq.push(val / 2);
            curr -= val / 2;
            ops++;
        }
        return ops;
    }
};