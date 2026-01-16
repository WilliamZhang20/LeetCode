class Solution {
public:
    int lengthOfLongestSubstring(const string& s) {
        // Frequency table for all possible byte values (0‑255)
        std::array<int, 256> freq{};

        int maxLen = 0;
        int left = 0;                     // left side of the sliding window

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            unsigned char ch = s[right];  // ensure we use the raw byte value
            ++freq[ch];                   // add current character

            // If this character now appears more than once, shrink from the left
            while (freq[ch] > 1) {
                unsigned char leftCh = s[left];
                --freq[leftCh];
                ++left;
            }

            // Window [left, right] is now valid (all distinct characters)
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;   // works for empty string as well (maxLen stays 0)
    }
};