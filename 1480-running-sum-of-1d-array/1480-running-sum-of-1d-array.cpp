class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int prefixSum = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            prefixSum += nums[i];
            result[i] = result[i] + prefixSum;
        }
        return result;
    }
};