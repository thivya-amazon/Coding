class Solution {
public:
    //4 zones : peak, valley, ascending, descending
    int findPeakElement(vector<int>& nums) {
        //Edge cases
        if(nums.size() == 1)
            return 0;
        if(nums[0] > nums[1])
            return 0;
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;
        
        int start = 1;
        int end = nums.size()-2;
        while(start <= end)
        {
            int mid = start + (end-start)/2;
            //Peak?
            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
                return mid;
            //Valley - Move towards the right
            if(nums[mid] < nums[mid+1] && nums[mid] < nums[mid-1])
                start = mid + 1;
            //Ascending - Move towards the right
            else if(nums[mid] > nums[mid-1])
                start = mid + 1;
            //Descending - Move towards the left
            else
                end = mid - 1;        
        }
        return -1;
    }
};