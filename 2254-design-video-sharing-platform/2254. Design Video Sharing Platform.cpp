class VideoSharingPlatform {
    struct Video {
        string content;
        int views = 0;
        int likes = 0;
        int dislikes = 0;
    };

    priority_queue<int, vector<int>, greater<int>> available;
    unordered_map<int, Video> videos;
    int nextId = 0;

public:
    VideoSharingPlatform() {
        videos.reserve(100000);
    }
    
    int upload(string video) {
        int id;
        if (!available.empty()) {
            id = available.top();
            available.pop();
        } else {
            id = nextId++;
        }

        videos[id] = {video, 0, 0, 0};
        return id;
    }
    
    void remove(int videoId) {
        auto it = videos.find(videoId);
        if (it == videos.end()) return;

        videos.erase(it);
        available.push(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        auto it = videos.find(videoId);
        if (it == videos.end()) return "-1";

        it->second.views++;
        return it->second.content.substr(startMinute, endMinute - startMinute + 1);
    }
    
    void like(int videoId) {
        auto it = videos.find(videoId);
        if (it != videos.end()) it->second.likes++;
    }
    
    void dislike(int videoId) {
        auto it = videos.find(videoId);
        if (it != videos.end()) it->second.dislikes++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        auto it = videos.find(videoId);
        if (it == videos.end()) return {-1};

        return {it->second.likes, it->second.dislikes};
    }
    
    int getViews(int videoId) {
        auto it = videos.find(videoId);
        if (it == videos.end()) return -1;

        return it->second.views;
    }
};

/**
 * Your VideoSharingPlatform object will be instantiated and called as such:
 * VideoSharingPlatform* obj = new VideoSharingPlatform();
 * int param_1 = obj->upload(video);
 * obj->remove(videoId);
 * string param_3 = obj->watch(videoId,startMinute,endMinute);
 * obj->like(videoId);
 * obj->dislike(videoId);
 * vector<int> param_6 = obj->getLikesAndDislikes(videoId);
 * int param_7 = obj->getViews(videoId);
 */