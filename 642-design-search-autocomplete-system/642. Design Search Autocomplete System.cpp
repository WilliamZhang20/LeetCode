class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    unordered_map<string, int> sCount;
};

class AutocompleteSystem {
    TrieNode root;
    string currSentence;
    TrieNode* currNode;

    static bool cmp(const pair<string,int>& a, const pair<string,int>& b) {
        if (a.second != b.second) return a.second > b.second;
        return a.first < b.first;
    }

public:
    void addToTrie(string& sentence, int count) {
        TrieNode* node = &root;
        for (char c : sentence) {
            if (!node->children.count(c)) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
            node->sCount[sentence] += count;
        }
    }

    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        currNode = &root;
        currSentence = "";
        for (int i = 0; i < sentences.size(); i++) {
            addToTrie(sentences[i], times[i]);
        }
    }

    vector<string> input(char c) {
        if (c == '#') {
            addToTrie(currSentence, 1);
            currSentence = "";
            currNode = &root;
            return {};
        }

        currSentence += c;

        if (!currNode || !currNode->children.count(c)) {
            currNode = nullptr;
            return {};
        }

        currNode = currNode->children[c];

        vector<pair<string,int>> candidates;
        for (auto& p : currNode->sCount) {
            candidates.push_back(p);
        }

        sort(candidates.begin(), candidates.end(), cmp);

        vector<string> res;
        for (int i = 0; i < min(3, (int)candidates.size()); i++) {
            res.push_back(candidates[i].first);
        }
        return res;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */