class AuthenticationManager {
    int ttl;
    vector<pair<string, int>> tokens;
public:
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens.emplace_back(tokenId, currentTime+ttl);
        sort(tokens.begin(), tokens.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    }
    
    void renew(string tokenId, int currentTime) {
        auto it = tokens.begin();
        while (it != tokens.end() && it->second <= currentTime) {
            it = tokens.erase(it); // Properly update iterator
        }
        it = std::find_if(tokens.begin(), tokens.end(), [&](const auto& x) { return x.first == tokenId; });
        if(it != tokens.end()) {
            it->second = currentTime + ttl;
        }
        sort(tokens.begin(), tokens.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
    }
    
    int countUnexpiredTokens(int currentTime) {
        auto it = tokens.begin();
        while (it != tokens.end() && it->second <= currentTime) {
            it = tokens.erase(it); // Properly update iterator
        }
        return tokens.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */