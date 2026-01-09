class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> meetingCount(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> usedRooms; // room_availability_time, room_number
        priority_queue<int, vector<int>, greater<int>> unusedRooms;
        for(int i=0; i<n; i++) {
            unusedRooms.push(i);
        }
        sort(meetings.begin(), meetings.end());
        for(auto& meeting: meetings) {
            int start = meeting[0], end = meeting[1];
            while(!usedRooms.empty() && usedRooms.top().first <= start) {
                int room = usedRooms.top().second;
                usedRooms.pop();
                unusedRooms.push(room);
            }
            if(!unusedRooms.empty()) {
                int room = unusedRooms.top();
                unusedRooms.pop();
                usedRooms.push({end, room});
                meetingCount[room]++;
            } else {
                auto [roomAvailTime, room] = usedRooms.top();
                usedRooms.pop();
                usedRooms.push({roomAvailTime + end - start, room});
                meetingCount[room]++;
            }
        }
        std::vector<int>::iterator max_it = std::max_element(meetingCount.begin(), meetingCount.end());
        int argmax_index = std::distance(meetingCount.begin(), max_it);
        return argmax_index;
    }
};