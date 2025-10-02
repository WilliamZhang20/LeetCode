struct tuple_hash {
    template <typename T>
    size_t operator ()(const T& tuple) const {
        size_t h1 = std::hash<int>{}(std::get<0>(tuple));
        size_t h2 = std::hash<int>{}(std::get<1>(tuple));
        size_t h3 = std::hash<int>{}(std::get<2>(tuple));
        // Combine the hashes of the tuple elements
        return h1 ^ h2 ^ h3;
    }
};

using Key = std::tuple<int, int, int>;

template<class Target, class Tuple>
auto tuple_to_vector_as(const Tuple& tup) -> std::vector<Target> {
    std::vector<Target> vec;
    vec.reserve(std::tuple_size_v<std::decay_t<Tuple>>);
    std::apply([&vec](auto&&... args) {
        (vec.emplace_back(static_cast<Target>(std::forward<decltype(args)>(args))), ...);
    }, tup);
    return vec;
}

class Router {
    std::unordered_set<Key, tuple_hash> check;  // To track existing (source, destination, timestamp) triplets
    std::unordered_map<int, std::deque<int>> sameDestQ;
    std::deque<Key> q; // Stores (source, destination, timestamp) for forwarding
    int capacity;
    int sz;

public:
    Router(int memoryLimit) {
        capacity = memoryLimit;
        sz = 0;
    }

    bool addPacket(int source, int destination, int timestamp) {
        if (check.contains(std::make_tuple(source, destination, timestamp))) {
            return false;
        }
        if (sz == capacity) {
            Key val = q.front();
            q.pop_front();
            check.erase(val); 
            --sz;
            
            sameDestQ[std::get<1>(val)].pop_front();
        }

        // Add the new packet to the router's structures
        check.emplace(source, destination, timestamp);
        q.emplace_back(source, destination, timestamp);
        sameDestQ[destination].push_back(timestamp);
        sz++;
        return true;
    }

    std::vector<int> forwardPacket() {
        if (sz == 0) { // Handle empty router
            return {};
        }

        // Forward the first packet in the queue (FIFO)
        Key val = q.front();
        q.pop_front();
        check.erase(val); 
        --sz;
        
        sameDestQ[std::get<1>(val)].pop_front();
        
        return tuple_to_vector_as<int>(val);
    }

    int getCount(int destination, int startTime, int endTime) {
        auto pos1 = lower_bound(sameDestQ[destination].begin(),
                                sameDestQ[destination].end(), startTime);
        auto pos2 = upper_bound(sameDestQ[destination].begin(),
                                sameDestQ[destination].end(), endTime);
        return std::distance(pos1, pos2);
    }
};
/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */