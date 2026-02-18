class Solution {
public:
    int characterReplacement(string s, int k) {
        array<int, 26> freq;
        int start=0;
        int maxFrequency = 0;
        int ans = 0; // longest substring
        for(int end = 0; end < s.length(); end += 1) { 
            int ch = s[end] - 'A';
            freq[ch]++;
            maxFrequency = max(maxFrequency, freq[ch]);
            if(end + 1 - start - maxFrequency > k) {
                int och = s[start] - 'A';
                freq[och] -= 1;
                start += 1;
            }
            ans = end + 1 - start;
        }
        return ans;
    }
};