class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int l = 1, r = piles[piles.size()-1];
        int ans = INT_MAX;
        while(l < r) {
            int k = (l + r) / 2;
            int time = 0;
            for(int i=0; i<piles.size(); i++) {
                time += (piles[i] + k - 1) / k;
            }
            if(time > h) {
                l = k + 1;
            } else {
                r = k;
            }
        }
        return r;
    }
};