class Solution {
public:

    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //vector of <starttime, passengers> and <endtime, -passengers>
        vector<pair<int,int>> tracker;
        for(int i = 0; i < trips.size(); i++)
        {
            tracker.push_back({trips[i][1], trips[i][0]});
            tracker.push_back({trips[i][2], -trips[i][0]});
        }
        sort(tracker.begin(), tracker.end());
        int passengers = 0;
        for(int i = 0; i < tracker.size(); i++)
        {
            passengers += tracker[i].second;
            if(passengers > capacity)
                return false;
        }
        return true;
    }
};