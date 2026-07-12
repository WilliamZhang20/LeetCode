class Allocator {
    map<int, int> free; // start->end
    unordered_map<int, vector<pair<int, int>>> meta; // id -> (start, size)
public:
    Allocator(int n) {
        free[0] = n-1;
    }
    
    int allocate(int size, int mID) {
        for (auto it = free.begin(); it != free.end(); ++it) {
            int l = it->first;
            int r = it->second;

            if (r - l + 1 < size)
                continue;

            meta[mID].push_back({l, size});

            if (r - l + 1 == size) {
                // entire block used
                free.erase(it);
            } else {
                // shrink block from the left
                free.erase(it);
                free[l + size] = r;
            }

            return l;
        }
        return -1;
    }
    
    int freeMemory(int mID) {
        if (!meta.count(mID)) return 0;

        int ret = 0;

        for (auto [start, sz] : meta[mID]) {
            ret += sz;

            int L = start;
            int R = start + sz - 1;

            auto it = free.lower_bound(L);

            // merge with previous
            if (it != free.begin()) {
                auto prv = prev(it);
                if (prv->second + 1 == L) {
                    L = prv->first;
                    free.erase(prv);
                }
            }

            // merge with next
            if (it != free.end() && it->first == R + 1) {
                R = it->second;
                free.erase(it);
            }

            free[L] = R;
        }

        meta.erase(mID);
        return ret;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->freeMemory(mID);
 */