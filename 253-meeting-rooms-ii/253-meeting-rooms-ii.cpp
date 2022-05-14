class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        unsigned long minRooms = 0;
        int nextStart = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            if(i == intervals.size()-1)
                nextStart = INT_MAX;
            else
                nextStart = intervals[i+1][0];
            
            //Push the end time of every interval into min heap
            pq.push(intervals[i][1]);
            minRooms = max(minRooms, pq.size());
            
            if(pq.top() <= nextStart)
                pq.pop();
        }
        return minRooms;
    }
};