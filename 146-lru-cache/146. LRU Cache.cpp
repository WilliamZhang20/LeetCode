class LRUCache {
    int cap;
    std::unordered_map<int, list<pair<int, int>>::iterator> cache;
    list<pair<int, int>> lru;
public:
    LRUCache(int capacity) : cap(capacity) {}
    
    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) {
            return -1;
        }
        int val = it->second->second; // the second of the value of the map
        // move it->second around in the linked list
        lru.splice(lru.begin(), lru, it->second);
        cache.erase(it);
        cache[key] = lru.begin();
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return;
        auto it = cache.find(key);
        if (it != cache.end()) {
            it->second->second = value;
            lru.splice(lru.begin(), lru, it->second);
            return;
        }
        lru.emplace_front(key, value);
        cache[key] = lru.begin();
        if (cache.size() > cap) {
            cache.erase(lru.back().first);
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */