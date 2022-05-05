class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxOnes = 0;
        int onesSoFar = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] == 1)
            {
                onesSoFar++;
                maxOnes = max(maxOnes, onesSoFar);
            }
            else
                onesSoFar = 0;
        }
        return maxOnes;
    }
};