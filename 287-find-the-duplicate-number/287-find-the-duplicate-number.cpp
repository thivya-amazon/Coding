class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            while(nums[i] != i+1)
            {
                int destIndex = nums[i]-1;
                if(nums[i] != nums[destIndex])
                    swap(nums[i], nums[destIndex]);
                else
                    break;
            }
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i+1)
                return nums[i];
        }
        return -1;
    }
};