class RandomizedCollection {
    vector<int> v;
    std::mt19937 gen{std::random_device{}()};
    unordered_map<int, unordered_set<int>> indices;
public:
    RandomizedCollection() {
    }
    
    bool insert(int val) {
        v.push_back(val);
        indices[val].insert(v.size()-1); // 0-indexed
        if(indices[val].size() == 1) return true;
        return false;
    }
    
    bool remove(int val) {
        if(indices.find(val) == indices.end()) return false;
        int idx = *indices[val].begin();
        int lastIdx = v.size() - 1;
        int lastVal = v[lastIdx];
        indices[val].erase(idx);
        if(idx != lastIdx) {
            indices[lastVal].erase(lastIdx);
            indices[lastVal].insert(idx);
            v[idx] = lastVal;
        }
        
        v.pop_back();
        if (indices[val].empty()) indices.erase(val);
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> dist(0, v.size() - 1);
        return v[dist(gen)];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */