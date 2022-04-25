class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1,-1};
        if(nums.size() == 0)
            return result;
        int start = 0;
        int end = nums.size()-1;
        int leftmost = -1;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        //At this point start should point to the leftmost index of target, if available
        if(start == nums.size() || nums[start] != target)
            return result;
        leftmost = start;
        end = nums.size()-1;
        //Secondary binary search to find the rightmost index
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            if(nums[mid] <= target)
                start = mid+1;
            else
                end = mid-1;
        }
        result[0] = leftmost;
        result[1] = end;
        return result;
    }
};