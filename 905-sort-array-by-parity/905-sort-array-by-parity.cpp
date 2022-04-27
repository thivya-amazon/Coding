class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int evenPtr = -1;
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2 == 0)
            {
                evenPtr++;
                swap(nums[i], nums[evenPtr]);
            }
        }
        return nums;
    }
};