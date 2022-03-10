class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        
        //Array not rotated or arraySize = 1
        if(nums[0] < nums[len-1] || len == 1)
            return nums[0];
        
        int left = 0;
        int right = len-1;
        int minValue = INT_MAX;
        while(left <= right)
        {
            int mid = left + (right-left)/2;
            
            //minValue = min(minValue, nums[mid]);
            if(nums[mid] > nums[mid+1])
                return nums[mid+1];
            if(nums[mid-1] > nums[mid])
                return nums[mid];
            if(nums[mid] > nums[left])
                left = mid+1;
            else
                right = mid-1;                
        }
        return -1;
    }
};