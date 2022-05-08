class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        stack<int> s;
        vector<int> result;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!s.empty() && heights[i] >= heights[s.top()])
                s.pop();
            s.push(i);
        }
        while(!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        reverse(result.begin(), result.end());
        return result;    
        
    }
};