class Solution {
public:
    int binarySearch(vector<int>& nums, int start, int end, int target)
    {
        while(start <= end)
        {
            int mid = start + (end - start)/2;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] < target)
                start = mid+1;
            else
                end = mid-1;
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size()-1, target);
    }
};