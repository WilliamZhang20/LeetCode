class TwoSum {
    unordered_map<long long, int> freq;
public:
    TwoSum() {}
    
    void add(int number) {
        freq[number]++;
    }
    
    bool find(int value) {
        for(const auto& [k, v]: freq) {
            if((value - k != k) && freq.count(value - k)) {
                return true;
            } else if((value - k == k) && freq[k] > 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */