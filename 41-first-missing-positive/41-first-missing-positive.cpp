class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i+1)
            {
                unsigned int destIdx = (unsigned int)nums[i] - 1;
                if(destIdx >= 0 && destIdx < n && nums[i] != nums[destIdx])
                    swap(nums[i], nums[destIdx]);
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