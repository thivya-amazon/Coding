class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            while(nums[i] != i+1)
            {
               unsigned long destIndex = (unsigned long)nums[i] - 1;
                if(destIndex >= 0 && destIndex < n && nums[i] != nums[destIndex])
                    swap(nums[i], nums[destIndex]);
                else
                    break;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != i+1)
                return i+1;
        }
        return n+1;
    }
};