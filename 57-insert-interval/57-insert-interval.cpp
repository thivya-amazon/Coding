class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        int insertIndex = 0;
        for(int i = 0; i < intervals.size(); i++)
        {
            //New interval is after intervals[i]
            if(newInterval[0]  > intervals[i][1] )
            {
                result.push_back(intervals[i]);
            }
            //New interval is before intervals[i]
            else if(newInterval[1] < intervals[i][0])
            {
                result.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if(newInterval[0] <= intervals[i][1] || newInterval[1] >= intervals[i][0])
            {
                newInterval[0] = min(intervals[i][0], newInterval[0]);
                newInterval[1] = max(intervals[i][1], newInterval[1]);
            }
        }
        result.push_back(newInterval);
        return result;
    }
};