class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<int> mono;
        
        vector<int> result(heights.size());
        for(int i = heights.size()-1; i >= 0; i--)
        {
            int count = 0;
            while(!mono.empty() && mono.top() < heights[i])
            {
                count++;
                mono.pop();
            }
            if(!mono.empty())
                count++;
            result[i] = count;
            mono.push(heights[i]);
        }
        return result;
    }
};