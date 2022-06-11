class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i)
            {
                int dstIdx = nums[i];
                if(dstIdx < nums.size())
                    swap(nums[i], nums[nums[i]]);
                else
                    break;
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i)
                return i;
        }
        return nums.size();
    }
};