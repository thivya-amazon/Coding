class Solution {
public:
    int maximumDifference(vector<int>& nums) {

        int maxDiff = 0;
        int minVal = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            maxDiff = max(maxDiff, nums[i] - minVal);
            minVal = min(minVal, nums[i]);
        }
        return maxDiff == 0 ? -1 : maxDiff;
    }
};