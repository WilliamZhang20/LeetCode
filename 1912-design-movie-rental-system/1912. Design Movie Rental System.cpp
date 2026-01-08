class MovieRentingSystem {
    map<int, set<pair<int, int>>> movies; // movie -> {price, shop}
    set<tuple<int, int, int>> rented;     // {price, shop, movie}
    map<pair<int, int>, int> priceOf; // {movie, shop} -> price
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            movies[movie].insert({price, shop});
            priceOf[{movie, shop}] = price;
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!movies.count(movie)) return res;
        // ALREADY SORTED (SET)
        for (auto& [price, shop] : movies[movie]) {
            res.push_back(shop);
            if (res.size() == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceOf[{movie, shop}];
        movies[movie].erase({price, shop});
        rented.emplace(price, shop, movie);
    }

    void drop(int shop, int movie) {
        int price = priceOf[{movie, shop}];
        rented.erase({price, shop, movie});
        movies[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;

        for (auto& [price, shop, movie] : rented) {
            res.push_back({shop, movie});
            if (res.size() == 5) break;
        }
        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */