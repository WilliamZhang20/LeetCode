class AuthenticationManager {
    int ttl;
    vector<pair<string, int>> tokens; // Sorted by expiration time (ascending)
public:
    AuthenticationManager(int timeToLive) : ttl(timeToLive) {}
    
    void generate(string tokenId, int currentTime) {
        int exp = currentTime + ttl;
        auto it = lower_bound(tokens.begin(), tokens.end(), exp, 
            [](const auto& a, int exp_time) { return a.second < exp_time; });
        tokens.insert(it, {tokenId, exp});
    }
    
    void renew(string tokenId, int currentTime) {
        // Remove expired tokens (from front, since sorted)
        auto it = tokens.begin();
        while (it != tokens.end() && it->second <= currentTime) {
            it = tokens.erase(it);
        }
        
        // Find token (linear scan - unavoidable without a separate ID map)
        auto token_it = find_if(tokens.begin(), tokens.end(), 
            [&](const auto& x) { return x.first == tokenId; });
        if (token_it == tokens.end()) return;
        
        // Update expiration: remove old token, insert new one in sorted position
        tokens.erase(token_it);
        int new_exp = currentTime + ttl;
        auto insert_it = lower_bound(tokens.begin(), tokens.end(), new_exp,
            [](const auto& a, int exp_time) { return a.second < exp_time; });
        tokens.insert(insert_it, {tokenId, new_exp});
    }
    
    int countUnexpiredTokens(int currentTime) {
        // Remove expired tokens (from front)
        auto it = tokens.begin();
        while (it != tokens.end() && it->second <= currentTime) {
            it = tokens.erase(it);
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