class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> result;
        int n = code.size();
        result.assign(n, 0);
        for(int i=0; i<n; i++) {
            if(k > 0) {
                int sum = 0;
                for(int j=1; j<=k; j++) {
                    sum += code[(i + j) % n];
                }
                result[i] = sum;
            } else if(k < 0) {
                int sum = 0;
                for(int j=1; j<=(0-k); j++) {
                    sum += code[(i - j + n) % n];
                }
                result[i] = sum;
            }
        }
        return result;
    }
};