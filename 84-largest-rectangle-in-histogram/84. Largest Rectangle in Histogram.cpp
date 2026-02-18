class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        s.push(-1);
        int max_area = 0;
        for(size_t i = 0; i<heights.size(); i++) {
            while(s.top() != -1 && heights[s.top()] >= heights[i]) {
                int current_height = heights[s.top()];
                s.pop();
                int current_width = i - s.top() - 1;
                max_area = max(max_area, current_height * current_width);
            }
            s.push(i);
        }
        while(s.top() != -1) {
            int curr_height = heights[s.top()];
            s.pop();
            int curr_width = heights.size() - s.top() - 1;
            max_area = max(max_area, curr_height * curr_width);
        }
        return max_area;
    }
};