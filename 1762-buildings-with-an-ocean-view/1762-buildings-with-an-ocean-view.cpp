class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        int maxHeight = INT_MIN;
        for(int i = heights.size()-1; i >= 0; i--)
        {
            if(heights[i] > maxHeight)
            {
                result.push_back(i);
                maxHeight = heights[i];
            }                           
        }
  
        reverse(result.begin(), result.end());
        return result;
    }
};