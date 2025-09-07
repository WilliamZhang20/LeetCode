class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> soln;
        for(int i=1; i<=n/2; i++) {
            soln.push_back(i);
            soln.push_back(-i);
        }
        if(soln.size() < n) {
            soln.push_back(0);
        }
        return soln;
    }
};