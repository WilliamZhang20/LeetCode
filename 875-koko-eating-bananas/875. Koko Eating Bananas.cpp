class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        // function of time to eat of speed = # of piles less than speed + quotients rounded up of remaining
        int r = piles[piles.size()-1];
        int l = 1;
        while(l < r) {
            int k = (l + r) / 2;
            int time = 0;
            for(int i=0; i < piles.size(); i++) {
                time += ceil(piles[i] / (k * 1.0));
            }
            if(time > h) {
                l = k + 1;
            }
            else if(time <= h) {
                r = k;
            }
        }
        return l;
    }
};