class Solution {
public:
    string minWindow(string s, string t) {
        int l=0;
        unordered_map<char, int> tgt;
        for(char& c: t) {
            tgt[c]++;
        }
        unordered_map<char, int> curTrack;
        int minLength = 1e6;
        string ans;
        for(int r=0; r<s.length(); r++) {
            curTrack[s[r]]++; // add to frequency
            bool d = true;
            for(auto& [k, v]: tgt) {
                if(v > curTrack[k]) {
                    d = false;
                    break;
                }
            }
            if(!d) continue; // keep increasing r until valid
            while(curTrack[s[l]] > tgt[s[l]]) { // keep shrinking while valid
                curTrack[s[l]]--;
                l++;
            }
            if(r - l + 1 < minLength) {
                minLength = r - l + 1;
                ans = s.substr(l, r - l + 1);
            } 
        }
        return ans;
    }
};