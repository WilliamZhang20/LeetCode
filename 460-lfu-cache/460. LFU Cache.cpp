class LFUCache {
    int capacity;
    int minFreq;
    // key -> {value, freq, iterator into freq list}
    unordered_map<int, pair<int, pair<int, list<int>::iterator>>> keyMap;

    // freq -> list of keys (LRU order within same freq)
    unordered_map<int, list<int>> freqMap;
public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}
    
    int get(int key) {
        auto it = keyMap.find(key);
        if(it == keyMap.end()) return -1;

        int value = it->second.first;
        int& freq = it->second.second.first;
        auto iter = it->second.second.second;
        freqMap[freq].erase(iter);
        if (freq == minFreq && freqMap[freq].empty()) {
            minFreq++;
        }
        freq++;
        freqMap[freq].emplace_front(key);
        it->second.second.second = freqMap[freq].begin();
        return value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        auto it = keyMap.find(key);
        if(it != keyMap.end()) {
            it->second.first = value;
            get(key);   // reuse correct logic
            return;
        }
        if (keyMap.size() == capacity) {
            // proceed to delete a key
            int key = freqMap[minFreq].back();
            freqMap[minFreq].pop_back();
            keyMap.erase(key);
        }
        // create new key with frequency 1
        freqMap[1].emplace_front(key);
        minFreq = 1;
        keyMap[key] = {value, {1, freqMap[1].begin()}};
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */