class Logger {
    unordered_map<string, int> pTime;
public:
    Logger() { }
    
    bool shouldPrintMessage(int timestamp, string message) {
        if(!pTime.contains(message)) {
            pTime[message] = timestamp;
            return true;
        }   
        if (timestamp - pTime[message] < 10) {
            return false;
        }
        pTime[message] = timestamp;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */