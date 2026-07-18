class Solution {
public:
    int lastRemaining(int n) {
        // two pointers approach
        int start = 1, size = n;
        int step = 1;
        int rmStart = 1;
        while(size > 1) {
            if(rmStart) start += step;
            else if(!rmStart && size % 2 != 0) start += step;
            size /= 2; step *= 2;
            rmStart = 1 - rmStart;
        }
        return start;
    }
};