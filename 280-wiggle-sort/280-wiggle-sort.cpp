class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        /*
        Dec & Con:
        For any arbitrary index from 1 to n-1
            1. IF index is odd, nums[i-1] > nums[i]
            2. If index is even, nums[i-1] < nums[i]
                swap nums[i] & nums[i-1]
        */
        for(int i = 1; i < nums.size(); i++)
        {
            if((i % 2 && nums[i-1] > nums[i]) || (i%2 == 0 && nums[i-1] < nums[i]))
                swap(nums[i], nums[i-1]);                
        }
        return;
    }
};