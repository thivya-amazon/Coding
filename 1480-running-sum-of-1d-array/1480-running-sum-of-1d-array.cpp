class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result;
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            result.push_back(prefixSum);
        }
        return result;
    }
};