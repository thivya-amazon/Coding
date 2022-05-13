class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>> result;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        result.push_back(intervals[0]);
        for(int i = 1; i < n; i++)
        {
            int prev = result.size()-1;
            //Requires a merge
            if(result[prev][1] >= intervals[i][0])
                result[prev][1] = max(intervals[i][1], result[prev][1]);
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};