class Solution {
public:
    int findMin(vector<int>& nums) {
        int n  = nums.size();
        int start = 0;
        int end = n-1;
        int i;
        for(i = 0; i < n; i++)
        {
            if(nums[i] != nums[n-1])
            {
                start = i;
                break;
            }
        }
        //This indicates the entire array has the same value
        if(i == n-1)
            return nums[0];
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] > nums[n-1])
                start = mid + 1;
            else
                end = mid - 1;
        }
        return nums[start];
    }
};