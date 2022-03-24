class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        //Find all the next greater elements for each elemet in nums2 and store it in a map
        unordered_map<int, int> umap;
        stack<int> mono;
        vector<int> result(nums.size(), -1);
        for(int i = 2 * nums.size()-1; i >= 0; i--)
        {
            while(!mono.empty() && mono.top() <= nums[i % nums.size()])
                mono.pop();
            if(!mono.empty())
                result[i % nums.size()] = mono.top();
            mono.push(nums[i % nums.size()]);
        }

        return result;
    }
};