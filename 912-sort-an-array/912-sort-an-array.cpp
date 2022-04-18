class Solution {
public:
    int getPivotIdx(vector<int>& nums, int start, int end)
    {
        srand(NULL);
        int randIdx = start + rand() % (end - start);
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
    void quickSort(vector<int>& nums, int start, int end)
    {
        if(start >= end)
            return;
        int pivotIdx = getPivotIdx(nums, start, end);
        quickSort(nums, start, pivotIdx-1);
        quickSort(nums, pivotIdx+1, end);
    }
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};