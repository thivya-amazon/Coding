class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> mono;
        vector<int> rightSpan(heights.size(), 0);
        vector<int> leftSpan(heights.size(), 0);
        int localArea = 0;
        int globalArea = 0;
        //Find the next smallest element and calculate the rightSpan for every index i
        for(int i = heights.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && heights[mono.top()] >= heights[i])
                mono.pop();
            if(!mono.empty())
                rightSpan[i] = mono.top() - i;
            else
                rightSpan[i] = heights.size() - i;  //If the stack is empty, all the indices from end to i are smaller
            mono.push(i);
        }
        while(!mono.empty())
            mono.pop();
        //Find the previous smallest element and calculate the leftSpan for every index i
        for(int i = 0; i < heights.size(); i++)
        {
            while(!mono.empty() && heights[mono.top()] >= heights[i])
                mono.pop();
            if(!mono.empty())
                leftSpan[i] = i - mono.top();
            else
                leftSpan[i] = i + 1;       //If the stack is empty, all the indices from left to i are greate
            mono.push(i);
        }
        
        //Width = leftSpan + rightSpan - 1
        for(int i = 0; i < heights.size(); i++)
        {
            localArea = (rightSpan[i] + leftSpan[i] - 1) * heights[i];
            globalArea = max(localArea, globalArea);
        }
        return globalArea;
    }
};