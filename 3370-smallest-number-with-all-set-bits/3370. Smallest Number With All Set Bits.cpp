class Solution {
public:
    int smallestNumber(int n) {
        int i = 0;
        while(true) {
            if(pow(2, i) > n) {
                return pow(2, i) - 1;
            }
            i++;
        }
    }
};