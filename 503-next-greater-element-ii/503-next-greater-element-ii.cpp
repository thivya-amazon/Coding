class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Find all the next greater elements for each element
        stack<int> mono;
        vector<int> result(nums.size(), -1);
        //Initialize the stack
        for(int i = nums.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && mono.top() <= nums[i])
                mono.pop();
            mono.push(nums[i]);
        }
        for(int i = nums.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && mono.top() <= nums[i])
                mono.pop();
            if(!mono.empty())
                result[i] = mono.top();
            mono.push(nums[i]);
        }
        return result;
    }
};