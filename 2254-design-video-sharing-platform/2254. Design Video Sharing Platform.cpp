class VideoSharingPlatform {
private:
    std::unordered_map<int, string> vidya;
    std::unordered_map<int, vector<int>> stats;
    std::set<int> avail_id;
    int hvideoId;

public:
    VideoSharingPlatform() {
        hvideoId = 0;
    }
    
    int upload(string video) {
        if (avail_id.size() != 0){
            int id = *avail_id.begin();
            vidya[id] = video;
            stats[id] = {0, 0, 0};
            avail_id.erase(id);
            return id;
        } else {
            vidya[hvideoId] = video;
            stats[hvideoId] = {0, 0, 0};
            return hvideoId++;
        }
    }
    
    void remove(int videoId) {
        if (!vidya.contains(videoId)) return;
        vidya.erase(videoId);
        stats.erase(videoId);
        avail_id.insert(videoId);
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (!vidya.contains(videoId)) return "-1";
        stats[videoId][2]++;
        string::iterator videoStart = vidya[videoId].begin()+startMinute;
        string::iterator videoEnd = vidya[videoId].begin()+std::min(endMinute+1, (int)vidya[videoId].length());
        return string(videoStart, videoEnd);
    }
    
    void like(int videoId) {
        if (!vidya.contains(videoId)) return;
        stats[videoId][0]++;
    }
    
    void dislike(int videoId) {
        if (!vidya.contains(videoId)) return;
        stats[videoId][1]++;
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (!vidya.contains(videoId)) return {-1};
        return vector<int>{stats[videoId][0], stats[videoId][1]};
    }
    
    int getViews(int videoId) {
        if (!vidya.contains(videoId)) return -1;
        return stats[videoId][2];
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