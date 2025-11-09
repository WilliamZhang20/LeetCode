class ATM {
    array<int, 5> corresp = {20, 50, 100, 200, 500};
    array<int, 5> bn = {0}; // Fixed-size array
public:
    void deposit(vector<int> banknotesCount) {
        for (int i = 0; i < 5; i++) bn[i] += banknotesCount[i];
    }
    
    vector<int> withdraw(int amount) {
        array<int, 5> cache = bn;
        vector<int> res(5, 0);
        
        for (int i = 4; i >= 0; i--) {
            int maxTake = min(bn[i], amount / corresp[i]);
            amount -= maxTake * corresp[i];
            res[i] = maxTake;
            bn[i] -= maxTake;
        }
        
        if (amount > 0) {
            bn = cache;
            return {-1};
        }
        return res;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */