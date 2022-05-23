class Solution {
public:
    void reverse(vector<int>& nums, int start, int end)
    {
        while(start < end)
        {
            swap(nums[start++], nums[end--]);
        }
    }
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();
        //reverse the entire array
        reverse(nums, 0, nums.size()-1);
        //reverse k elements from the start
        reverse(nums, 0, k-1);
        //reverse n-k elements from k
        reverse(nums, k, nums.size()-1);
            
    }
};