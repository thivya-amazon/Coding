class Solution {
public:
    vector<int> getMinSpan(vector<int>& nums)
    {
        //Find prev min element
        stack<int> mono;
        vector<int> leftSpan(nums.size(), 0);
        vector<int> rightSpan(nums.size(), 0);
        vector<int> minSpan(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            while(!mono.empty() && nums[mono.top()] >= nums[i])
                mono.pop();
            if(!mono.empty())
                leftSpan[i] = i - mono.top();
            else
                leftSpan[i] = i+1; 
            mono.push(i);
        }
        while(!mono.empty())
            mono.pop();
        //Find next min element
        for(int i = nums.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && nums[mono.top()] > nums[i])
                mono.pop();
            if(!mono.empty())
                rightSpan[i] = mono.top() - i;
            else
                rightSpan[i] = nums.size() - i; 
            mono.push(i);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            minSpan[i] = (leftSpan[i]) * rightSpan[i];
        }
        return minSpan;
    }
   vector<int> getMaxSpan(vector<int>& nums)
    {
        //Find prev max element
        stack<int> mono;
        vector<int> leftSpan(nums.size(), 0);
        vector<int> rightSpan(nums.size(), 0);
        vector<int> maxSpan(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++)
        {
            while(!mono.empty() && nums[mono.top()] <= nums[i])
                mono.pop();
            if(!mono.empty())
                leftSpan[i] = i - mono.top();
            else
                leftSpan[i] = i+1; 
            mono.push(i);
        }
        while(!mono.empty())
            mono.pop();
        //Find next max element
        for(int i = nums.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && nums[mono.top()] < nums[i])
                mono.pop();
            if(!mono.empty())
                rightSpan[i] = mono.top() - i;
            else
                rightSpan[i] = nums.size() - i; 
            mono.push(i);
        }
        for(int i = 0; i < nums.size(); i++)
        {
            maxSpan[i] = (leftSpan[i]) * rightSpan[i];
        }
        return maxSpan;
        
    }
    long long subArrayRanges(vector<int>& nums) {
        vector<int> minSpan(nums.size(), 0);
        vector<int> maxSpan(nums.size(), 0);
        long long result = 0;
        minSpan = getMinSpan(nums);
        maxSpan = getMaxSpan(nums);
        for(int i = 0; i < nums.size(); i++)
        {
            result += (((long long)maxSpan[i] * nums[i]) - ((long long)minSpan[i] * nums[i]));
        }
        return result;
    }
};