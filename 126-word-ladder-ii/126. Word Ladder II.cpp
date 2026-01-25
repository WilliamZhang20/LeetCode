class Solution {
    unordered_map<string, vector<string>> parents;
    vector<vector<string>> ans;
public:
    void dfs(string& curr, string& target, vector<string>& path) {
        if(curr == target) {
            ans.emplace_back(path.rbegin(), path.rend());
            return; // base case
        }
        for(auto& next: parents[curr]) {
            path.push_back(next);
            dfs(next, target, path);
            path.pop_back();
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return {};
        int L = beginWord.size();
        unordered_map<string, vector<string>> patterns;
        for (const string& word : wordSet) {
            for (int i = 0; i < L; i++) {
                string p = word;
                p[i] = '*';
                patterns[p].push_back(word);
            }
        }

        unordered_set<string> level{beginWord};
        unordered_set<string> vis{beginWord};
        bool found = false;

        while(!level.empty() && !found) {
            unordered_set<string> nextLevel;
            unordered_set<string> localVis;
            for(const string& word: level) {
                for(int i=0; i < L; i++) {
                    string p = word;
                    p[i] = '*';

                    for(const string& next : patterns[p]) {
                        if(!vis.count(next)) {
                            if(next == endWord) found = true;
                            if(!localVis.count(next)) {
                                nextLevel.insert(next);
                                localVis.insert(next);
                            }
                            parents[next].push_back(word);
                        }
                    }
                }
            }

            for(const string& w : localVis) 
                vis.insert(w);
            level = move(nextLevel);
        }

        // do a DFS search to gather all shortest paths into ans
        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);
        return ans;
    }
};