class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i)
            {
                int destIndex = nums[i];
                if(nums[i] != nums[destIndex])
                    swap(nums[i], nums[destIndex]);
                else
                    break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i)
                return nums[i];
        }
        return -1;
    }
};