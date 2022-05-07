class Solution {
public:
    void reverse(vector<int>& nums, int start)
    {
        int end = nums.size()-1;
        while(start <= end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-2;
        while(i >= 0 && nums[i] >= nums[i+1])
            i--;
        int j = nums.size()-1;
        if(i >= 0)
        {
            while(nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        reverse(nums, i+1);        
    }
};