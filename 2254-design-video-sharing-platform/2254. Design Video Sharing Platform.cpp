class VideoSharingPlatform {
    priority_queue<int, vector<int>, greater<>> used;
    int curId = 0;
    unordered_map<int, vector<int>> stats;
    unordered_map<int, string> ids;
public:
    VideoSharingPlatform() {
    }
    
    int upload(string video) {
        int videoId;
        if(!used.empty()) {
            videoId = used.top();
            used.pop();
        }
        else {
            videoId = curId++;
        }
        stats[videoId].assign(4, 0);
        ids[videoId] = video;
        return videoId;
    }
    
    void remove(int videoId) {
        if (!stats.contains(videoId)) return;
        stats.erase(videoId);
        ids.erase(videoId);
        used.push(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (!stats.contains(videoId)) return "-1";
        stats[videoId][0] += 1;
        return ids[videoId].substr(startMinute, endMinute - startMinute + 1);
    }
    
    void like(int videoId) {
        if (!stats.contains(videoId)) return;
        stats[videoId][1] += 1;
    }
    
    void dislike(int videoId) {
        if (!stats.contains(videoId)) return;
        stats[videoId][2] += 1;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (!stats.contains(videoId)) return {-1};
        return {stats[videoId][1], stats[videoId][2]};
    }
    
    int getViews(int videoId) {
        if (!stats.contains(videoId)) return -1;
        return stats[videoId][0];
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