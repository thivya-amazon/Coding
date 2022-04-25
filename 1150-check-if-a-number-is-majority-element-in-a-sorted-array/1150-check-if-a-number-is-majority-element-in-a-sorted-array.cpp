class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int n = nums.size();
        if(n == 0)
            return false;
        int start = 0;
        int end = nums.size() - 1;
        
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        if(start + n/2 > n-1)
            return false;
        if(nums[start] != target)
            return false;
        if(nums[start + n/2] != target)
            return false;
        
        return true;
    }
};