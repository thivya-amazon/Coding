class Solution {
public:
    int partition(vector<int>& nums, int start, int end)
    {
        int randIdx = start + rand() % (end - start+1);
        swap(nums[randIdx], nums[start]);
        
        int pivot = nums[start];
        int smaller = start;
        for(int bigger = start+1; bigger <= end; bigger++)
        {
            if(nums[bigger] < pivot)
            {
                smaller++;
                swap(nums[bigger], nums[smaller]);
            }
        }
        swap(nums[start], nums[smaller]);
        return smaller;
    }
    int quickSelect(vector<int>& nums, int start, int end, int k)
    {
        int pivotIdx = 0;
        while(1)
        {            
            pivotIdx = partition(nums, start, end);
            if(pivotIdx == k)
                break;
            if(pivotIdx < k)
                start = pivotIdx + 1;
            else
                end = pivotIdx - 1;
        }
        return nums[pivotIdx];
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n-1, n-k);
    }
};