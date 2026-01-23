class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<>> large;
    priority_queue<int> small;

    MedianFinder() {}
    
    void addNum(int num) {
        small.push(num);
        if(!small.empty()) {
            large.push(small.top());
            small.pop();
        }
        if(large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }
    
    double findMedian() {
        if(large.size() > small.size()) {
            return large.top();
        } else if(large.size() < small.size()) {
            return small.top();
        } else {
            return (large.top() + small.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */