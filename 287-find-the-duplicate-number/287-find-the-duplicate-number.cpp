class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i+1)
            {
                int destIdx = nums[i] - 1;
                if(destIdx < nums.size() && nums[i] != nums[destIdx])
                    swap(nums[i], nums[destIdx]);
                else
                    break;
            }
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != i+1)
                return nums[i];
        }
        return -1;
    }
};