class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](auto &x, auto &y) {return x[1] < y[1];});
        int numArrows = 1;
        int currArrow = points[0][1];
        for(int i=0; i<points.size(); i++) {
            if(points[i][0] > currArrow) {
                currArrow = points[i][1];
                ++numArrows;
            } else {
                continue;
            }
        }
        return numArrows;
    }
};