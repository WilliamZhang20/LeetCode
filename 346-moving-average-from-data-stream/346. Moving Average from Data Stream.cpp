class MovingAverage {
    int curSum;
    deque<int> window;
    int size;
public:
    MovingAverage(int size) {
        curSum = 0;
        this->size = size;
    }
    
    double next(int val) {
        window.push_back(val);
        curSum += val;
        if(window.size() > size) {
            curSum -= window.front();
            window.pop_front();
        }
        return static_cast<double>(curSum) / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */