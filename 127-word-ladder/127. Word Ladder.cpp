class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> track;
        for(auto& word: wordList) {
            track.insert(word);
        }
        if (!track.count(endWord)) return 0;
        queue<string> q;
        int level = 1;
        q.push(beginWord);
        track.erase(beginWord);
        while(!q.empty()) {
            // iterate through queue + pop everything + push all neighbors
            int len = q.size();
            for(int i=0; i<len; i++) {
                string curr = q.front();
                q.pop();
                // find neighbor
                for(int j=0; j<curr.length(); j++) {
                    char original = curr[j];
                    string next = curr;
                    for(char c='a'; c <= 'z'; c++) { // C++ :))
                        if(c == original) continue;
                        next[j] = c;
                        if(track.count(next)) {
                            if(next == endWord) {
                                return level + 1;
                            }
                            q.push(next);
                            track.erase(next);
                        }
                    }
                }
            }
            level++;
        }
        return 0;
    }
};