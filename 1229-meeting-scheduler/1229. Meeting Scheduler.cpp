class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        using timeslot = pair<int, int>;
        priority_queue<timeslot, vector<timeslot>, greater<>> timeslots;
        for(const auto& slot: slots1) {
            if(slot[1] - slot[0] >= duration) {
                timeslots.emplace(slot[0], slot[1]);
            }
        }
        for(const auto& slot : slots2) {
            if(slot[1] - slot[0] >= duration) {
                timeslots.emplace(slot[0], slot[1]);
            }
        }
        while(timeslots.size() > 1) {
            timeslot curr = timeslots.top();
            timeslots.pop();
            timeslot curr2 = timeslots.top();
            if(curr.second >= curr2.first + duration) {
                return {curr2.first, curr2.first + duration};
            }
        }
        return {};
    }
};