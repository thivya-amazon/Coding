class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum = 0;
        int leftSum = 0;
        for(auto n : nums)
            totalSum += n;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(totalSum - leftSum - nums[i] == leftSum)
                return i;
            leftSum += nums[i];
        }
       return -1; 
    }
};