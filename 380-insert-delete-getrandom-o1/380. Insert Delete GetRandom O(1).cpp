class RandomizedSet {
    map<int, int> idx; // value -> position (1-based)
    vector<int> v;
    std::mt19937 gen;

public:
    RandomizedSet() : gen(std::random_device{}()) {}

    bool insert(int val) {
        if (idx.find(val) != idx.end())
            return false;

        v.push_back(val);
        idx[val] = v.size(); // 1-based index
        return true;
    }

    bool remove(int val) {
        auto it = idx.find(val);
        if (it == idx.end())
            return false;

        int pos = it->second - 1;   // convert to 0-based
        int last = v.back();

        v[pos] = last;
        idx[last] = pos + 1;        // keep 1-based

        v.pop_back();
        idx.erase(it);

        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, v.size() - 1);
        return v[dist(gen)];
    }
};