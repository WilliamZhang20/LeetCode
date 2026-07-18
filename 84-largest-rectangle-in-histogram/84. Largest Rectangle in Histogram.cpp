class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // build previous smaller element and next smaller element via stack
        vector<int> pse(n), nse(n); // both contain indices
        stack<int> st; // monotonic stack to track increasing/decreasing
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        st = std::stack<int>();
        for(int i=heights.size()-1; i>=0; i--) { 
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        int ans = 0;
        // use previous smaller element and next smaller element
        for(int i=0; i<n; i++) {
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
};