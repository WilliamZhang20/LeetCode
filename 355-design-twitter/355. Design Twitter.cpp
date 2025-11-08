class Twitter {
    int timestamp;
    unordered_map<int, vector<pair<int, int>>> usrTwts; // user -> [(time, tweet)]
    unordered_map<int, unordered_set<int>> following;   // user -> set of followed users

public:
    Twitter() : timestamp(0) {}

    void postTweet(int userId, int tweetId) {
        usrTwts[userId].emplace_back(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        // Min-heap keeps the 10 most recent tweets
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        // Always include the user themselves
        following[userId].insert(userId);

        for (int followedId : following[userId]) {
            auto &tweets = usrTwts[followedId];
            for (auto &[time, tid] : tweets) {
                if ((int)minHeap.size() < 10) {
                    minHeap.push({time, tid});
                } else if (time > minHeap.top().first) {
                    minHeap.pop();
                    minHeap.push({time, tid});
                }
            }
        }

        vector<int> feed;
        while (!minHeap.empty()) {
            feed.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(feed.begin(), feed.end()); // newest first
        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)  // users don't need to follow themselves
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].erase(followeeId);
    }
};

/**
 * Usage:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId, tweetId);
 * vector<int> feed = obj->getNewsFeed(userId);
 * obj->follow(followerId, followeeId);
 * obj->unfollow(followerId, followeeId);
 */
