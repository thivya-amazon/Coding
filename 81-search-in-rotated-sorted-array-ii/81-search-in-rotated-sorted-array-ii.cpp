class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
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
        //The entire array has the same value
        if(i == n-1)
        {
            if(nums[i] != target)
                return false;
            else
                return true;
        }
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] == target)
                return true;
            if(nums[mid] > nums[n-1] && target <= nums[n-1])
                start = mid + 1;
            else if(nums[mid] <= nums[n-1] && target > nums[n-1])
                end = mid - 1;
            else if(nums[mid] < target)
                start = mid + 1;
            else
                end = mid - 1;
        }
        return false;
    }
};