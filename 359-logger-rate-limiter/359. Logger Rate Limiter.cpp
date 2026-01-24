class Logger {
    unordered_map<string, int> pTime;
public:
    Logger() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        auto it = pTime.find(message);

        if (it == pTime.end()) {
            pTime.emplace(message, timestamp);
            return true;
        }

        if (timestamp - it->second < 10) {
            return false;
        }

        it->second = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */