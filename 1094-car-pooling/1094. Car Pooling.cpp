class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // destination, # of passengers
        int n = trips.size();
        sort(trips.begin(), trips.end(), [](auto& lhs, auto& rhs) {
            if(lhs[1]<rhs[1] || (lhs[1]==rhs[1] && lhs[2]<rhs[2]))
                return true;
            return false;
        });
        int curr = 0; // number of current passengers
        for(int i=0; i<n; i++) {
            // drop off everybody
            while(!pq.empty() && pq.top().first <= trips[i][1]) {
                curr -= pq.top().second;
                pq.pop();
            }

            // pick up everybody at this spot
            curr += trips[i][0];
            pq.emplace(trips[i][2], trips[i][0]);
            
            // if wrong, return false
            if(curr > capacity) {
                return false;
            }
        }
        return true;
    }
};