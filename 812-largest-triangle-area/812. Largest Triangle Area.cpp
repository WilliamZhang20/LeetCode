class Solution {
    double max(double a, double b) {
        return (a > b) ? a : b;
    }
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double a = 0;
        for(int i=0; i<points.size(); i++) {
            for(int j=i+1; j<points.size(); j++) {
                for(int k=i+2; k<points.size(); k++) {
                    a = max(a, 0.5 * abs(points[i][0] * (points[j][1] - points[k][1]) + points[j][0] * (points[k][1] - points[i][1]) + points[k][0] * (points[i][1] - points[j][1])));
                }
            }
        }
        return a;
    }
};