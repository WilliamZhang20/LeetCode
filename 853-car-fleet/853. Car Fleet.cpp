class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // sort positions/speed
        int n = position.size();
        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++) {
            vec.emplace_back(position[i], speed[i]);
        }
        sort(vec.begin(), vec.end());
        stack<double> arrivals;
        // stack of fleets to be stored in final
        // push first car onto it?
        arrivals.push((target - vec[0].first)/(1.0 * vec[0].second));
        // for each following car, check if earlier, if so, pop current + push later
        for(int i=1; i<n; i++) {
            double time = (target - vec[i].first) / (1.0 * vec[i].second);
            while(!arrivals.empty() && arrivals.top() <= time)
                arrivals.pop();
            arrivals.push(time);
        }
        return arrivals.size();
    }
};