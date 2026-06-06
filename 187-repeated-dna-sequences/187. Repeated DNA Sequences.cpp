class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() < 10) return {};
        vector<string> ans;
        unordered_map<int, int> seqFreq;
        int hash = 0;
        unordered_map<char, int> encode{
            {'A',0},
            {'C',1},
            {'G',2},
            {'T',3}
        };
        for (int i = 0; i < 10; i++) {
            hash = (hash << 2) | encode[s[i]];
        }
        seqFreq[hash]++;
        for(int i=10; i<s.length(); i++) {
            hash = ((hash << 2) | encode[s[i]]) & ((1 << 20) - 1);
            seqFreq[hash]++;
            if(seqFreq[hash] == 2) {
                ans.emplace_back(s.substr(i-9, 10));
            }
        }
        return ans;
    }
};