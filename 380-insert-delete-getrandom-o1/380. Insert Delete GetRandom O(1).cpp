class RandomizedSet {
    unordered_map<int, int> idx; 
    vector<int> v;
    std::mt19937 gen;
public:
    RandomizedSet() {
    }
    
    bool insert(int val) {
        if(idx[val] != 0) return false;
        v.push_back(val);
        idx[val] = v.size();
        return true;
    }
    
    bool remove(int val) {
        if(idx[val] == 0) return false;
        // how to remove from vector
        idx[v[v.size()-1]] = idx[val];
        swap(v[idx[val]-1], v[v.size()-1]);
        v.pop_back();
        idx[val] = 0;
        return true;
    }
    
    int getRandom() {
        std::uniform_int_distribution<int> dist(0, v.size() - 1);
        return v[dist(gen)];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */