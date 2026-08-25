class Solution {
    using P = pair<string, int>;

    struct Compare {
        bool operator()(const P& a, const P& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;

        for (const auto& word : words) {
            ++freq[word];
        }

        priority_queue<P, vector<P>, Compare> pq;

        for (const auto& [word, count] : freq) {
            pq.push({word, count});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        vector<string> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
